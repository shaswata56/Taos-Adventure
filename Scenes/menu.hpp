#ifndef MENU_HPP_INCLUDED
#define MENU_HPP_INCLUDED

#include "../Header/scenes.hpp"
#include<SFML/Graphics.hpp>
#include<bits/stdc++.h>

using namespace sf;
using namespace std;

void menu(RenderWindow &app,Text &startGameText){
    app.draw(startGameText);
    if(Keyboard::isKeyPressed(Keyboard::Enter)) currentScene = gamePlay;
}

#endif // MENU_HPP_INCLUDED
