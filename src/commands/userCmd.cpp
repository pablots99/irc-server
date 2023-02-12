/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   userCmd.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:36:10 by nlutsevi          #+#    #+#             */
/*   Updated: 2023/02/12 20:10:28 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cmds/userCmd.hpp"
# include "../includes/reply.hpp"

UserCmd::UserCmd() {}

UserCmd::~UserCmd() {}

UserCmd::UserCmd(UserCmd const& src) {
	*this = src;
}

UserCmd& UserCmd::operator=(UserCmd const& src) {
	(void)src;
	return *this;
}

void		UserCmd::execute(std::vector<std::string> cmdArgs, User* user, Reply* reply, bool first_time) 
{
	if (cmdArgs.size() < 4)
		reply->notify(user->getFd(), reply->Error(ERR_NEEDMOREPARAMS, "USER"));
	if (!first_time)
		reply->notify(user->getFd(), reply->Error(ERR_ALREADYREGISTRED, "USER"));
	//TODO: Parse: each arg is in correct format
	user->setUsername(cmdArgs[0]);
	user->setMode(cmdArgs[1]);
	//user->setUnused(cmdArgs[2]);
	user->setRealname(cmdArgs[3]);
	//TODO: once NICK get nick from fd is prepared, check if nick exists and send first PING
}