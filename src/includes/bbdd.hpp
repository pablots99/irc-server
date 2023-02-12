/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bbdd.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:01:19 by nlutsevi          #+#    #+#             */
/*   Updated: 2023/02/12 21:58:00 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BBDD_HPP
# define BBDD_HPP

# include <map>
# include "user.hpp"

class User;

class Bbdd {
	public:
		Bbdd();
		~Bbdd();
		Bbdd(Bbdd const& src);
		Bbdd& operator=(Bbdd const& src);

		std::map<int, User*>		_usersMap;
		void					addUser(User* user);
		void					removeUser(User* user);
		User*					getUser(int fd);
		
};


# endif