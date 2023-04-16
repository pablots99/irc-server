/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:04:56 by nlutsevi          #+#    #+#             */
/*   Updated: 2023/02/12 22:29:58 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/user.hpp"


User::User(void)
{
	_onHold = false;
	_isRegistered = false;
	_firstTime = true;
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
		_client_fd = src.getFd();
		_client_addr = new sockaddr_in(*src.getAddr());
		_client_addr_size = new socklen_t(*src.getAddrSize());
		_nickname = src.getNickname();
		_username = src.getUsername();
		_mode = src.getMode();
		_realname = src.getRealname();
	}
	return *this;
}

//std::map<int, User> 		User::usersFdMap;


const int		&User::getFd(void) const
{
	return _client_fd;
}


struct sockaddr_in*		User::getAddr(void) const
{
	return _client_addr;
}


socklen_t*				User::getAddrSize(void) const
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

const bool				&User::getOnHold(void) const
{
	return _onHold;
}

const time_t 			&User::getPingSent(void) const
{
	return _pingSent;
}

const time_t 			&User::getPingReceived(void) const
{
	return _pingReceived;
}

const bool				&User::getIsRegistered(void) const
{
	return _isRegistered;
}

const time_t 			&User::getEntersChat(void) const
{
	return _entersChat;
}

const bool				&User::getFirstTime(void) const
{
	return _firstTime;
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

void					User::setOnHold(bool onHold)
{
	_onHold = onHold;
}

void					User::setPingSent(time_t pingSent)
{
	_pingSent = pingSent;
}


void					User::setPingReceived(time_t pingReceived)
{
	_pingReceived = pingReceived;
}

void					User::setIsRegistered(bool isRegistered)
{
	_isRegistered = isRegistered;
}

void					User::setEntersChat(time_t entersChat)
{
	_entersChat = entersChat;
}

void					User::setFistTime(bool firstTime)
{
	_firstTime = firstTime;
}








