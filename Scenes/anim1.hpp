#ifndef ANIM1_HPP_INCLUDED
#define ANIM1_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include "../Header/scenes.hpp"
#include "../Header/physX.hpp"
using namespace std;
using namespace sf;

Sprite full, text;
Texture fullT, textT;
bool anim1started=true;
Clock anim1Clock;
float anim1TextX=600, anim1TextY=600;

void anim1(RenderWindow& app) {
    if(anim1started){
        fullT.loadFromFile("Resource/cutScenes/anim1/1.png");
        textT.loadFromFile("Resource/cutScenes/anim1/2.png");
        full.setTexture(fullT);
        text.setTexture(textT);
        anim1Clock.restart();
        full.setPosition(0,0);
        text.setPosition(anim1TextX,anim1TextY);
        anim1started=false;
    }
    if(anim1Clock.getElapsedTime().asMilliseconds()>1000){
        if(text.getPosition().x>0) {
            anim1TextX-=10;
            anim1TextY-=10;
        }
    }
    text.setPosition(anim1TextX,anim1TextY);
    if(anim1Clock.getElapsedTime().asMilliseconds() > 5000 || Keyboard::isKeyPressed(Keyboard::Escape)){
        level = 1;
        currentScene = gamePlay;
    }
    app.draw(full);
    app.draw(text);
}

#endif // ANIM1_HPP_INCLUDED
