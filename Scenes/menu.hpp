#ifndef MENU_HPP_INCLUDED
#define MENU_HPP_INCLUDED

#include "../Header/scenes.hpp"
#include<SFML/Graphics.hpp>
#include<bits/stdc++.h>

using namespace sf;
using namespace std;

bool menuStarted=true;

Texture backgroundTexture, normalTexture, soundOffTexture, musicOffTexture;
Sprite backgroundSprite, backgroundSprite2, normalSprite, soundOffSprrite, musicOffSprite;

void menu(RenderWindow &app){
    backgroundTexture.loadFromFile("Resource/Menu/BG.png");
    normalTexture.loadFromFile("Resource/Menu/normal.png");
    soundOffTexture.loadFromFile("Resource/Menu/soundOff.png");
    musicOffTexture.loadFromFile("Resource/Menu/musicOff.png");
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite2.setTexture(backgroundTexture);
    normalSprite.setTexture(normalTexture);
    soundOffSprrite.setTexture(soundOffTexture);
    musicOffSprite.setTexture(musicOffTexture);

    if(menuStarted){
        backgroundSprite.setPosition(0,0);
        backgroundSprite2.setPosition(1198, 0);
        menuStarted = false;
    }

    backgroundSprite.move(-5, 0);
    backgroundSprite2.move(-5, 0);
    if(backgroundSprite.getPosition().x<-1198) backgroundSprite.setPosition(1198, 0);
    if(backgroundSprite2.getPosition().x<-1198) backgroundSprite2.setPosition(1198, 0);

    app.draw(backgroundSprite);
    app.draw(backgroundSprite2);
    app.draw(normalSprite);
}

#endif // MENU_HPP_INCLUDED
