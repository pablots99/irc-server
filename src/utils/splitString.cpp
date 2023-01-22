/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitString.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:47:29 by nlutsevi          #+#    #+#             */
/*   Updated: 2023/01/22 19:48:50 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <vector>


std::vector<std::string> splitString(std::string const& str, char delim)
{
	std::vector<std::string> result;
	std::stringstream ss(str);
	std::string item;

	while (std::getline(ss, item, delim))
		result.push_back(item);
	return result;
}