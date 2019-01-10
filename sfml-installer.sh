#!/bin/bash

echo Installing SFML library for your distribution...
echo Entering privileged mode...

if [ $(command -v apt) ]
then
	exec sudo apt install libsfml-dev
fi
if [ $(command -v dnf) ]
then
	exec sudo dnf install sfml
fi
if [ $(command -v rpm) ]
then
	exec sudo rpm install sfml
fi
if [ $(command -v pacman) ]
then
	exec sudo pacman -S sfml
else
	echo "Sorry!!!"
	echo "Your distribution is not supported!!!"
fi

