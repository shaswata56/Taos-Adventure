#ifndef ANIM2_HPP_INCLUDED
#define ANIM2_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include "../Header/scenes.hpp"
#include "../Header/physX.hpp"
using namespace std;
using namespace sf;

Texture text1, text2, text3, text4;
bool anim2started=true;
Clock anim2Clock;
float anim2TextX=600, anim2TextY=600;

void anim2(RenderWindow& app) {
    if(anim2started){
        fullT.loadFromFile("Resource/cutScenes/anim2/bg.png");
        text1.loadFromFile("Resource/cutScenes/anim2/1.png");
        text2.loadFromFile("Resource/cutScenes/anim2/2.png");
        text3.loadFromFile("Resource/cutScenes/anim2/3.png");
        text4.loadFromFile("Resource/cutScenes/anim2/4.png");
        full.setTexture(fullT);
        text.setTexture(text1);
        anim2Clock.restart();
        full.setPosition(0,0);
        text.setPosition(anim2TextX,anim2TextY);
        anim2started=false;
    }
    if(anim2Clock.getElapsedTime().asMilliseconds()>2000) text.setTexture(text2);
    if(anim2Clock.getElapsedTime().asMilliseconds()>4000) text.setTexture(text3);
    if(anim2Clock.getElapsedTime().asMilliseconds()>6000) text.setTexture(text4);
    if(anim2Clock.getElapsedTime().asMilliseconds() > 8000 || Keyboard::isKeyPressed(Keyboard::Escape)){
        level = 2;
        currentScene = gamePlay;
    }
    app.draw(full);
    app.draw(text);
}

#endif // ANIM2_HPP_INCLUDED
