/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nicknameCheck.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 13:07:12 by nlutsevi          #+#    #+#             */
/*   Updated: 2023/04/23 14:46:53 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <regex>


std::string getValidNickname(const std::string& nickname)
{
    /*
    Checks that the nickname starts with a letter or special character, 
    followed by up to 8 alphanumeric characters, underscores, dashes, 
    or square brackets.
    */
    std::string allowedChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789[]_-";
    bool validNickname = true;

    // Check first character
    char firstChar = nickname[0];
    if (!(allowedChars.find(firstChar) != std::string::npos)) {
        validNickname = false;
    }
    else {
        // Check remaining characters
        for (std::basic_string<char>::size_type i = 0; i < nickname.length(); i++) {
            char currChar = nickname[i];
            if (!(allowedChars.find(currChar) != std::string::npos)) {
                validNickname = false;
                break;
            }
        }
    }

    if (validNickname) {
        if (nickname.length() > 9) 
            return nickname.substr(0, 9);
        return nickname;
    }
    return "";
}   
