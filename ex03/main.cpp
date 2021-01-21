/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 19:33:48 by lsuardi           #+#    #+#             */
/*   Updated: 2021/01/20 12:09:03 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

int		main(void)
{
	FragTrap	fa("FRAG A");
	FragTrap	fb("FRAG B");
	FragTrap	fc("FRAG C");
	ScavTrap	sa("SCAV A");
	ScavTrap	sb("SCAV B");
	ScavTrap	sc("SCAV C");
	NinjaTrap	na("NINJ A");
	NinjaTrap	nb("NINJ B");
	NinjaTrap	nc("NINJ C");

	na.meleeAttack("dummy");
	nb.ninjaShoebox(fa);
	nb.ninjaShoebox(sa);
	nb.ninjaShoebox(nc);
	nc.takeDamage(150);
	fa.meleeAttack("dummy");
	fa.takeDamage(70);
	fa.takeDamage(30);
	fb.rangedAttack("dummy");
	fb.takeDamage(50);
	fb.beRepaired(30);
	fb.takeDamage(60);
	fb.vaulthunter_dot_exe("dummy");
	fc.meleeAttack("dummy");
	fc.vaulthunter_dot_exe("dummy");
	fc.takeDamage(150);
	sa.meleeAttack("dummy");
	sa.rangedAttack("dummy");
	sb.challengeNewcomer();
	sb.challengeNewcomer();
	sa.challengeNewcomer();
	sb.challengeNewcomer();
	sc.challengeNewcomer();
	sc.takeDamage(30);
	return (0);
}
