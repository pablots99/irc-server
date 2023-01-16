/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:26:12 by marvin            #+#    #+#             */
/*   Updated: 2023/01/16 19:26:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Server.hpp"


Server::Server(const unsigned int port): _port(port)
{

    //Socket creation
    _sockfd = socket(SOCKET_DOMAIN,SOCKET_TYPE,SOCKET_PROTOCOL);
    if (_sockfd == 0)
    {
        std::cerr << "Error creating listener socket" << std::endl;
        exit(1);
    }

    //Bind socket to port and interface
    struct sockaddr_in sockaddr;
    sockaddr.sin_family = SOCKET_DOMAIN;
    sockaddr.sin_port = htons(_port);
    sockaddr.sin_addr.s_addr = INADDR_ANY; // INADDR_ANY specify that is an IP address
    if (bind(_sockfd, (struct sockaddr *) &sockaddr, sizeof(sockaddr)) < 0) {
        std::cerr << "Error binding to port: " << _port << std::endl;
        exit(1);
    }

    //Listen in port
    if (listen(_sockfd, MAX_CLIENTS) < 0) {
        std::cerr << "Error listening" << std::endl;
        exit(1);
    }

    pollfd _poll;

    _poll.events = POLLIN;
    _poll.fd     = _sockfd;
    _poll.revents = 0;

    clients.push_back(_poll);

    std::cout << "Server created" << std::endl;
}

int Server::start() {

   
    std::cout << "Server listening in port: " << this->_port << "..." << std::endl;
    return 1;
}


Server::~Server() {
    
    shutdown(this->_sockfd,SHUT_RDWR);
    for (size_t i = 1; i < this->clients.size(); i++) {
         shutdown(this->clients[i].fd,SHUT_RDWR);
         close(this->clients[i].fd);
    }
    close(this->_sockfd);
}