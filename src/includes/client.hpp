/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:22:34 by ptorres           #+#    #+#             */
/*   Updated: 2023/02/04 17:37:13 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Client { 
    public:
        std::string nick; // max 9 characters
        std::string user_type;
        std::string real_host;
        std::string username;
        
        Client();
        ~Client();
    private:
        //std::map<channel>
};