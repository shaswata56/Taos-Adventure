#ifndef MENU_HPP_INCLUDED
#define MENU_HPP_INCLUDED
#include "../Header/scenes.hpp"
#include<SFML/Graphics.hpp>

void menu(RenderWindow &app) {

    CircleShape circle(100.0f);

    circle.setFillColor(Color::Red);

    app.draw(circle);

    if(Keyboard::isKeyPressed(Keyboard::Enter)) currentScene = gamePlay;

}

#endif // MENU_HPP_INCLUDED
