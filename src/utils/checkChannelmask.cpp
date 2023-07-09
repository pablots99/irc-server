/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkChannelmask.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 10:30:19 by nlutsevi          #+#    #+#             */
/*   Updated: 2023/07/09 10:47:24 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

//TODO: check in wechat
bool		isValidChannelMask(std::string const& channelName) {
	return (channelName[0] == '#' || channelName[0] == '+' || channelName[0] == '!' || channelName[0] == '&');
}