/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reply.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 19:34:27 by nlutsevi          #+#    #+#             */
/*   Updated: 2023/02/04 19:40:05 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLY_HPP
# define REPLY_HPP

# define ERR_NEEDMOREPARAMS "461" // Not enough parameters

# include <iostream>

class Reply
{
	public:
		Reply(void);
		~Reply(void);
		Reply(Reply const& src);
		Reply& operator=(Reply const& src);

		static std::string		Error(std::string errCode);

};
std::string		Error(std::string errCode);

#endif