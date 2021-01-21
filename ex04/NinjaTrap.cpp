/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 11:25:13 by lsuardi           #+#    #+#             */
/*   Updated: 2021/01/21 20:53:42 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(std::string name) : ClapTrap(name), _hitPoints(60), _maxHitPoints(60),
_energyPoints(120), _maxEnergyPoints(120), _meleeAttackDmg(60), _rangedAttackDmg(5), _armorDmgReduction(0)
{
	std::cout << "N1NJ4-TP <" << name << "> enabled!" << std::endl;
	std::cout << '<' << name << "> - " << clp::randomString(JOIN_Q) << std::endl;
}

NinjaTrap::~NinjaTrap(void)
{
	std::cout << "N1NJ4-TP <" << _name << "> disabled!" << std::endl;
}

void	NinjaTrap::ninjaShoebox(FragTrap &ft)
{
	if (_hitPoints <= 0)
		std::cout << "N1NJ4-TP <" << _name << "> is dead!" << std::endl;
	else if (_energyPoints < 30)
		std::cout << '<' << _name << "> - " << clp::randomString(OUTA_Q) << std::endl;
	else
	{
		std::cout << "N1NJ4-TP <" << _name << "> uses Ninja Shoebox" << std::endl;
		_energyPoints -= 30;
		std::cout << '<' << _name << "> - I hate those stupid FragTraps!!!" << std::endl;
		ft.takeDamage(90);
	}
}

void	NinjaTrap::ninjaShoebox(ScavTrap &st)
{
	if (_hitPoints <= 0)
		std::cout << "N1NJ4-TP <" << _name << "> is dead!" << std::endl;
	else if (_energyPoints < 30)
		std::cout << '<' << _name << "> - " << clp::randomString(OUTA_Q) << std::endl;
	else
	{
		std::cout << "N1NJ4-TP <" << _name << "> uses Ninja Shoebox" << std::endl;
		_energyPoints -= 30;
		std::cout << '<' << _name << "> - Let me scav your energy, ScavTrap!" << std::endl;
		st.takeDamage(40);
		beRepaired(20);
	}
}

void	NinjaTrap::ninjaShoebox(NinjaTrap &nt)
{
	if (_hitPoints <= 0)
		std::cout << "N1NJ4-TP <" << _name << "> is dead!" << std::endl;
	else if (_energyPoints < 30)
		std::cout << '<' << _name << "> - " << clp::randomString(OUTA_Q) << std::endl;
	else
	{
		std::cout << "N1NJ4-TP <" << _name << "> uses Ninja Shoebox" << std::endl;
		_energyPoints -= 30;
		std::cout << '<' << _name << "> - Oh! A NinjaTrap friend! High five!" << std::endl;
	}
}

void	NinjaTrap::rangedAttack(std::string const &target)
{
	if (_hitPoints <= 0)
		std::cout << "N1NJ4-TP <" << _name << "> is destroyed!" << std::endl;
	else
	{
		std::cout << "N1NJ4-TP <" << _name << "> attacks <" << target << "> at range, causing <" << _rangedAttackDmg << "> points of damage!" << std::endl;
		std::cout << '<' << _name << "> - " << clp::randomString(RGED_Q) << std::endl;
	}
}

void	NinjaTrap::meleeAttack(std::string const &target)
{
	if (_hitPoints <= 0)
		std::cout << "N1NJ4-TP <" << _name << "> is dead!" << std::endl;
	else
	{
		std::cout << "N1NJ4-TP <" << _name << "> attacks <" << target << "> with melee, causing <" << _meleeAttackDmg << "> points of damage!" << std::endl;
		std::cout << '<' << _name << "> - " << clp::randomString(MLEE_Q) << std::endl;
	}
}

void	NinjaTrap::takeDamage(unsigned int amount)
{
	amount *= (100 - _armorDmgReduction) / 100.0;
	if (_hitPoints <= 0)
		std::cout << "N1NJ4-TP <" << _name << "> is already dead!" << std::endl;
	else
	{
		_hitPoints -= amount;
		std::cout << "N1NJ4-TP <" << _name << "> took <" << amount << "> points of damage!" << std::endl;
		std::cout << '<' << _name << "> - " << clp::randomString(HURT_Q) << std::endl;
		if (_hitPoints <= 0)
		{
			std::cout << '<' << _name << "> - " << clp::randomString(DEAD_Q) << std::endl;
			std::cout << "N1NJ4-TP <" << _name << "> died!" << std::endl;
		}
	}
}

void	NinjaTrap::beRepaired(unsigned int amount)
{
	if ((_hitPoints + amount) > 100)
		amount -= (100 - (_hitPoints + amount));
	if (_hitPoints <= 0)
		std::cout << "N1NJ4-TP <" << _name << "> is dead!" << std::endl;
	else
	{
		_hitPoints += amount;
		std::cout << "N1NJ4-TP <" << _name << "> got repared for <" << amount << "> hit points!" << std::endl;
		std::cout << '<' << _name << "> - " << clp::randomString(REPA_Q) << std::endl;
	}
}
