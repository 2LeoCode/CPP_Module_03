/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 12:20:44 by lsuardi           #+#    #+#             */
/*   Updated: 2021/01/21 21:51:00 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "NinjaTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap
{
	public:

	SuperTrap(std::string name);
	virtual ~SuperTrap(void);

	using FragTrap::rangedAttack;
	using NinjaTrap::meleeAttack;
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);

	protected:

	std::string _name;
	int _hitPoints;
	int _maxHitPoints;
	int _rangedAttackDmg;
	int _armorDmgReduction;
	int _energyPoints;
	int _maxEnergyPoints;
	int _meleeAttackDmg;
};

#endif
