/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 21:37:53 by lsuardi           #+#    #+#             */
/*   Updated: 2021/01/20 12:49:08 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_prefix = "FR4G";
	_hitPoints = 100;
	_maxHitPoints = 100;
	_energyPoints = 100;
	_maxEnergyPoints = 100;
	_meleeAttackDmg = 30;
	_rangedAttackDmg = 20;
	_armorDmgReduction = 5;
	std::cout << _prefix << "-TP <" << name << "> enabled!" << std::endl;
	std::cout << '<' << name << "> - " << clp::randomString(JOIN_Q) << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << _prefix << "-TP <" << _name << "> disabled!" << std::endl;
}

void	FragTrap::vaulthunter_dot_exe(std::string const &target)
{
	if (_hitPoints <= 0)
		std::cout << _prefix << "-TP <" << _name << "> is dead!" << std::endl;
	else if (_energyPoints < 25)
	{
		std::cout << _prefix << "-TP <" << _name << "> has not enough energy to enable VaultHunter.EXE" << std::endl;
		std::cout << '<' << _name << "> " << clp::randomString(OUTA_Q) << std::endl;
	}
	else
	{
		std::cout << _prefix << "-TP <" << _name << "> INITIALIZING VaultHunter.EXE..." << std::endl;
		for (char i = '3'; i >= '0'; i--)
		{
			sleep(1);
			std::cout << "( " << i << " )" << std::endl;
		}
		std::cout << "FRAG-TP <" << _name << "> ACTIVATED VaultHunter.EXE!" << std::endl;
		std::cout << '<' << _name << "> - " << clp::randomString(VHEX_Q) << std::endl;
	}
}
