/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generatePingRandomString.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:58:26 by nlutsevi          #+#    #+#             */
/*   Updated: 2023/02/12 22:25:56 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <string>

std::string generatePingRandomString() {
	std::string	random_str;
	static const unsigned char symbols[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "!$/%()=?^_;\\|@#~[]{},-'+";
	random_str.reserve(10);
	for (int i = 0; i < 10; ++i) {
		unsigned char c = symbols[rand() % (sizeof(symbols) - 1)];
        random_str.push_back(c);
	}
	return random_str;
}