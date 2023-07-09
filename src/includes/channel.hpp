/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 10:53:57 by nlutsevi          #+#    #+#             */
/*   Updated: 2023/07/09 11:15:00 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANNEL_HPP
# define CHANNEL_HPP
# include <list>
# include "user.hpp"

class User;

class Channel {
	public:
		Channel(std::string channelName, User* user);
		~Channel();
		Channel(Channel const& src);
		Channel& operator=(Channel const& src);
	private:
		std::string					_channelName;
		std::list<std::string>		_channelNicknames;
		std::string					getChannelName(void) const;
		std::list<std::string>		getChannelNicknames(void) const;
		void						setChannelName(std::string channelName);
		
};


#endif