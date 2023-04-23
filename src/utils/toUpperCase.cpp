/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toUppercase.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 13:00:15 by nlutsevi          #+#    #+#             */
/*   Updated: 2023/04/23 14:17:10 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <cctype>


std::string toUpperCase(std::string str) {
    for (std::string::size_type i = 0; i < str.length(); i++) {
        str[i] = std::toupper(str[i]);
    }
    return str;
}