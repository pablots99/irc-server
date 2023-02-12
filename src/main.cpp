/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:49:12 by ptorres           #+#    #+#             */
/*   Updated: 2023/02/04 18:02:43 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "includes/Server.hpp"

#define PORT 3490

int main() { 

    Server *server = new Server(PORT);

    server->start();

    delete(server);
    return 0;
}
