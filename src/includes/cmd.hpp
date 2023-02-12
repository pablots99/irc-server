/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:06:03 by nlutsevi          #+#    #+#             */
/*   Updated: 2023/02/12 22:02:42 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CMD_HPP
# define CMD_HPP

# include "user.hpp"
# include <string>
# include <vector>

class User;

class Cmd
{
	private:
		std::string 				_cmdName;
		std::vector<std::string>	_cmdArgs;
		void _handle_commands(std::string cmdName, std::vector<std::string> cmdArgs, User* user, bool first_time);

	public:
		Cmd(std::string const& line, User* user, bool first_time);
		~Cmd();
		Cmd(Cmd const& src);
		Cmd& operator=(Cmd const& src);

		const std::string 				&getCmdName() const;
		const std::vector<std::string> 	&getCmdArgs() const;
	
	
};

#endif

