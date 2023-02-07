/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:33:31 by nlutsevi          #+#    #+#             */
/*   Updated: 2023/02/07 21:41:19 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cmd.hpp"
# include "../includes/utils.hpp"
# include "../includes/reply.hpp"
# include "../includes/userCmd.hpp"
# include <iostream>

Cmd::Cmd(std::string const& line, User* user)
//Assuming space as command deimiter and command name is first parameter.
//TODO: need to be adapted to actual RFC 1459
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
	if (cmdArgs.size() == 0)
		r->notify(user->getClientFd(), r->Error(ERR_NEEDMOREPARAMS));
	if (cmdName == "USER")
	{
		UserCmd *u = new UserCmd();
		u->execute(cmdArgs, user, r);
		delete u;
	}
	delete r;

}
