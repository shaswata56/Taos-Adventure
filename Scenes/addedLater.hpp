#ifndef ADDEDLATER_HPP_INCLUDED
#define ADDEDLATER_HPP_INCLUDED

#include "../Header/scenes.hpp"
#include<SFML/Graphics.hpp>

using namespace sf;

void addLater(RenderWindow &app){
    int i;
    Font AmaticB;
    AmaticB.loadFromFile("Resource/Fonts/Amatic-Bold.ttf");

    Text addedLaterTexts[5];

    addedLaterTexts[0].setString("More Levels Will Be Added");
    addedLaterTexts[1].setString("Enemies Will Be Added");
    addedLaterTexts[2].setString("Story Based Cutscenes Will Be Added");
    addedLaterTexts[3].setString("More Animations Will Be Added");
    addedLaterTexts[4].setString("Some Bugs Will Be Fixed");

    for(i=0; i<5; i++) {
        addedLaterTexts[i].setFont(AmaticB);
        addedLaterTexts[i].setCharacterSize(40);
        addedLaterTexts[i].setOrigin(addedLaterTexts[i].getLocalBounds().width/2, addedLaterTexts[i].getLocalBounds().height/2);
        addedLaterTexts[i].setFillColor(Color::Magenta);
        addedLaterTexts[i].setPosition(app.getSize().x/2, 160+i*80);
    }

    if(Keyboard::isKeyPressed(Keyboard::BackSpace))
        currentScene = mainMenu;

    for(i=0; i<5; i++) app.draw(addedLaterTexts[i]);
}

#endif // ADDEDLATER_HPP_INCLUDED
