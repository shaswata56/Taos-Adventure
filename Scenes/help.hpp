#ifndef HELP_HPP_INCLUDED
#define HELP_HPP_INCLUDED

#include "../Header/scenes.hpp"
#include <SFML/Graphics.hpp>
using namespace sf;
Texture helpTexture;
Sprite helpSprite;
bool helpStarted = true;

void help(RenderWindow &app){
    app.clear();
    if(helpStarted){
        helpTexture.loadFromFile("Resource/help.png");
        helpSprite.setTexture(helpTexture);
        helpStarted = false;
    }
    app.draw(helpSprite);

    if(Keyboard::isKeyPressed(Keyboard::Backspace)) {
        currentScene = mainMenu;
        helpStarted = true;
    }
}

#endif // HELP_HPP_INCLUDED
