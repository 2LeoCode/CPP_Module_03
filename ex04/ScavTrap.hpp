/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 22:09:00 by lsuardi           #+#    #+#             */
/*   Updated: 2021/01/21 21:50:52 by lsuardi          ###   ########.fr       */
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

class ScavTrap : protected ClapTrap
{
	public:

	ScavTrap(std::string name);
	virtual ~ScavTrap(void);

	void			challengeNewcomer(void);

	void	rangedAttack(std::string const &target);
	void	meleeAttack(std::string const &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);


	protected:

	using ClapTrap::_name;
	using ClapTrap::_level;
	int				_hitPoints;
	int				_maxHitPoints;
	int				_energyPoints;
	int				_maxEnergyPoints;
	int				_meleeAttackDmg;
	int				_rangedAttackDmg;
	int				_armorDmgReduction;
};

#endif
