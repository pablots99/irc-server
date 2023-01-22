/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:49:12 by ptorres           #+#    #+#             */
/*   Updated: 2023/01/16 21:03:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "server/Server.hpp"

#define PORT 3490

int main() { 

    Server *server = new Server(PORT);

    server->start();

    delete(server);
    return 0;
}
