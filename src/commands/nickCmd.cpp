/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nickCmd.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 20:27:06 by nlutsevi          #+#    #+#             */
/*   Updated: 2023/02/12 21:21:43 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cmds/nickCmd.hpp"

nickCmd::nickCmd(void) {
}

nickCmd::~nickCmd(void) {
}

nickCmd::nickCmd(nickCmd const& src) {
	*this = src;
}

nickCmd&		nickCmd::operator=(nickCmd const& src) {
	if (this != &src) {
	}
	return *this;
}

void			nickCmd::execute(std::vector<std::string> cmdArgs, User* user, Reply* reply) {
	if(cmdArgs.size() < 1)
		reply->notify(user->getFd(), reply->Error(ERR_NEEDMOREPARAMS, "NICK"));
	user->setNickname(cmdArgs[0]);
	if (user->getUsername() != "")
		user->setIsRegistered(true);
}