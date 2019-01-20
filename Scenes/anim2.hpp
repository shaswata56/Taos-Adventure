#ifndef ANIM2_HPP_INCLUDED
#define ANIM2_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include "../Header/scenes.hpp"
#include "../Header/physX.hpp"
using namespace std;
using namespace sf;

Sprite Sfull, Stext, sp;
Texture Tfull, Ttext, t;
Texture text1, text2, text3, text4;
bool anim2started=true;
Clock anim2Clock;
float anim2TextX=600, anim2TextY=600;

void anim2(RenderWindow& app) {
    if(anim2started){
        world1.StopSFX();
        world2.StopSFX();
        world4.StopSFX();
        Tfull.loadFromFile("Resource/cutScenes/anim2/bg.png");
        t.loadFromFile("Resource/test.png");
        text1.loadFromFile("Resource/cutScenes/anim2/1.png");
        text2.loadFromFile("Resource/cutScenes/anim2/2.png");
        text3.loadFromFile("Resource/cutScenes/anim2/3.png");
        text4.loadFromFile("Resource/cutScenes/anim2/4.png");
        Sfull.setTexture(Tfull);
        Stext.setTexture(text1);
        anim2Clock.restart();
        Sfull.setPosition(1786,0);
        Stext.setPosition(1200 + anim2TextX,anim2TextY - 600);
        anim2started=false;
    }
    
    if(anim2Clock.getElapsedTime().asMilliseconds()>2000) Stext.setTexture(text2);
    if(anim2Clock.getElapsedTime().asMilliseconds()>4000) Stext.setTexture(text3);
    if(anim2Clock.getElapsedTime().asMilliseconds()>6000) Stext.setTexture(text4);
    if(anim2Clock.getElapsedTime().asMilliseconds() > 8000 || Keyboard::isKeyPressed(Keyboard::Escape)){
        level = 2;
        anim2started=true;
        currentScene = gamePlay;
    }
    
    app.clear(Color::White);
    app.draw(Sfull);
    app.draw(Stext);
}

#endif // ANIM2_HPP_INCLUDED
