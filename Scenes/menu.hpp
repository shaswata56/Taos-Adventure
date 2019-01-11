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

Clock frameRateChecker;

void menu(RenderWindow &app){

    if(menuStarted){
        backgroundTexture.loadFromFile("Resource/Menu/BG.png");
        normalTexture.loadFromFile("Resource/Menu/normal.png");
        soundOffTexture.loadFromFile("Resource/Menu/soundOff.png");
        musicOffTexture.loadFromFile("Resource/Menu/musicOff.png");
        backgroundSprite.setTexture(backgroundTexture);
        backgroundSprite2.setTexture(backgroundTexture);
        normalSprite.setTexture(normalTexture);
        soundOffSprrite.setTexture(soundOffTexture);
        musicOffSprite.setTexture(musicOffTexture);
        backgroundSprite.setPosition(0,0);
        backgroundSprite2.setPosition(1200, 0);
        menuStarted = false;
    }

    if(Mouse::isButtonPressed(Mouse::Left)){
        Vector2i mousePosition = Mouse::getPosition(app);
        if(mousePosition.x >= 545 && mousePosition.x <= 690 && mousePosition.y >= 400 && mousePosition.y <= 550)
        {
            currentScene = startingAnime;
        }
    }

    backgroundSprite.move(-2, 0);
    backgroundSprite2.move(-2, 0);
    if(backgroundSprite.getPosition().x<-1200) backgroundSprite.setPosition(1200, 0);
    if(backgroundSprite2.getPosition().x<-1200) backgroundSprite2.setPosition(1200, 0);

    app.draw(backgroundSprite);
    app.draw(backgroundSprite2);
    app.draw(normalSprite);
}

#endif // MENU_HPP_INCLUDED
