/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   userCmd.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:32:35 by nlutsevi          #+#    #+#             */
/*   Updated: 2023/02/07 22:04:56 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USERCMD_HPP
# define USERCMD_HPP

# include <iostream>
# include "../includes/user.hpp"
# include "../includes/reply.hpp"

class UserCmd {
	public:
		UserCmd();
		~UserCmd();
		UserCmd(UserCmd const& src);
		UserCmd& operator=(UserCmd const& src);

		void		execute(std::vector<std::string> cmdArgs, User* user, Reply* reply);
};



# endif