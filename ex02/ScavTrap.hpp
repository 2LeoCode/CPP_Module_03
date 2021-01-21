/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 22:09:00 by lsuardi           #+#    #+#             */
/*   Updated: 2021/01/20 01:12:52 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include "../SDL2.framework/Headers/SDL.h"

# define JOIN_QUOTES {\
	"Hey everybody! Check out my package!",\
	"Let's get this party started!",\
	"Glitching weirdness is a term of endearment, right?",\
	"Recompiling my combat code!",\
	"This time it'll be awesome, I promise!",\
	"Look out everybody! Things are about to get awesome!", "" }
# define DIE_QUOTES {\
	"I'll die the way I lived: annoying!",\
	"This could've gone better!",\
	"Good thing I don't have a soul!",\
	"I'm too pretty to die!",\
	"Robot down!", "" }
# define MELEE_QUOTES {\
	"Hyah!",\
	"Heyyah!",\
	"Take that!",\
	"Bop!",\
	"Guess who?",\
	"Meet professor punch!",\
	"Ready for the PUNCHline?!", "" }
# define RANGED_QUOTES {\
	"Step right up, to the Bulletnator 9000!",\
	"I am a tornado of death and bullets!",\
	"Stop me before I kill again, except don't!",\
	"Hehehehe, mwaa ha ha ha, MWAA HA HA HA!",\
	"Unts unts unts unts!",\
	"This is why I was built!", "" }
# define HURT_QUOTES {\
	"Aww!",\
	"Argh arghargh death gurgle gurglegurgle urgh... death.",\
	"Crap!",\
	"No, nononono NO!",\
	"If only my chassis... weren't made of recycled human body parts! Wahahaha!",\
	"My robotic flesh! AAHH!", "" }
# define REPAIRED_QUOTES {\
	"Can I just say... yeehaw.",\
	"You are ace high!",\
	"You're the wub to my dub!",\
	"Wow, that actually worked?",\
	"I'm back! Woo!",\
	"Holy crap, that worked?", "" }
# define VAULTHUNTER_QUOTES {\
	"It's happening... it's happening!",\
	"It's about to get magical!",\
	"Running the sequencer!",\
	"Look out everybody, things are about to get awesome!",\
	"Let's get this party started!", "" }
# define OUTAMMO_QUOTES {\
	"Where'd all my bullets go?",\
	"Bullets are dumb.",\
	"Who needs ammo anyway, am I right?",\
	"I need tiny death pellets!",\
	"Need some ammo!",\
	"Dangit, I'm out!",\
	"Ammo reserves are spent!",\
	"Crap, no more shots left!",\
	"Hnngh! Empty!",\
	"Coming up empty!", "" }

# define JOIN_Q 0
# define DEAD_Q 1
# define MLEE_Q 2
# define RGED_Q 3
# define HURT_Q 4
# define REPA_Q 5
# define VHEX_Q 6
# define OUTA_Q 7

typedef struct timespec	t_times;

namespace cha
{
	bool			bottleFlip(std::string name);
	bool			iceBucket(std::string name);
	bool			hotPepper(std::string name);
	bool			stairsClimbing(std::string name);
};

typedef bool		(*t_challenge)(std::string);

class ScavTrap : public ClapTrap
{
	public:

	ScavTrap(std::string name);
	~ScavTrap(void);

	void			challengeNewcomer(void);
};

#endif
