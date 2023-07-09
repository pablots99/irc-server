/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:06:03 by nlutsevi          #+#    #+#             */
/*   Updated: 2023/07/09 10:18:34 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CMD_HPP
# define CMD_HPP

# include "user.hpp"
# include "bbdd.hpp"
# include "reply.hpp"
# include <string>
# include <vector>
# include <sstream>
# include <unordered_map>


class Reply;

class Cmd : public Bbdd
{
	private:
		std::string 				_cmdName;
		std::vector<std::string>	_cmdArgs;
		void _handle_commands(std::string cmdName, std::vector<std::string> cmdArgs, User* user);

	public:
		Cmd(std::string const& line, User* user);
		~Cmd();
		Cmd(Cmd const& src);
		Cmd& operator=(Cmd const& src);

		const std::string 				&getCmdName() const;
		const std::vector<std::string> 	&getCmdArgs() const;
		void							nickCmd(std::vector<std::string> cmdArgs, User* user, Reply* reply);
		void							userCmd(std::vector<std::string> cmdArgs, User* user, Reply* reply);
		void							pongCmd(std::vector<std::string> cmdArgs, User* user, Reply* reply);
		void							joinCmd(std::vector<std::string> cmdArgs, User* user, Reply* reply);
};

#endif

