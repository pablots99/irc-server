/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:33:31 by nlutsevi          #+#    #+#             */
/*   Updated: 2023/02/12 20:08:44 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cmd.hpp"
# include "../includes/utils.hpp"
# include "../includes/reply.hpp"
# include "../includes/cmds/userCmd.hpp"
# include <iostream>

Cmd::Cmd(std::string const& line, User* user, bool first_time)
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
	for (size_t i = 1; i < tmp2.size(); i++)
		_cmdArgs.push_back(tmp2[i]);
	_handle_commands(_cmdName, _cmdArgs, user, first_time);
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

void Cmd::_handle_commands(std::string cmdName, std::vector<std::string> cmdArgs, User* user, bool first_time)
{
	Reply *r = new Reply(); 
	if (cmdName == "USER")
	{
		UserCmd *u = new UserCmd();
		u->execute(cmdArgs, user, r, first_time);
		delete u;
	}
	else if (cmdName == "NICK")
	{
		//todo: to be configured by Pablo P
	}
	else if (cmdName == "PASS")
	{
		//TODO: to be implemented from args received in main -> see irc subject
	}
	else if (cmdName == "QUIT")
	{
		//TODO: need to be implemented
	}
	else
		r->notify(user->getFd(), r->Error(ERR_NOTREGISTERED, cmdName));
	delete r;

}
