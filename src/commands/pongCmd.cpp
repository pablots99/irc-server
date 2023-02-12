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
	if (cmdArgs.size() < 2)
		reply->notify(user->getFd(), reply->Error(ERR_NEEDMOREPARAMS, "PONG"));
}