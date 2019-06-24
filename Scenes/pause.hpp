#ifndef PAUSE_HPP_INCLUDED
#define PAUSE_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include "../Header/scenes.hpp"

using namespace std;
using namespace sf;

Texture pauseScreenTexture;
Sprite pauseScreen;
bool paused = true;


void pause(RenderWindow &app){
    app.clear(Color::White);
    if(paused){
        pauseScreenTexture.loadFromFile("Resource/pause.png");
        pauseScreen.setTexture(pauseScreenTexture);
    }
    ZeroView.setCenter(600, 400);
    ZeroView.setSize(Vector2f(1200, 800));
    app.setView(ZeroView);
    app.draw(pauseScreen);

    if(Keyboard::isKeyPressed(Keyboard::Enter)) 
	    currentScene = gamePlay;

    if(Mouse::isButtonPressed(Mouse::Left)) {
	Vector2i mousePos = Mouse::getPosition(app);
        if(mousePos.x>475 && mousePos.x<720 
	   && mousePos.y>345 && mousePos.y<450) 
		currentScene = gamePlay;
        if(mousePos.x>488 && mousePos.x<705 
	   && mousePos.y>533 && mousePos.y<625) 
		currentScene = mainMenu;

    }
}

#endif // PAUSE_HPP_INCLUDED
