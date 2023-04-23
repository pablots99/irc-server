/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:33:31 by nlutsevi          #+#    #+#             */
/*   Updated: 2023/04/23 14:55:45 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cmd.hpp"
# include "../includes/utils.hpp"
# include "../includes/reply.hpp"
# include "../includes/cmds/userCmd.hpp"
# include <iostream>

Cmd::Cmd(std::string const& line, User* user)
//TODO: /r/n need to be managed
{
	std::vector<std::string> tmp;
	std::vector<std::string> tmp2;
	tmp = splitString(line, ':');
	if (tmp.size() == 1)
		tmp2 = splitString(line, ' ');
	else
	{
		tmp2 = splitString(tmp[0], ' ');
		tmp2.push_back(tmp[1]);
	}
	_cmdName = tmp2[0];
	for (size_t i = 1; i < tmp2.size(); i++) {
		if (tmp2[i].find('\n') != std::string::npos) {
        	std::string remaining = tmp2[i].substr(0, tmp2[i].find('\n'));
        	_cmdArgs.push_back(remaining);
        	break;
    	}
    	else {
        	_cmdArgs.push_back(tmp2[i]);
		}
	}
	_handle_commands(_cmdName, _cmdArgs, user);
}

Cmd::~Cmd(void)
{
}

Cmd::Cmd(Cmd const& src)
{
	*this = src;
}

Cmd& Cmd::operator=(Cmd const& src)
{
	if (this != &src)
	{
		_cmdName = src.getCmdName();
		_cmdArgs = src.getCmdArgs();
	}
	return *this;
}

const std::string& Cmd::getCmdName() const
{
	return _cmdName;
}

const std::vector<std::string>& Cmd::getCmdArgs() const
{
	return _cmdArgs;
}

void Cmd::_handle_commands(std::string cmdName, std::vector<std::string> cmdArgs, User* user)
{
	Reply *r = new Reply(); 
	if (cmdName == "USER")
	{
		UserCmd *u = new UserCmd();
		u->execute(cmdArgs, user, r);
		delete u;
	}
	else if (cmdName == "NICK")
	{
		nickCmd(cmdArgs, user, r);
	}
	else if (cmdName == "PASS")
	{
		//TODO: to be implemented from args received in main -> see irc subject
	}
	else if (cmdName == "QUIT")
	{
		//TODO: need to be implemented
	}
	else if (cmdName == "PONG")
	{
		PongCmd *p = new PongCmd();
		p->execute(cmdArgs, user, r);
		delete p;
	}
	//else
	//	r->notify(user->getFd(), r->Error(ERR_NOTREGISTERED, cmdName));
	delete r;

}

void		Cmd::nickCmd(std::vector<std::string> cmdArgs, User* user, Reply* reply) {
	std::string	nick;
	std::string valid_nick;
	
	if (cmdArgs.size() > 1)
		return;
	if(cmdArgs.size() < 1)
		reply->notify(user->getFd(), reply->Error(ERR_NEEDMOREPARAMS, "NICK"));
	valid_nick = getValidNickname(cmdArgs[0]);
	if (valid_nick.empty())
		reply->notify(user->getFd(), reply->Error(ERR_ERRONEUSNICKNAME, "NICK", cmdArgs[0]));
	/*
	In IRC, nicknames are case-insensitive. to avoid confusion,
	IRC servers tipcally store and display nicknames in uppercase
	characters.
	*/
	nick = toUpperCase(valid_nick);
	// Check if nickname alredy exists in the server
	if (Bbdd::nickExists(nick))
		reply->notify(user->getFd(), reply->Error(ERR_NICKNAMEINUSE, "NICK", nick));
	// Nickname change
	if (user->getIsRegistered())
		return Bbdd::updateUserNick(user, nick);
	user->setNickname(nick);
	Bbdd::addNick(nick, user->getFd());
}
