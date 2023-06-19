/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:49:12 by ptorres           #+#    #+#             */
/*   Updated: 2023/06/19 21:15:56 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "includes/Server.hpp"

#define PORT 3495

int main() { 

    Server *server = new Server(PORT);

    server->start();

    delete(server);
    return 0;
}
