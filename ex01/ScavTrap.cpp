/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 22:08:56 by lsuardi           #+#    #+#             */
/*   Updated: 2021/01/20 00:05:27 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : _name(name), _hitPoints(100), _maxHitPoints(100), _energyPoints(50),
_maxEnergyPoints(50), _level(1), _meleeAttackDmg(20), _rangedAttackDmg(15), _armorDmgReduction(3)
{
	std::cout << "SC4V-TP <" << name << "> enabled!" << std::endl;
	std::cout << '<' << name << "> - " << scv::randomString(JOIN_Q) << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "SC4V-TP <" << _name << "> disabled!" << std::endl;
}

void	ScavTrap::rangedAttack(std::string const &target)
{

	if (_hitPoints <= 0)
		std::cout << "SC4V-TP <" << _name << "> is destroyed!" << std::endl;
	else
	{
		std::cout << "SC4V-TP <" << _name << "> attacks <" << target << "> at range, causing <" << _rangedAttackDmg << "> points of damage!" << std::endl;
		std::cout << '<' << _name << "> - " << scv::randomString(RGED_Q) << std::endl;
	}
}

void	ScavTrap::meleeAttack(std::string const &target)
{
	if (_hitPoints <= 0)
		std::cout << "SC4V-TP <" << _name << "> is dead!" << std::endl;
	else
	{
		std::cout << "SC4V-TP <" << _name << "> attacks <" << target << "> with melee, causing <" << _meleeAttackDmg << "> points of damage!" << std::endl;
		std::cout << '<' << _name << "> - " << scv::randomString(MLEE_Q) << std::endl;
	}
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	amount *= (100 - _armorDmgReduction) / 100.0;
	if (_hitPoints <= 0)
		std::cout << "SC4V-TP <" << _name << "> is already dead!" << std::endl;
	else
	{
		_hitPoints -= amount;
		std::cout << "SC4V-TP <" << _name << "> took <" << amount << "> points of damage!" << std::endl;
		std::cout << '<' << _name << "> - " << scv::randomString(HURT_Q) << std::endl;
		if (_hitPoints <= 0)
		{
			std::cout << '<' << _name << "> - " << scv::randomString(DEAD_Q) << std::endl;
			std::cout << "SC4V-TP <" << _name << "> died!" << std::endl;
		}
	}
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if ((_hitPoints + amount) > 100)
		amount -= (100 - (_hitPoints + amount));
	if (_hitPoints <= 0)
		std::cout << "SC4V-TP <" << _name << "> is dead!" << std::endl;
	else
	{
		_hitPoints += amount;
		std::cout << "SC4V-TP <" << _name << "> got repared for <" << amount << "> hit points!" << std::endl;
		std::cout << '<' << _name << "> - " << scv::randomString(REPA_Q) << std::endl;
	}
}

void	ScavTrap::challengeNewcomer(void)
{
	t_times		timespec;

	if (_hitPoints <= 0)
		std::cout << "SC4V-TP <" << _name << "> is dead!" << std::endl;
	std::cout << "SC4V-TP <" << _name << "> is turning the wheel of challenges!" << std::endl;
	t_challenge		challenges[4] = { &cha::bottleFlip, &cha::iceBucket, &cha::hotPepper, &cha::stairsClimbing };
	t_challenge		chosenChallenge;

	int			i;

	sleep(2);
	clock_gettime(CLOCK_REALTIME, &timespec);
	std::srand(timespec.tv_nsec);
	i = std::rand() % 4;
	chosenChallenge = challenges[i];
	if ((*chosenChallenge)(_name))
		std::cout << "SC4V-TP <" << _name << "> passed challenge!" << std::endl;
	else
		std::cout << "SC4V-TP <" << _name << "> failed challenge!" << std::endl;
}

static std::uint32_t	getSize(std::string *s)
{
	int		i = 0;

	while (s[i] != "")
		i++;
	return (i);
}

std::string				scv::randomString(int i)
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

bool					cha::bottleFlip(std::string name)
{
	t_times			timespec;
	int				i;

	clock_gettime(CLOCK_REALTIME, &timespec);
	std::srand(timespec.tv_nsec);
	std::cout << "CHALLENGE: Bottle Flip" << std::endl;
	if ((i = rand() % 3) == 1)
		std::cout << '<' << name << "> - The bottle landed right!" << std::endl;
	else
		std::cout << '<' << name << "> - The bottle landed wrong!" << std::endl;
	return (i == 1);
}

bool					cha::hotPepper(std::string name)
{
	std::cout << "CHALLENGE: Hot Pepper" << std::endl;

	std::cout << '<' << name << "> - What do you think your pepper will do to me, I'm a freaking rob...AAAHHHH WHAT AM I?!" << std::endl;
	return (true);
}

bool					cha::iceBucket(std::string name)
{
	std::cout << "CHALLENGE: Ice Bucket" << std::endl;

	std::cout << '<' << name << "> - This can't be so bad...DZZZHDD hai, wo shi paishou!" << std::endl;
	return (true);
}

bool					cha::stairsClimbing(std::string name)
{
	SDL_AudioSpec		wav_spec;
	Uint32				wav_length;
	Uint8				*wav_buffer;
	SDL_AudioDeviceID	deviceId;
	int					wav_success;

	std::cout << "CHALLENGE: Climb Stairs" << std::endl;
	std::cout << '<' << name << "> - STAIRS?! NOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO!" << std::endl;
	SDL_Init(SDL_INIT_AUDIO);
	SDL_LoadWAV("stairs.wav", &wav_spec, &wav_buffer, &wav_length);
	deviceId = SDL_OpenAudioDevice(NULL, 0, &wav_spec, NULL, 0);
	wav_success = SDL_QueueAudio(deviceId, wav_buffer, wav_length);
	SDL_PauseAudioDevice(deviceId, 0);
	SDL_Delay(7000);
	SDL_CloseAudioDevice(deviceId);
	SDL_FreeWAV(wav_buffer);
	return (false);
}
