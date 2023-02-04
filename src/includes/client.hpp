/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:22:34 by ptorres           #+#    #+#             */
/*   Updated: 2023/02/04 18:00:38 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
# define CLIENT_HPP

# include <iostream>

class Client { 
    private:
	 	std::string _nickname; // max 9 characters
		std::string _username;
		std::string	_mode;
		std::string _realname;
		// std::string _hostname;
        // std::string _servername;
		// std::string _serverinfo;
		// std::string _awaymsg;
		// std::string _password;
		// std::string _ip;
		// std::string _port;
        // std::map<channel> _channels;
	
	public:
    	Client();
        ~Client();
		Client(Client const& src);
		Client& operator=(Client const& src);

		const std::string 				&getNickname() const;
		const std::string 				&getUsername() const;
		const std::string 				&getMode() const;
		const std::string 				&getRealname() const;
		// const std::string 				&getHostname() const;
		// const std::string 				&getServername() const;
		// const std::string 				&getServerinfo() const;
		// const std::string 				&getAwaymsg() const;
		// const std::string 				&getPassword() const;
		// const std::string 				&getIp() const;
		// const std::string 				&getPort() const;
		// const std::map<channel> 		&getChannels() const;

		void setNickname(std::string const& nickname);
		void setUsername(std::string const& username);
		void setMode(std::string const& mode);
		void setRealname(std::string const& realname);
		// void setHostname(std::string const& hostname);
		// void setServername(std::string const& servername);
		// void setServerinfo(std::string const& serverinfo);
		// void setAwaymsg(std::string const& awaymsg);
		// void setPassword(std::string const& password);
		// void setIp(std::string const& ip);
		// void setPort(std::string const& port);
		// void setChannels(std::map<channel> const& channels);
    
};


#endif