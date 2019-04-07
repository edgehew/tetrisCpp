#!/bin/sh

COMMAND=$1
# Run script as SUDO user to install sfml library
if [ "$COMMAND" = "pacman" ]; then
    pacman -Syy
    pacman -Sy libsfml-dev
elif [ "$COMMAND" = "apt-get" ]; then
    apt-get install libsfml-dev
else
    echo "Invalid Argument given"
fi

