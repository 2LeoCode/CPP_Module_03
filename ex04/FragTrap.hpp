/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 21:37:50 by lsuardi           #+#    #+#             */
/*   Updated: 2021/01/21 21:50:32 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual protected ClapTrap
{
	public:

	FragTrap(std::string name);
	virtual ~FragTrap(void);

	void			vaulthunter_dot_exe(std::string const &target);

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
