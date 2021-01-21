/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 00:20:32 by lsuardi           #+#    #+#             */
/*   Updated: 2021/01/20 12:49:00 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _level(1), _name(name)
{
	std::cout << "CREATED A CLAPTRAP" << std::endl;
}

ClapTrap::~ClapTrap(void) { }

void	ClapTrap::rangedAttack(std::string const &target)
{

	if (_hitPoints <= 0)
		std::cout << _prefix << "-TP <" << _name << "> is destroyed!" << std::endl;
	else
	{
		std::cout << _prefix << "-TP <" << _name << "> attacks <" << target << "> at range, causing <" << _rangedAttackDmg << "> points of damage!" << std::endl;
		std::cout << '<' << _name << "> - " << clp::randomString(RGED_Q) << std::endl;
	}
}

void	ClapTrap::meleeAttack(std::string const &target)
{
	if (_hitPoints <= 0)
		std::cout << _prefix << "-TP <" << _name << "> is dead!" << std::endl;
	else
	{
		std::cout << _prefix << "-TP <" << _name << "> attacks <" << target << "> with melee, causing <" << _meleeAttackDmg << "> points of damage!" << std::endl;
		std::cout << '<' << _name << "> - " << clp::randomString(MLEE_Q) << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	amount *= (100 - _armorDmgReduction) / 100.0;
	if (_hitPoints <= 0)
		std::cout << _prefix << "-TP <" << _name << "> is already dead!" << std::endl;
	else
	{
		_hitPoints -= amount;
		std::cout << _prefix << "-TP <" << _name << "> took <" << amount << "> points of damage!" << std::endl;
		std::cout << '<' << _name << "> - " << clp::randomString(HURT_Q) << std::endl;
		if (_hitPoints <= 0)
		{
			std::cout << '<' << _name << "> - " << clp::randomString(DEAD_Q) << std::endl;
			std::cout << _prefix << "-TP <" << _name << "> died!" << std::endl;
		}
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if ((_hitPoints + amount) > 100)
		amount -= (100 - (_hitPoints + amount));
	if (_hitPoints <= 0)
		std::cout << _prefix << "-TP <" << _name << "> is dead!" << std::endl;
	else
	{
		_hitPoints += amount;
		std::cout << _prefix << "-TP <" << _name << "> got repared for <" << amount << "> hit points!" << std::endl;
		std::cout << '<' << _name << "> - " << clp::randomString(REPA_Q) << std::endl;
	}
}

static std::uint32_t	getSize(std::string *s)
{
	int		i = 0;

	while (s[i] != "")
		i++;
	return (i);
}

std::string				clp::randomString(int i)
{
	static int		callCount = 0;
	std::string		s[8][11] = {JOIN_QUOTES, DIE_QUOTES, MELEE_QUOTES, RANGED_QUOTES, HURT_QUOTES, REPAIRED_QUOTES, VAULTHUNTER_QUOTES, OUTAMMO_QUOTES};

	if (i < 0 || i > 7)
		return (std::string(""));

	std::uint32_t	size = getSize(s[i]);
	std::uint32_t	rd;

	std::srand(time(NULL) + callCount);
	rd = (std::rand() % size);
	callCount++;
	return (s[i][rd]);
}
