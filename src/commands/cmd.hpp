/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:06:03 by nlutsevi          #+#    #+#             */
/*   Updated: 2023/01/22 20:39:35 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CMD_HPP
# define CMD_HPP

# include <string>
# include <vector>

class Cmd
{
	private:
		std::string _cmdName;
		std::vector<std::string> _cmdArgs;
		void _handle_commands(std::string cmdName, std::vector<std::string> cmdArgs);

	public:
		Cmd(std::string const& line);
		~Cmd();
		Cmd(Cmd const& src);
		Cmd& operator=(Cmd const& src);

		const std::string 				&getCmdName() const;
		const std::vector<std::string> 	&getCmdArgs() const;
	
	
};

#endif

