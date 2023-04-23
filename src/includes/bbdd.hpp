/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bbdd.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:01:19 by nlutsevi          #+#    #+#             */
/*   Updated: 2023/04/23 14:05:51 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BBDD_HPP
# define BBDD_HPP

# include <map>
# include <string>
# include "user.hpp"

class User;

class Bbdd {
	public:
		Bbdd();
		~Bbdd();
		Bbdd(Bbdd const& src);
		Bbdd& operator=(Bbdd const& src);

		std::map<int, User*>		_usersMap;
		std::map<std::string, int> 	_nicksMap;
		void					addUser(User* user);
		void					removeUser(User* user);
		User*					getUser(int fd);
		void					addNick(std::string &nick, int fd);
		void					removeNick(const std::string &nick);
		bool					nickExists(std::string &nick);
		void					updateUserNick(User *user, std::string &new_nick);
};


# endif