#ifndef CREDITS_HPP_INCLUDED
#define CREDITS_HPP_INCLUDED

#include "../Header/scenes.hpp"
#include <SFML/Graphics.hpp>
using namespace sf;
Texture creditTexture;
Sprite creditSprite;
bool creditStarted = true;

void credit(RenderWindow &app){
    app.clear();
    if(creditStarted){
        creditTexture.loadFromFile("Resource/credit.png");
        creditSprite.setTexture(creditTexture);
        creditStarted = false;
    }
    app.draw(creditSprite);

    if(Keyboard::isKeyPressed(Keyboard::Backspace)) {
        currentScene = mainMenu;
        creditStarted = true;
    }
}


#endif // CREDITS_HPP_INCLUDED
