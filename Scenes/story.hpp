#ifndef STORY_HPP_INCLUDED
#define STORY_HPP_INCLUDED

#include "../Header/scenes.hpp"
#include<SFML/Graphics.hpp>

using namespace sf;

void story(RenderWindow &app){

    Font AmaticB;
    AmaticB.loadFromFile("Resource/Fonts/Amatic-Bold.ttf");

    Text storyText("Tao, a happy ball from the Ballworld, was living happily with his family.\nBut, one day, a disaster happened in his life. Some bad squares from the\nSquareworld came to his village and kidnapped his whole family and hid them\non various places in Squareworld. Tao somehow saved himself from the kidnappers.\nNow, he wants to go to the Squareworld and find his family. By getting help from\none of his friends, he managed to go there. And started searching his family members.\nNow, Tao needs your help to find them.", AmaticB, 50);
    Text returnText("Press Backspace to go back to menu!", AmaticB, 30);
    storyText.setOrigin(storyText.getLocalBounds().width/2, storyText.getLocalBounds().height/2);
    returnText.setOrigin(returnText.getLocalBounds().width/2, returnText.getLocalBounds().height/2);

    storyText.setPosition(app.getSize().x/2, app.getSize().y/2);
    returnText.setPosition(app.getSize().x/2, app.getSize().y-100);

    storyText.setFillColor(Color::Green);
    returnText.setFillColor(Color::Green);

    if(Keyboard::isKeyPressed(Keyboard::BackSpace))
        currentScene = mainMenu;

    app.draw(storyText);
    app.draw(returnText);
}

#endif // STORY_HPP_INCLUDED
