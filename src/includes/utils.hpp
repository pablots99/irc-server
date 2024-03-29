/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:55:02 by nlutsevi          #+#    #+#             */
/*   Updated: 2023/04/23 13:15:23 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP


# include <string>
# include <vector>

std::vector<std::string> 	splitString(std::string const& str, char delim);
std::string					generatePingRandomString(void);
std::string                 toUpperCase(std::string str);
std::string                 getValidNickname(const std::string& nickname);

#endif