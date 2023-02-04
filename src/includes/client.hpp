/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:22:34 by ptorres           #+#    #+#             */
/*   Updated: 2023/02/04 17:32:35 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Client { 
    public:
        std::string nick;
        std::string id;
        std::string user_type;
        Client();
        ~Client();
    private:
        //std::map<channel>
};