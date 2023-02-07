/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reply.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 19:40:36 by nlutsevi          #+#    #+#             */
/*   Updated: 2023/02/07 20:50:09 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/reply.hpp"
#include "../includes/server.hpp"

Reply::Reply(void) {}

Reply::~Reply(void) {}

Reply::Reply(Reply const& src)
{
	*this = src;
}

Reply& Reply::operator=(Reply const& src)
{
	(void)src;
	return *this;
}

std::string		Reply::Error(std::string errCode)
{
	std::string		err;

	if (errCode == ERR_NEEDMOREPARAMS)
		err = "461 :Not enough parameters";
	return err;
}

void			Reply::notify(int client_fd, const std::string &msg)
{
	std::string		msg_br = msg + "\r\n";
	if (send(client_fd, msg_br.c_str(), msg_br.size(), 0) == -1)
		throw std::runtime_error("Error sending message to client");
}