/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:33:31 by nlutsevi          #+#    #+#             */
/*   Updated: 2023/02/04 19:48:49 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cmd.hpp"
# include "../includes/utils.hpp"
# include "../includes/reply.hpp"
# include <iostream>

Cmd::Cmd(std::string const& line, User* user)
//Assuming space as command deimiter and command name is first parameter.
//TODO: need to be adapted to actual RFC 1459
{
	std::vector<std::string> tmp = splitString(line, ' ');
	_cmdName = tmp[0];
	for (size_t i = 1; i < tmp.size(); i++)
		_cmdArgs.push_back(tmp[i]);
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
	if (cmdName == "USER")
	{
		//TODO: User Class needs to be created to handle USER command, meanwhile:	
		if (cmdArgs.size() < 4)
			throw std::runtime_error(Error(ERR_NEEDMOREPARAMS));
		//TODO: Parse: each arg is in correct format
		user->setUsername(cmdArgs[0]);
		user->setMode(cmdArgs[1]);
		//user->setUnused(cmdArgs[2]);
		user->setRealname(cmdArgs[3]);
	}

}
