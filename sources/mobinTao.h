#ifndef MOBINTAO_H_INCLUDED
#define MOBINTAO_H_INCLUDED

#include<SFML/Graphics.hpp>

using namespace sf;

class Tao{
public:
    Tao(float size){
        taoCircle.setRadius(size);
        taoCircle.setFillColor(Color::Red);
    }

    void drawTo(RenderWindow& win){
        win.draw(taoCircle);
    }

    void move(Vector2f distance){
        taoCircle.move(distance);

    }

    void setPos(Vector2f newPos){
        taoCircle.setPosition(newPos);
    }

    bool onGround(float ground){
        return taoCircle.getPosition().y==ground;
    }

    float getY(){
        return taoCircle.getPosition().y;
    }
    float getX(){
        return taoCircle.getPosition().x;
    }

private:
    CircleShape taoCircle;
};

#endif // MOBINTAO_HPP_INCLUDED
