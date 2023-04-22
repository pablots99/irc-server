/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pongCmd.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:45:34 by nlutsevi          #+#    #+#             */
/*   Updated: 2023/02/12 18:47:00 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONGCMD_HPP
# define PONGCMD_HPP

# include <iostream>
#include <sstream>
# include "../user.hpp"
# include "../reply.hpp"

class Reply;

class PongCmd {
	public:
		PongCmd();
		~PongCmd();
		PongCmd(PongCmd const& src);
		PongCmd& operator=(PongCmd const& src);

		void		execute(std::vector<std::string> cmdArgs, User* user, Reply* reply);
};

# endif