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

# define SOCKET_DOMAIN AF_INET // AF_ LOCAL -> localhost, AF_INET -> ipv4, AF_INET_6 -> ipv6
# define SOCKET_TYPE SOCK_STREAM //SOCK_STREAM -> TCP, SOCK_DGRAM -> UDP
# define SOCKET_PROTOCOL 0 // 0 -> IP protocol
# define MAX_CLIENTS 1024
# define BUFFER_SIZE 1024

class Server
{
	private:
	    const unsigned int _port;
	    int _sockfd;
	    std::vector<pollfd> clients;
		void _read_command(char buffer[BUFFER_SIZE]);
	    void _accept_client();
		void _user_first_message(char buffer[BUFFER_SIZE], int client_fd);
	    // void _recive_buffer();
	    // void _send_buffer();

	public:
	    Server(const unsigned int port);
	    int start();
	    ~Server();
};

#endif
