/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:19:47 by marvin            #+#    #+#             */
/*   Updated: 2023/01/16 19:19:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SERVER_HPP
# define SERVER_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <cstring>
# include <unistd.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <poll.h>
# include <chrono>
# include "bbdd.hpp"
# include "cmd.hpp"
# include "reply.hpp"
# include "utils.hpp"

# define SOCKET_DOMAIN AF_INET // AF_ LOCAL -> localhost, AF_INET -> ipv4, AF_INET_6 -> ipv6
# define SOCKET_TYPE SOCK_STREAM //SOCK_STREAM -> TCP, SOCK_DGRAM -> UDP
# define SOCKET_PROTOCOL 0 // 0 -> IP protocol
# define MAX_CLIENTS 1024
# define BUFFER_SIZE 1024
# define PING_TIMEOUT_MS 60

class Bbdd;
class Utils;

class Server : public Bbdd
{
	private:
	    unsigned int 			_port;
	    int 					_sockfd;
	    std::vector<pollfd> 	clients;
		void 					_read_command(char buffer[BUFFER_SIZE], int fd, User *user);
	    void 					_accept_client();
		User* 					_user_config(int fd);
	    // void _recive_buffer();
	    // void _send_buffer();

	public:
	    Server(unsigned int port);
		~Server();
	    int 					start();
		void 					ping_check();
		void 					send_ping_to_user(int fd);
};

#endif
