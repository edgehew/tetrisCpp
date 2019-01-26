#!/bin/sh

# Run script as SUDO user because need to install sfml library
pacman -Syy
pacman -Sy libsfml-dev
