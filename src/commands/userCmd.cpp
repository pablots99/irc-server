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

UserCmd::UserCmd() {}

UserCmd::~UserCmd() {}

UserCmd::UserCmd(UserCmd const& src) {
	*this = src;
}

UserCmd& UserCmd::operator=(UserCmd const& src) {
	(void)src;
	return *this;
}

void		UserCmd::execute(std::vector<std::string> cmdArgs, User* user, Reply* reply) 
{
	if (cmdArgs.size() < 4)
		reply->notify(user->getFd(), reply->Error(ERR_NEEDMOREPARAMS, "USER"));
	if (user->getIsRegistered())
		reply->notify(user->getFd(), reply->Error(ERR_ALREADYREGISTERED, "USER"));
	user->setUsername(cmdArgs[0]);
	user->setRealname(cmdArgs[3]);
}