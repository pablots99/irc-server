/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:04:56 by nlutsevi          #+#    #+#             */
/*   Updated: 2023/02/04 19:23:48 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/user.hpp"

User::User(void)
{
	_client_addr = new sockaddr_in();
	_client_addr_size = new socklen_t(sizeof(_client_addr));
}


User::~User(void)
{
	delete _client_addr;
	delete _client_addr_size;
}


User::User(User const& src)
{
	*this = src;
}


User&			User::operator=(User const& src)
{
	if (this != &src)
	{
		_client_fd = src.getClientFd();
		_client_addr = new sockaddr_in(*src.getClientAddr());
		_client_addr_size = new socklen_t(*src.getClientAddrSize());
		_nickname = src.getNickname();
		_username = src.getUsername();
		_mode = src.getMode();
		_realname = src.getRealname();
	}
	return *this;
}


const int		&User::getClientFd(void) const
{
	return _client_fd;
}


struct sockaddr_in*		User::getClientAddr(void) const
{
	return _client_addr;
}


socklen_t*				User::getClientAddrSize(void) const
{
	return _client_addr_size;
}


const std::string		&User::getNickname(void) const
{
	return _nickname;
}


const std::string		&User::getUsername(void) const
{
	return _username;
}


const std::string		&User::getMode(void) const
{
	return _mode;
}


const std::string		&User::getRealname(void) const
{
	return _realname;
}


void					User::setClientFd(int client_fd)
{
	_client_fd = client_fd;
}


void					User::setClientAddr(struct sockaddr_in* client_addr)
{
	_client_addr = client_addr;
}


void					User::setClientAddrSize(socklen_t* client_addr_size)
{
	_client_addr_size = client_addr_size;
}


void					User::setNickname(std::string nickname)
{
	_nickname = nickname;
}


void					User::setUsername(std::string username)
{
	_username = username;
}


void					User::setMode(std::string mode)
{
	_mode = mode;
}


void					User::setRealname(std::string realname)
{
	_realname = realname;
}








