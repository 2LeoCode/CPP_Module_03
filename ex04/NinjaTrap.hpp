/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 11:24:15 by lsuardi           #+#    #+#             */
/*   Updated: 2021/01/21 21:50:45 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class NinjaTrap : virtual protected ClapTrap
{
	public:

	NinjaTrap(std::string name);
	virtual ~NinjaTrap(void);

	void	ninjaShoebox(FragTrap &ft);
	void	ninjaShoebox(ScavTrap &st);
	void	ninjaShoebox(NinjaTrap &nt);

	void			rangedAttack(std::string const &target);
	void			meleeAttack(std::string const &target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);


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
