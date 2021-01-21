/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 00:20:32 by lsuardi           #+#    #+#             */
/*   Updated: 2021/01/21 21:51:50 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _level(1), _name(name)
{
	std::cout << "CREATED A CLAPTRAP" << std::endl;
}

ClapTrap::~ClapTrap(void) { }

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

int						clp::randomNumber(int a, int b)
{
	if (a > b)
	{
		int		tmp = b;
		b = a;
		a = tmp;
	}

	t_times		timespec;

	clock_gettime(CLOCK_REALTIME, &timespec);
	std::srand(timespec.tv_nsec);
	return (a + std::rand() % (b - a + 1));
}
