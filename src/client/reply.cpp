/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reply.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 19:40:36 by nlutsevi          #+#    #+#             */
/*   Updated: 2023/02/04 19:42:52 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/reply.hpp"

std::string		Error(std::string errCode)
{
	std::string		err;

	if (errCode == ERR_NEEDMOREPARAMS)
		err = "461 :Not enough parameters";
	return err;
}