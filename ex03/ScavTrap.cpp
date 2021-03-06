/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 22:08:56 by lsuardi           #+#    #+#             */
/*   Updated: 2021/01/20 11:52:10 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_name = name;
	_prefix = "SC4V";
	_hitPoints = 100;
	_maxHitPoints = 100;
	_energyPoints = 50;
	_maxEnergyPoints = 50;
	_level = 1;
	_meleeAttackDmg = 20;
	_rangedAttackDmg = 15;
	_armorDmgReduction = 3;
	std::cout << _prefix << "-TP <" << name << "> enabled!" << std::endl;
	std::cout << '<' << name << "> - " << clp::randomString(JOIN_Q) << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "SC4V-TP <" << _name << "> disabled!" << std::endl;
}

void	ScavTrap::challengeNewcomer(void)
{
	if (_hitPoints <= 0)
		std::cout << _prefix << "-TP <" << _name << "> is dead!" << std::endl;
	std::cout << _prefix << "-TP <" << _name << "> is turning the wheel of challenges!" << std::endl;
	t_challenge		challenges[4] = { &cha::bottleFlip, &cha::iceBucket, &cha::hotPepper, &cha::stairsClimbing };
	t_challenge		chosenChallenge;

	int			i;

	sleep(2);
	i = clp::randomNumber(0, 3);
	chosenChallenge = challenges[i];
	if ((*chosenChallenge)(_name))
		std::cout << _prefix << "-TP <" << _name << "> passed challenge!" << std::endl;
	else
		std::cout << _prefix << "-TP <" << _name << "> failed challenge!" << std::endl;
}

bool	cha::bottleFlip(std::string name)
{
	int				i = clp::randomNumber(0, 2);

	std::cout << "CHALLENGE: Bottle Flip" << std::endl;
	if (!i)
		std::cout << '<' << name << "> - The bottle landed right!" << std::endl;
	else
		std::cout << '<' << name << "> - The bottle landed wrong!" << std::endl;
	return (!i);
}

bool	cha::hotPepper(std::string name)
{
	std::cout << "CHALLENGE: Hot Pepper" << std::endl;

	std::cout << '<' << name << "> - What do you think your pepper will do to me, I'm a freaking rob...AAAHHHH WHAT AM I?!" << std::endl;
	return (true);
}

bool	cha::iceBucket(std::string name)
{
	std::cout << "CHALLENGE: Ice Bucket" << std::endl;

	std::cout << '<' << name << "> - This can't be so bad...DZZZHDD hai, wo shi paishou!" << std::endl;
	return (true);
}

bool	cha::stairsClimbing(std::string name)
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
	SDL_Quit();
	return (false);
}
