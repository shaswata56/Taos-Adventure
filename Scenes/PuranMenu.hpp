#ifndef MENU_HPP_INCLUDED
#define MENU_HPP_INCLUDED

#include "../Header/scenes.hpp"
#include<SFML/Graphics.hpp>
#include<bits/stdc++.h>

using namespace sf;
using namespace std;

unsigned int menuSelection = 0;

    Clock menuClock;

void menu(RenderWindow &app){
    Font AmaticB;
    AmaticB.loadFromFile("Resource/Fonts/Amatic-Bold.ttf");

    Text startGameText("StartGame", AmaticB, 60);
    Text storyLineText("Storyline", AmaticB, 60);
    Text addedLaterText("What\'ll be added later?", AmaticB, 60);
    Text exitText("Exit", AmaticB, 60);

    startGameText.setOrigin(startGameText.getLocalBounds().width/2, startGameText.getLocalBounds().height/2);
    storyLineText.setOrigin(storyLineText.getLocalBounds().width/2, storyLineText.getLocalBounds().height/2);
    addedLaterText.setOrigin(addedLaterText.getLocalBounds().width/2, addedLaterText.getLocalBounds().height/2);
    exitText.setOrigin(exitText.getLocalBounds().width/2, exitText.getLocalBounds().height/2);

    startGameText.setPosition(app.getSize().x/2, 150);
    storyLineText.setPosition(app.getSize().x/2, 300);
    addedLaterText.setPosition(app.getSize().x/2, 450);
    exitText.setPosition(app.getSize().x/2, 600);

    startGameText.setFillColor(Color::Yellow);
    storyLineText.setFillColor(Color::Yellow);
    addedLaterText.setFillColor(Color::Yellow);
    exitText.setFillColor(Color::Yellow);

    switch(menuSelection){
        case 0:
            startGameText.setFillColor(Color::Red);
            break;
        case 1:
            storyLineText.setFillColor(Color::Red);
            break;
        case 2:
            addedLaterText.setFillColor(Color::Red);
            break;
        case 3:
            exitText.setFillColor(Color::Red);
            break;
    }

    if(Keyboard::isKeyPressed(Keyboard::Up) && menuClock.getElapsedTime().asMilliseconds()>100) {
        if(menuSelection>0)
            menuSelection--;
        else
            menuSelection = 3;
        menuClock.restart();
    }
    if(Keyboard::isKeyPressed(Keyboard::Down) && menuClock.getElapsedTime().asMilliseconds()>100) {
        if(menuSelection<3)
            menuSelection++;
        else
            menuSelection = 0;
        menuClock.restart();
    }

    if(Keyboard::isKeyPressed(Keyboard::Enter)) {
        switch(menuSelection) {
        case 0:
            currentScene = startingAnime;
            break;
        case 1:
            currentScene = storyLine;
            break;
        case 2:
            currentScene = addedLater;
            break;
        case 3:
            app.close();
            break;
        }
    }
    app.draw(startGameText);
    app.draw(storyLineText);
    app.draw(addedLaterText);
    app.draw(exitText);
}

#endif // MENU_HPP_INCLUDED
