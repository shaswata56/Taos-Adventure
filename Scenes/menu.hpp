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
SoundBuffer mainbuff;
Sound mainbg;

Clock menuButtonClock;
bool musicOn=true, soundOn=true;

void menu(RenderWindow &app){
    app.clear();
    if(menuStarted){
        backgroundTexture.loadFromFile("Resource/Menu/BG.png");
        normalTexture.loadFromFile("Resource/Menu/normal.png");
        soundOffTexture.loadFromFile("Resource/Menu/soundOff.png");
        musicOffTexture.loadFromFile("Resource/Menu/musicOff.png");
        mainbuff.loadFromFile("Resource/Menu/joy_bangla.ogg");
        mainbg.setBuffer(mainbuff);
        mainbg.setLoop(true);
        backgroundSprite.setTexture(backgroundTexture);
        backgroundSprite2.setTexture(backgroundTexture);
        normalSprite.setTexture(normalTexture);
        soundOffSprrite.setTexture(soundOffTexture);
        musicOffSprite.setTexture(musicOffTexture);
        backgroundSprite.setPosition(0,0);
        backgroundSprite2.setPosition(1200, 0);
        menuStarted = false;
        //mainbg.play();
    }
    //  Mouse pointer location viewer
    string str;
    str.append(to_string(Mouse::getPosition(app).x));
    str.append(",");
    str.append(to_string(Mouse::getPosition(app).y));
    app.setTitle(str);


    if(Mouse::isButtonPressed(Mouse::Left)){
        Vector2i mousePosition = Mouse::getPosition(app);
        if(mousePosition.x >= 545 && mousePosition.x <= 690 && mousePosition.y >= 400 && mousePosition.y <= 550)
        {
            currentScene = startingAnime;
        }
        if(mousePosition.y >= 605 && mousePosition.y <= 710){
            if(mousePosition.x >= 435 && mousePosition.x <= 540 && menuButtonClock.getElapsedTime().asMilliseconds()>500){
                if(musicOn){
                    musicOn = !musicOn;
                    mainbg.pause();
                }
                else{
                    musicOn = !musicOn;
                    mainbg.play();
                }
                menuButtonClock.restart();
            }
            if(mousePosition.x >= 650 && mousePosition.x <= 745 && menuButtonClock.getElapsedTime().asMilliseconds()>500){
                soundOn = !soundOn;
                menuButtonClock.restart();
            }
            if(mousePosition.x >= 240 && mousePosition.x <= 340) {
                currentScene = helpPage;
            }
            if(mousePosition.x >= 855 && mousePosition.x <= 960) {
                currentScene = creditPage;
            }
        }
        if(mousePosition.x >= 1076 && mousePosition.x <= 1169 && mousePosition.y >= 30 && mousePosition.y <= 121)
            app.close();
    }

    if(Keyboard::isKeyPressed(Keyboard::Enter)){
        currentScene = startingAnime;
    }

    backgroundSprite.move(-2, 0);
    backgroundSprite2.move(-2, 0);
    if(backgroundSprite.getPosition().x<-1200) backgroundSprite.setPosition(1200, 0);
    if(backgroundSprite2.getPosition().x<-1200) backgroundSprite2.setPosition(1200, 0);
    app.draw(backgroundSprite);
    app.draw(backgroundSprite2);
    app.draw(normalSprite);
    if(!musicOn) app.draw(musicOffSprite);
    if(!soundOn) app.draw(soundOffSprrite);
}

#endif // MENU_HPP_INCLUDED
