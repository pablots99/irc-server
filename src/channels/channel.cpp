/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 10:59:59 by nlutsevi          #+#    #+#             */
/*   Updated: 2023/07/09 11:19:14 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/channel.hpp"

Channel::Channel(std::string channelName, User* user) {
	_channelName = channelName;
	//Add user to UsersList
	_channelNicknames.push_back(user->getNickname());
	//TODO: Add a mode
}

Channel::~Channel(void) {};


Channel::Channel(Channel const& src)
{
	*this = src;
}

Channel& Channel::operator=(Channel const& src)
{
	if (this != &src)
	{
		_channelName = src.getChannelName();
		_channelNicknames = src.getChannelNicknames();
	}
	return *this;
}

std::string				Channel::getChannelName(void) const {
	return this->_channelName;
}

std::list<std::string>	Channel::getChannelNicknames(void) const {
	return this->_channelNicknames;
}

void					Channel::setChannelName(std::string channeName) {
	this->_channelName = channeName;
}
