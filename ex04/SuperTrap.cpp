/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 12:46:48 by lsuardi           #+#    #+#             */
/*   Updated: 2021/01/21 20:55:17 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

SuperTrap::SuperTrap(std::string name) : ClapTrap(name), FragTrap(name), NinjaTrap(name),
_hitPoints(FragTrap::_hitPoints), _maxHitPoints(FragTrap::_maxHitPoints), _rangedAttackDmg(FragTrap::_rangedAttackDmg),
_armorDmgReduction(FragTrap::_armorDmgReduction), _energyPoints(NinjaTrap::_energyPoints),
_maxEnergyPoints(NinjaTrap::_maxEnergyPoints), _meleeAttackDmg(NinjaTrap::_meleeAttackDmg), _name(name)
{
	std::cout << "SUP3R-TP <" << name << "> enabled!" << std::endl;
	std::cout << '<' << name << "> - I'm as boring as the other ClapTraps, but I'm stronger!" << std::endl;
}

SuperTrap::~SuperTrap(void)
{
	std::cout << "SUP3R-TP <" << _name << "> disabled!" << std::endl;
}

void	SuperTrap::takeDamage(unsigned int amount)
{
	amount *= (100 - _armorDmgReduction) / 100.0;
	if (_hitPoints <= 0)
		std::cout << "SUP3R-TP <" << _name << "> is already dead!" << std::endl;
	else
	{
		_hitPoints -= amount;
		std::cout << "SUP3R-TP <" << _name << "> took <" << amount << "> points of damage!" << std::endl;
		std::cout << '<' << _name << "> - " << clp::randomString(HURT_Q) << std::endl;
		if (_hitPoints <= 0)
		{
			std::cout << '<' << _name << "> - " << clp::randomString(DEAD_Q) << std::endl;
			std::cout << "SUP3R-TP <" << _name << "> died!" << std::endl;
		}
	}
}

void	SuperTrap::beRepaired(unsigned int amount)
{
	if ((_hitPoints + amount) > 100)
		amount -= (100 - (_hitPoints + amount));
	if (_hitPoints <= 0)
		std::cout << "SUP3R-TP <" << _name << "> is dead!" << std::endl;
	else
	{
		_hitPoints += amount;
		std::cout << "SUP3R-TP <" << _name << "> got repared for <" << amount << "> hit points!" << std::endl;
		std::cout << '<' << _name << "> - " << clp::randomString(REPA_Q) << std::endl;
	}
}
