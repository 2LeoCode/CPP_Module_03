/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 21:37:53 by lsuardi           #+#    #+#             */
/*   Updated: 2021/01/20 00:04:36 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : _name(name), _hitPoints(100), _maxHitPoints(100), _energyPoints(100),
_maxEnergyPoints(100), _level(1), _meleeAttackDmg(30), _rangedAttackDmg(20), _armorDmgReduction(5)
{
	std::cout << "FR4G-TP <" << name << "> enabled!" << std::endl;
	std::cout << '<' << name << "> - " << frg::randomString(JOIN_Q) << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FR4G-TP <" << _name << "> disabled!" << std::endl;
}

void	FragTrap::rangedAttack(std::string const &target)
{

	if (_hitPoints <= 0)
		std::cout << "FR4G-TP <" << _name << "> is destroyed!" << std::endl;
	else
	{
		std::cout << "FR4G-TP <" << _name << "> attacks <" << target << "> at range, causing <" << _rangedAttackDmg << "> points of damage!" << std::endl;
		std::cout << '<' << _name << "> - " << frg::randomString(RGED_Q) << std::endl;
	}
}

void	FragTrap::meleeAttack(std::string const &target)
{
	if (_hitPoints <= 0)
		std::cout << "FR4G-TP <" << _name << "> is dead!" << std::endl;
	else
	{
		std::cout << "FR4G-TP <" << _name << "> attacks <" << target << "> with melee, causing <" << _meleeAttackDmg << "> points of damage!" << std::endl;
		std::cout << '<' << _name << "> - " << frg::randomString(MLEE_Q) << std::endl;
	}
}

void	FragTrap::takeDamage(unsigned int amount)
{
	amount *= (100 - _armorDmgReduction) / 100.0;
	if (_hitPoints <= 0)
		std::cout << "FR4G-TP <" << _name << "> is already dead!" << std::endl;
	else
	{
		_hitPoints -= amount;
		std::cout << "FR4G-TP <" << _name << "> took <" << amount << "> points of damage!" << std::endl;
		std::cout << '<' << _name << "> - " << frg::randomString(HURT_Q) << std::endl;
		if (_hitPoints <= 0)
		{
			std::cout << '<' << _name << "> - " << frg::randomString(DEAD_Q) << std::endl;
			std::cout << "FR4G-TP <" << _name << "> died!" << std::endl;
		}
	}
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if ((_hitPoints + amount) > 100)
		amount -= (100 - (_hitPoints + amount));
	if (_hitPoints <= 0)
		std::cout << "FR4G-TP <" << _name << "> is dead!" << std::endl;
	else
	{
		_hitPoints += amount;
		std::cout << "FR4G-TP <" << _name << "> got repared for <" << amount << "> hit points!" << std::endl;
		std::cout << '<' << _name << "> - " << frg::randomString(REPA_Q) << std::endl;
	}
}

void	FragTrap::vaulthunter_dot_exe(std::string const &target)
{
	if (_hitPoints <= 0)
		std::cout << "FR4G-TP <" << _name << "> is dead!" << std::endl;
	else if (_energyPoints < 25)
	{
		std::cout << "FR4G-TP <" << _name << "> has not enough energy to enable VaultHunter.EXE" << std::endl;
		std::cout << '<' << _name << "> " << frg::randomString(OUTA_Q) << std::endl;
	}
	else
	{
		std::cout << "FR4G-TP <" << _name << "> INITIALIZING VaultHunter.EXE..." << std::endl;
		for (char i = '3'; i >= '0'; i--)
		{
			sleep(1);
			std::cout << "( " << i << " )" << std::endl;
		}
		std::cout << "FRAG-TP <" << _name << "> ACTIVATED VaultHunter.EXE!" << std::endl;
		std::cout << '<' << _name << "> - " << frg::randomString(VHEX_Q) << std::endl;
	}
}

static std::uint32_t	getSize(std::string *s)
{
	int		i = 0;

	while (s[i] != "")
		i++;
	return (i);
}

std::string				frg::randomString(int i)
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
