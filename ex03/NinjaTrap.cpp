/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 11:25:13 by lsuardi           #+#    #+#             */
/*   Updated: 2021/01/20 19:50:51 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(std::string name) : ClapTrap(name), _prefix("N1NJ4"), _hitPoints(60), _maxHitPoints(60),
_energyPoints(120), _maxEnergyPoints(120), _meleeAttackDmg(60), _rangedAttackDmg(5), _armorDmgReduction(0)
{
	std::cout << _prefix << "-TP <" << name << "> enabled!" << std::endl;
	std::cout << '<' << name << "> - " << clp::randomString(JOIN_Q) << std::endl;
}

NinjaTrap::~NinjaTrap(void)
{
	std::cout << _prefix << "-TP <" << _name << "> disabled!" << std::endl;
}

void	NinjaTrap::ninjaShoebox(FragTrap &ft)
{
	if (_hitPoints <= 0)
		std::cout << _prefix << "-TP <" << _name << "> is dead!" << std::endl;
	else if (_energyPoints < 30)
		std::cout << '<' << _name << "> - " << clp::randomString(OUTA_Q) << std::endl;
	else
	{
		_energyPoints -= 30;
		std::cout << '<' << _name << "> - I hate those stupid FragTraps!!!" << std::endl;
		ft.takeDamage(90);
	}
}

void	NinjaTrap::ninjaShoebox(ScavTrap &st)
{
	if (_hitPoints <= 0)
		std::cout << _prefix << "-TP <" << _name << "> is dead!" << std::endl;
	else if (_energyPoints < 30)
		std::cout << '<' << _name << "> - " << clp::randomString(OUTA_Q) << std::endl;
	else
	{
		_energyPoints -= 30;
		std::cout << '<' << _name << "> - Let me scav your energy, ScavTrap!" << std::endl;
		st.takeDamage(40);
		beRepaired(20);
	}
}

void	NinjaTrap::ninjaShoebox(NinjaTrap &nt)
{
	if (_hitPoints <= 0)
		std::cout << _prefix << "-TP <" << _name << "> is dead!" << std::endl;
	else if (_energyPoints < 30)
		std::cout << '<' << _name << "> - " << clp::randomString(OUTA_Q) << std::endl;
	else
	{
		_energyPoints -= 30;
		std::cout << '<' << _name << "> - Oh! A NinjaTrap friend! High five!" << std::endl;
	}
}
