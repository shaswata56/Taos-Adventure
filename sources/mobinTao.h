#ifndef MOBINTAO_H_INCLUDED
#define MOBINTAO_H_INCLUDED
#include<SFML/Graphics.hpp>

using namespace sf;

class Tao{
private:
    Texture taoTexture;
    Sprite taoSprite;

    void taoInclude(){
        taoTexture.loadFromFile("resources/tao/Ten 13.png");
        taoSprite.setTexture(taoTexture);
        taoSprite.setScale(0.5, 0.5);
    }

public:
    float rotataion=0;
    Tao(){
        taoInclude();
        taoSprite.setOrigin(256, 256);
    }

    void drawTo(RenderWindow& win){
        win.draw(taoSprite);
    }

    void move(Vector2f distance){
        taoSprite.move(distance);
        taoSprite.rotate(rotataion);
    }

    void setPos(Vector2f newPos){
        taoSprite.setPosition(newPos);
    }

    bool onGround(float ground){
        return taoSprite.getPosition().y==ground;
    }

    float getY(){
        return taoSprite.getPosition().y;
    }
    float getX(){
        return taoSprite.getPosition().x;
    }
};

#endif // MOBINTAO_HPP_INCLUDED
