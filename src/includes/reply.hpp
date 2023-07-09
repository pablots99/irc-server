/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reply.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 19:34:27 by nlutsevi          #+#    #+#             */
/*   Updated: 2023/07/09 10:36:41 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLY_HPP
# define REPLY_HPP

# define ERR_NEEDMOREPARAMS "461" // Not enough parameters
# define ERR_ALREADYREGISTERED "462" //  You may not reregister
# define ERR_NOTREGISTERED "451" // You have not registered
# define ERR_NEEDPONG "513" // Pong on registration not correct
# define ERR_ERRONEUSNICKNAME "432" // Erroneus nickname
# define ERR_NICKNAMEINUSE "433" // Nickname is already in use
# define ERR_BADCHANMASK "476" // Bad Channel Mask

# include <iostream>
# include "Server.hpp"

class Reply
{
	public:
		Reply(void);
		~Reply(void);
		Reply(Reply const& src);
		Reply& operator=(Reply const& src);

		static std::string		Error(std::string errCode, std::string cmd, std::string nickname="");
		void				    notify(int client_fd, const std::string &msg);

};

std::string 				CloseError(int client_fd, std::string error);

#endif