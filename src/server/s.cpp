#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <poll.h>

const int MAX_CLIENTS = 100;
const int BUFFER_SIZE = 1024;

int main() {
    int listener = socket(AF_INET, SOCK_STREAM, 0);
    if (listener < 0) {
        std::cerr << "Error creating listener socket" << std::endl;
        return 1;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(3490); //Binds to port 3490
    addr.sin_addr.s_addr = INADDR_ANY; //Binds the socket to all available interfaces
    if (bind(listener, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
        std::cerr << "Error binding to port" << std::endl;
        return 1;
    }

    listen(listener, MAX_CLIENTS);
    std::vector<pollfd> clients;

    

    /* Adding the listener socket fd at the end of clients vector and setting the events monitored
    as POLLIN (the program is notified when there is data available to be read on the socket).
    The third parameter sets `reverts` to 0 to ensure that there is no stale data from previous calls
    and to indicate that there are no events occured to this fd yet. */
    
    pollfd _p;

    _p.events = POLLIN;
    _p.fd     = listener;
    _p.revents = 0;

    clients.push_back(_p);

    while (true) {
        /*Monitor multiple fds of connected clients.
        param: clients.data() is a pointer to the first element of clients vector containing all client's fds.
        param: clients.size() is the number of client's fds being monitored
        param: -1 is the timeout, -1 means that function will block indefinitely until an event occurs
        return: poll_result is the number of clients with data available to read
        */
        int poll_result = poll(clients.data(), clients.size(), -1);
        if (poll_result == -1) {
            std::cerr << "Error polling sockets" << std::endl;
            break;
        }

        /*Bitwise AND that checks if the `POLLIN` event occurred on the listener socket fd.
        If it did occur, this expression will evaluate to true*/
        if (clients[0].revents & POLLIN) {
            int new_client = accept(listener, NULL, NULL);
            if (new_client < 0) {
                std::cerr << "Error accepting new connection" << std::endl;
                continue;
            }

            pollfd _p_client;

            _p_client.events = POLLIN;
            _p_client.fd     = new_client;
            _p_client.revents = 0;

            /*Adding accepted client fd at the end of cliends vector*/
            clients.push_back(_p_client);
            std::cout << "New client connected" << std::endl;
        }

        for (size_t i = 1; i < clients.size(); i++) {
            if (clients[i].revents & POLLIN) {
                char buffer[BUFFER_SIZE];
                int received = recv(clients[i].fd, buffer, sizeof(buffer), 0);
                std::cout << "fd_: " << clients[i].fd << " events: " << clients[i].events << " reverts: " << clients[i].revents << std::endl;
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
        }
    }
	//Close server and client sockets
    
    return 0;
}