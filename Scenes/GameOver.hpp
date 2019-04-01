#ifndef GAMEOVER_HPP_INCLUDED
#define GAMEOVER_HPP_INCLUDED
#include "../Header/scenes.hpp"
#include<SFML/Graphics.hpp>
#include<bits/stdc++.h>

using namespace sf;
using namespace std;

void game_over(RenderWindow &app,Text &endGameText){
    app.clear();
    app.draw(endGameText);
    if(Keyboard::isKeyPressed(Keyboard::Backspace)) {
    	currentScene = mainMenu;
    }
}

#endif // GAMEOVER_HPP_INCLUDED
