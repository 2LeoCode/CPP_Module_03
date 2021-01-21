#!/bin/bash

clang++ main.cpp ClapTrap.cpp FragTrap.cpp ScavTrap.cpp -F ../ -L ../SDL2.framework/Versions/Current -framework SDL2 -o ClapTrap
