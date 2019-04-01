#ifndef PAUSE_HPP_INCLUDED
#define PAUSE_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include "../Header/scenes.hpp"

using namespace std;
using namespace sf;

Texture pauseScreenTexture;
Sprite pauseScreen;
bool paused = true;


void pause(RenderWindow &app){
    app.clear(Color::White);
    if(paused){
        pauseScreenTexture.loadFromFile("Resource/pause.png");
        pauseScreen.setTexture(pauseScreenTexture);
    }
    ZeroView.setCenter(600, 400);
    ZeroView.setSize(Vector2f(1200, 800));
    app.setView(ZeroView);
    app.draw(pauseScreen);

    if(Keyboard::isKeyPressed(Keyboard::Enter)) currentScene = gamePlay;

    if(Mouse::isButtonPressed(Mouse::Left)){
        if(Mouse::getPosition().x>475 && Mouse::getPosition().x<720 && Mouse::getPosition().y>345 && Mouse::getPosition().y<450) currentScene = gamePlay;
        if(Mouse::getPosition().x>488 && Mouse::getPosition().x<705 && Mouse::getPosition().y>533 && Mouse::getPosition().y<625) currentScene = mainMenu;

    }
}

#endif // PAUSE_HPP_INCLUDED
