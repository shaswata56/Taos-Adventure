#ifndef MENU_HPP_INCLUDED
#define MENU_HPP_INCLUDED

#include "../Header/scenes.hpp"
#include<SFML/Graphics.hpp>
#include<bits/stdc++.h>

using namespace sf;
using namespace std;

void menu(RenderWindow &app) {
    Font AmaticB;
    AmaticB.loadFromFile("Resource/Fonts/Amatic-Bold.ttf");
    Text startGameText("Press Enter To Start Game", AmaticB, 40);
    startGameText.setOrigin(startGameText.getLocalBounds().width/2, startGameText.getLocalBounds().height/2);
    startGameText.setPosition(600, 400);
    startGameText.setFillColor(Color::Yellow);
    app.draw(startGameText);
    if(Keyboard::isKeyPressed(Keyboard::Enter)) currentScene = gamePlay;
}

#endif // MENU_HPP_INCLUDED
