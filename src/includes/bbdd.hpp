/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bbdd.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:01:19 by nlutsevi          #+#    #+#             */
/*   Updated: 2023/07/09 11:40:05 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BBDD_HPP
# define BBDD_HPP

# include <map>
# include <string>
# include "user.hpp"
# include "channel.hpp"

class User;

class Channel;

class Bbdd {
	public:
		Bbdd();
		~Bbdd();
		Bbdd(Bbdd const& src);
		Bbdd& operator=(Bbdd const& src);

	private:
		std::map<int, User*>			_usersMap;
		std::map<std::string, int> 		_nicksMap;
		std::map<std::string, Channel*>	_channelMap;
		void							addUser(User* user);
		void							removeUser(User* user);
		User*							getUser(int fd);
		void							addNick(std::string &nick, int fd);
		void							removeNick(const std::string &nick);
		bool							nickExists(std::string &nick);
		void							updateUserNick(User *user, std::string &new_nick);
		bool							doesChannelExist(std::string channelName);
		void							createNewChannel(std::string channelName, User *user);
};


# endif