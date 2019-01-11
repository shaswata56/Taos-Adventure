#ifndef GAMEOVER_HPP_INCLUDED
#define GAMEOVER_HPP_INCLUDED
#include "../Header/scenes.hpp"
#include<SFML/Graphics.hpp>
#include<bits/stdc++.h>

using namespace sf;
using namespace std;

void game_over(RenderWindow &app,Text &endGameText){
    //printf("Shotti moira gechi....");

    /// SHOTTI MORE GELEO GAMEOVER TEXT SHOW KORTECHE NA JOKHON ENEMY ER SATHE BARI KHAIYA MORE
    /// CHECK KORIS TO PROBLEM KOI

    app.draw(endGameText);
    if(Keyboard::isKeyPressed(Keyboard::Backspace)) {
    	currentScene = mainMenu;
    }
}

#endif // GAMEOVER_HPP_INCLUDED
