/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 19:33:48 by lsuardi           #+#    #+#             */
/*   Updated: 2021/01/19 21:56:57 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int		main(void)
{
	FragTrap	a("Robot A");
	FragTrap	b("Robot B");
	FragTrap	c("Robot C");

	a.meleeAttack("dummy");
	a.takeDamage(70);
	a.takeDamage(30);
	b.rangedAttack("dummy");
	b.takeDamage(50);
	b.beRepaired(30);
	b.takeDamage(60);
	b.vaulthunter_dot_exe("dummy");
	c.meleeAttack("dummy");
	c.vaulthunter_dot_exe("dummy");
	c.takeDamage(150);
	return (0);
}
