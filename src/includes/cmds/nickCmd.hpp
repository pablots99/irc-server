/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nickCmd.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 20:25:30 by nlutsevi          #+#    #+#             */
/*   Updated: 2023/02/12 20:26:45 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NICKCMD_HPP
# define NICKCMD_HPP

# include <iostream>
# include "../user.hpp"
# include "../reply.hpp"

class Reply;

class nickCmd {
	public:
		nickCmd();
		~nickCmd();
		nickCmd(nickCmd const& src);
		nickCmd& operator=(nickCmd const& src);

		void		execute(std::vector<std::string> cmdArgs, User* user, Reply* reply);
};



# endif