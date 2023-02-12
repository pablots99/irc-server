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

#include "../includes/server.hpp"

Server::Server(unsigned int port) : Bbdd()
{
	this->_port = port;
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

Server::~Server() {
    
    shutdown(this->_sockfd,SHUT_RDWR);
    //TODO use iterators instead of size
    for (size_t i = 1; i < this->clients.size(); i++) {
         shutdown(this->clients[i].fd,SHUT_RDWR);
         close(this->clients[i].fd);
    }
    close(this->_sockfd);
}

void 		Server::ping_check(int fd) {
	time_t now;
	time_t since_last_ping;
	User *user = getUser(fd);
	if (user->getOnHold()) {
		now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
		since_last_ping = now - user->getPingSent();
		if (since_last_ping >= 120) {
			std::cout << "User " << user->getUsername() << " has been disconnected for inactivity" << std::endl;
			close(fd);
			clients.erase(clients.begin() + fd);
			_usersMap.erase(fd);
		}
	}
	now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	time_t since_user_entered_chat = now - user->getEntersChat();
	if (since_user_entered_chat >= 60 && (!user->getIsRegistered()))
		throw std::runtime_error(CloseError("Registration timeout"));
	//TODO:Since last message
	send_ping_to_user(fd);
}

int Server::start() {
    std::cout << "Server listening in port: " << this->_port << "..." << std::endl;
    while (true)
    {

        /*Monitor multiple fds of connected clients.
        param: clients.data() is a pointer to the first element of clients vector containing all client's fds.
        param: clients.size() is the number of client's fds being monitored
        param: -1 is the timeout, -1 means that function will block indefinitely until an event occurs
        return: poll_result is the number of clients with data available to read
        */
        if(poll(clients.data(), clients.size(), -1) == -1)
        {
            std::cerr << "Error polling sockets" << std::endl;
            break ;
        }
        /*Bitwise AND that checks if the `POLLIN` event occurred on the listener socket fd.
        If it did occur, this expression will evaluate to true meeaning there is a new client*/
        if(clients[0].revents & POLLIN) {
            _accept_client();
        }
        for (size_t i = 1; i < clients.size(); i++) {
            if (clients[i].revents & POLLIN) {
                char buffer[BUFFER_SIZE];
                int received = recv(clients[i].fd, buffer, sizeof(buffer), 0);
                std::cout << "fd_: " << clients[i].fd << " events: " << clients[i].events << " reverts: " << clients[i].revents << std::endl;
                //Read commands send by client
				_read_command(buffer, clients[i].fd);
                if (received < 0) {
                    std::cerr << "Error receiving data from client" << std::endl;
                    continue;
                }
                if (received == 0) {
                    std::cout << "Client disconnected" << std::endl;
                    close(clients[i].fd);
                    clients.erase(clients.begin() + i);
                    i--;
                    continue;
                }
                for (size_t j = 1; j < clients.size(); j++) {
                    if (i == j) continue;
                    send(clients[j].fd, buffer, received, 0);
                }
            }
			ping_check(clients[i].fd);
        }
    }

    return 1;
}

// void Server::_recive_buffer() {
//	}

// void Server::_send_buffer(int fd) {
//     for (size_t j = 1; j < clients.size(); j++) {
//         if (clients[j].fd == fd) continue;
//             send(clients[j].fd, buffer, received, 0);
//     }
// }


void Server::_read_command(char buffer[BUFFER_SIZE], int client_fd) {
	User *user = getUser(client_fd);
	bool first_time;
	user == NULL ? first_time = true : first_time = false;
	_user_message(buffer, client_fd, first_time);
	delete user;
}

void Server::_accept_client() {
    int new_client = accept(_sockfd, NULL, NULL);
    if (new_client < 0) {
        std::cerr << "Error accepting new connection" << std::endl;
        exit(1);
    }

    pollfd _poll;

    _poll.events = POLLIN;
    _poll.fd     = new_client;
    _poll.revents = 0;

    clients.push_back(_poll);

    std::cout << "New client connected" << std::endl;
}


void Server::_user_message(char buffer[BUFFER_SIZE], int client_fd, bool first_time) {
	User *user = NULL;
	std::string line(buffer);

	first_time ? user = new User() : getUser(client_fd);
	if (first_time) {
		time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
		user->setEntersChat(now);
	}
	user->setClientFd(client_fd);
	_usersMap.insert(std::pair<int, User*>(client_fd, user));
	//Call Cmd constructor (commands parser) passing line written by client as argument
	Cmd c(line, user, first_time);
}


void Server::send_ping_to_user(int fd) {
	time_t now;
	User *user = getUser(fd);
	//TODO: apapt to actual ping from irc-hispano
	std::string ping = "PING :irc.42.fr\r\n";
	send(fd, ping.c_str(), ping.length(), 0);
	now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	user->setPingSent(now);
	user->setOnHold(true);
}



