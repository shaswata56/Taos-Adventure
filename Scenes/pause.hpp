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
    if(paused){
        pauseScreenTexture.loadFromFile("../Resource/pause.png");
        pauseScreen.setTexture(pauseScreenTexture);
    }
    app.draw(pauseScreen);

    if(Keyboard::isKeyPressed(Keyboard::Enter)) currentScene = gamePlay;
}

#endif // PAUSE_HPP_INCLUDED
