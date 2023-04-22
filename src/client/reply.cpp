/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reply.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 19:40:36 by nlutsevi          #+#    #+#             */
/*   Updated: 2023/02/12 22:04:13 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/reply.hpp"

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

std::string		Reply::Error(std::string errCode, std::string cmd)
{
	std::string		err;

	err = "irc: " + errCode + " * " + cmd;;

	if (errCode == ERR_NEEDMOREPARAMS)
		err = " :Not enough parameters";
	if (errCode == ERR_ALREADYREGISTERED)
		err = " :You may not reregister";
	if (errCode == ERR_NOTREGISTERED)
		err = " :You have not registered";
	return err + "\r\n";
}

void			Reply::notify(int client_fd, const std::string &msg)
{
	std::string		msg_br = msg + "\r\n";
	if (send(client_fd, msg_br.c_str(), msg_br.size(), 0) == -1)
		throw std::runtime_error("Error sending message to client");
}


std::string 				CloseError(int client_fd, std::string error)
{
	std::string		err;

	//TODO add host
	err = "ERROR :Closing link: [" + error + "]\r\n";
	if (send(client_fd, err.c_str(), err.size(), 0) == -1)
		throw std::runtime_error("Error sending message to client");
	return err;
}