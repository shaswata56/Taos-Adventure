#ifndef ANIM2_HPP_INCLUDED
#define ANIM2_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include "../Header/scenes.hpp"
#include "../Header/physX.hpp"
using namespace std;
using namespace sf;

Sprite fullA2, textA2;
Texture text1, text2, text3, text4, fullT2;
bool anim2started=true;
Clock anim2Clock;

void anim2(RenderWindow& app) {
    app.clear();
    if(anim2started){
        fullT2.loadFromFile("Resource/cutScenes/anim2/bg.png");
        text1.loadFromFile("Resource/cutScenes/anim2/1.png");
        text2.loadFromFile("Resource/cutScenes/anim2/2.png");
        text3.loadFromFile("Resource/cutScenes/anim2/3.png");
        text4.loadFromFile("Resource/cutScenes/anim2/4.png");
        fullA2.setTexture(fullT);
        textA2.setTexture(text1);
        anim2Clock.restart();
        fullA2.setPosition(0,0);
        textA2.setPosition(0,0);
        anim2started=false;
    }
    if(anim2Clock.getElapsedTime().asMilliseconds()>2000) textA2.setTexture(text2);
    if(anim2Clock.getElapsedTime().asMilliseconds()>4000) textA2.setTexture(text3);
    if(anim2Clock.getElapsedTime().asMilliseconds()>6000) textA2.setTexture(text4);
    if(anim2Clock.getElapsedTime().asMilliseconds() > 8000 || Keyboard::isKeyPressed(Keyboard::Escape)){
        level = 2;
        currentScene = gamePlay;
    }
    app.draw(fullA2);
    app.draw(textA2);
}

#endif // ANIM2_HPP_INCLUDED
