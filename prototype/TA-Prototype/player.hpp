#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED

#include<SFML/Graphics.hpp>

using namespace sf;

class Player{
public:
    Player(float size){
        playerRectangle.setRadius(size);
        playerRectangle.setFillColor(Color::Red);
    }

    void drawTo(RenderWindow& win){
        win.draw(playerRectangle);
    }

    void move(Vector2f distance){
        playerRectangle.move(distance);
    }

    void setPos(Vector2f newPos){
        playerRectangle.setPosition(newPos);
    }

    bool onGround(float ground){
        return playerRectangle.getPosition().y==ground;
    }

    float getY(){
        return playerRectangle.getPosition().y;
    }
    float getX(){
        return playerRectangle.getPosition().x;
    }

private:
    CircleShape playerRectangle;
};

#endif // PLAYER_HPP_INCLUDED
