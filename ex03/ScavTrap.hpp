/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 22:09:00 by lsuardi           #+#    #+#             */
/*   Updated: 2021/01/20 11:43:05 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

namespace cha
{
	bool			bottleFlip(std::string name);
	bool			iceBucket(std::string name);
	bool			hotPepper(std::string name);
	bool			stairsClimbing(std::string name);
};

typedef bool		(*t_challenge)(std::string);

class ScavTrap : public ClapTrap
{
	public:

	ScavTrap(std::string name);
	~ScavTrap(void);

	void			challengeNewcomer(void);
};

#endif
