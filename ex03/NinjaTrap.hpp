/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 11:24:15 by lsuardi           #+#    #+#             */
/*   Updated: 2021/01/20 19:45:06 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class NinjaTrap : virtual public ClapTrap
{
	public:

	NinjaTrap(std::string name);
	~NinjaTrap(void);

	void	ninjaShoebox(FragTrap &ft);
	void	ninjaShoebox(ScavTrap &st);
	void	ninjaShoebox(NinjaTrap &nt);


	protected:

	using ClapTrap::_name;
	using ClapTrap::_level;
	std::string		_prefix;
	int				_hitPoints;
	int				_maxHitPoints;
	int				_energyPoints;
	int				_maxEnergyPoints;
	int				_meleeAttackDmg;
	int				_rangedAttackDmg;
	int				_armorDmgReduction;
};

#endif
