/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 19:33:48 by lsuardi           #+#    #+#             */
/*   Updated: 2021/01/21 20:48:29 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

int		main(void)
{
	SuperTrap	super("SuperBoy");
	FragTrap	frag("Fraggy");

	super.vaulthunter_dot_exe("dummy");
	super.ninjaShoebox(frag);
	super.meleeAttack("dummy");
	super.rangedAttack("dummy");


	frag.meleeAttack("dummy");
	frag.rangedAttack("dummy");
	frag.beRepaired(20);
	frag.vaulthunter_dot_exe("dummy");
	frag.takeDamage(90);

	ScavTrap	scav("Scavy");

	scav.meleeAttack("dummy");
	scav.rangedAttack("dummy");
	scav.takeDamage(30);
	scav.beRepaired(20);
	scav.challengeNewcomer();
	scav.takeDamage(90);

	NinjaTrap	ninja("Ninjoux");

	ninja.meleeAttack("dummy");
	ninja.rangedAttack("dummy");
	ninja.takeDamage(30);
	ninja.beRepaired(20);

	FragTrap	frag2("Resurrected Fraggy");
	ScavTrap	scav2("Resurrected Scavy");
	NinjaTrap	ninja2("Ninjoux's buddy");

	ninja.ninjaShoebox(frag2);
	ninja.ninjaShoebox(scav2);
	ninja.ninjaShoebox(ninja2);

	return (0);
}
