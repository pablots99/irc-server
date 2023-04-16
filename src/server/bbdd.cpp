/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bbdd.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:05:25 by nlutsevi          #+#    #+#             */
/*   Updated: 2023/02/12 21:36:43 by nlutsevi         ###   ########.fr       */
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
