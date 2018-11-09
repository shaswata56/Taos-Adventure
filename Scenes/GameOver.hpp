#ifndef GAMEOVER_HPP_INCLUDED
#define GAMEOVER_HPP_INCLUDED
#include "../Header/scenes.hpp"
#include<SFML/Graphics.hpp>
#include<bits/stdc++.h>

using namespace sf;
using namespace std;

void game_over(RenderWindow &app) {
    Font AmaticB;
    AmaticB.loadFromFile("Resource/Fonts/Amatic-Bold.ttf");
    Text endGameText("Game Over", AmaticB, 50);
    endGameText.setOrigin(endGameText.getLocalBounds().width/2, endGameText.getLocalBounds().height/2);
    endGameText.setPosition(600, 400);
    endGameText.setFillColor(Color::Red);
    app.draw(endGameText);
    if(Keyboard::isKeyPressed(Keyboard::Backspace)) currentScene = mainMenu;
}

#endif // GAMEOVER_HPP_INCLUDED
