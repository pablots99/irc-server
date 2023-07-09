/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bbdd.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:05:25 by nlutsevi          #+#    #+#             */
/*   Updated: 2023/07/09 11:37:03 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/bbdd.hpp"


Bbdd::Bbdd(void) {
}

Bbdd::~Bbdd(void) {
}

Bbdd::Bbdd(Bbdd const& src) {
	*this = src;
}

Bbdd& Bbdd::operator=(Bbdd const& src) {
	if (this != &src) {
		_usersMap = src._usersMap;
	}
	return *this;
}

void	Bbdd::addUser(User* user) {
	_usersMap.insert(std::pair<int, User*>(user->getFd(), user));
}

void	Bbdd::removeUser(User* user) {
	_usersMap.erase(user->getFd());
}

User*	Bbdd::getUser(int fd) {
	//not using _usersMap[fd] here because it will create a new element if a user doesn't exist
	std::map<int, User*>::iterator it;
	it = _usersMap.find(fd);
	if (it != _usersMap.end())
		return it->second;
	return NULL;
}

void	Bbdd::addNick(std::string &nick, int fd) {
	_nicksMap.insert(std::pair<std::string, int>(nick, fd));
}

void	Bbdd::removeNick(const std::string &nick) {
	_nicksMap.erase(nick);
}

bool	Bbdd::nickExists(std::string &nick) {
	return _nicksMap.count(nick);
}

void	Bbdd::updateUserNick(User *user, std::string &new_nick) {
	removeNick(user->getNickname());
	addNick(new_nick, user->getFd());
	user->setNickname(new_nick);
}

bool	Bbdd::doesChannelExist(std::string channelName) {
	return std::find(this->_channelMap.begin(), this->_channelMap.end(), channelName) != this->_channelMap.end();
}

void	Bbdd::createNewChannel(std::string channelName, User *user) {
	(void)channelName;
	(void)user;
	//TODO:: Create new Channel
}