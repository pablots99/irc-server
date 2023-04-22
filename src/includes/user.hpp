/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:22:58 by nlutsevi          #+#    #+#             */
/*   Updated: 2023/02/12 22:26:38 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef USER_HPP
# define USER_HPP

# include <iostream>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>

class User { 
    private:
		int 					_client_fd;
		struct sockaddr_in* 	_client_addr;
		socklen_t* 				_client_addr_size;
	 	std::string _nickname; // max 9 characters
		std::string _username;
		std::string	_mode;
		std::string _realname;
		std::string _pingMsg;
		bool 					_onHold;
		time_t					_pingSent;
		time_t					_pingReceived;
		bool					_isRegistered;
		time_t					_entersChat;
		bool					_firstTime;
		// std::string _hostname;
        // std::string _servername;
		// std::string _serverinfo;
		// std::string _awaymsg;
		// std::string _password;
		// std::string _ip;
		// std::string _port;
        // std::map<channel> _channels;
	
	public:
    	User();
        ~User();
		User(User const& src);
		User& operator=(User const& src);
		//std::map<int, User> 			usersFdMap;

		const int 						&getFd() const;
		struct sockaddr_in* 			getAddr() const;
		socklen_t* 						getAddrSize() const;
		const std::string 				&getNickname() const;
		const std::string 				&getUsername() const;
		const std::string 				&getMode() const;
		const std::string 				&getRealname() const;
		const std::string				&getPingMsg() const;
		const bool 						&getOnHold() const;
		const time_t 					&getPingSent() const;
		const time_t 					&getPingReceived() const;
		const bool 						&getIsRegistered() const;
		const time_t 					&getEntersChat() const;
		const bool						&getFirstTime() const;
		// const std::string 				&getHostname() const;
		// const std::string 				&getServername() const;
		// const std::string 				&getServerinfo() const;
		// const std::string 				&getAwaymsg() const;
		// const std::string 				&getPassword() const;
		// const std::string 				&getIp() const;
		// const std::string 				&getPort() const;
		// const std::map<channel> 		&getChannels() const;

		void setClientFd(int client_fd);
		void setClientAddr(sockaddr_in* client_addr);
		void setClientAddrSize(socklen_t* client_addr_size);
		void setNickname(std::string nickname);
		void setUsername(std::string username);
		void setMode(std::string mode);
		void setRealname(std::string realname);
		void setPingMsg(std::string pingMsg);
		void setOnHold(bool onHold);
		void setPingSent(time_t pingSent);
		void setPingReceived(time_t pingReceived);
		void setIsRegistered(bool isRegistered);
		void setEntersChat(time_t entersChat);
		void setFistTime(bool firtsTime);
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