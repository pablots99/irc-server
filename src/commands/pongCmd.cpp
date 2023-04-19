/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pongCmd.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:47:27 by nlutsevi          #+#    #+#             */
/*   Updated: 2023/02/12 19:56:05 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cmds/pongCmd.hpp"

PongCmd::PongCmd(void) {
}

PongCmd::~PongCmd(void) {
}

PongCmd::PongCmd(PongCmd const& src) {
	*this = src;
}

PongCmd&		PongCmd::operator=(PongCmd const& src) {
	if (this != &src) {
	}
	return *this;
}

void			PongCmd::execute(std::vector<std::string> cmdArgs, User* user, Reply* reply) {
	//check if str sent is the same as the one received
	//reset timer
	std::string	ping_msg;
	std::string	line;
	ping_msg = user->getPingMsg();
	if (cmdArgs.size() < 1)
		reply->notify(user->getFd(), reply->Error(ERR_NEEDMOREPARAMS, "PONG"));
	//pong receved without previous ping
	if (ping_msg.empty())
		return;
	std::istringstream iss(cmdArgs[0]);
	std::getline(iss, line, '\n');
	if (ping_msg == line || (":" + ping_msg) == line) {
		user->setOnHold(false);
		user->setPingMsg("");
		//user->setPingSent(NULL);
		if (!user->getIsRegistered())
			user->setIsRegistered(true);
	}
	else if (!ping_msg.empty() && ping_msg != cmdArgs[0] && !user->getIsRegistered())
		throw std::runtime_error(CloseError(user->getFd(), "Incorrect ping reply for registration"));
}