#ifndef ENEMY_HPP_INCLUDED
#define ENEMY_HPP_INCLUDED
#include<bits/stdc++.h>
#include<SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Enemy{
private:
    Texture enemmyTexture;
    Sprite enemySprite;
    float moveSpeed=3;
    bool alive = true;
public:
    string enemyLoc = "Resource/Levels/co/enemy.png";
    bool directionOfEnemy;
    float startPoint=-100.0f, endPoint=-100.0f, height=-100.0f;
    void initEnemy(float startP, float endP, float heightP){
        enemmyTexture.loadFromFile(enemyLoc);
        enemySprite.setTexture(enemmyTexture);
        enemySprite.scale(.1,.1);
        startPoint=startP;
        endPoint=endP;
        height=heightP;
        enemySprite.setPosition(startPoint, height);
    }
    void updateEnemy(){
        if(alive){
            float enemyX = enemySprite.getPosition().x;
            if(directionOfEnemy) {
                enemySprite.move(moveSpeed,0);
                if(enemyX>=endPoint){
                    directionOfEnemy = false;
                }
            }
            else {
                enemySprite.move(moveSpeed*(-1),0);
                if(enemyX<=startPoint){
                    directionOfEnemy=true;
                }
            }
        }
        else enemySprite.setPosition(-200,-200);
    }
    void drawEnemy(RenderWindow& window){
        if(alive) window.draw(enemySprite);
    }
    FloatRect getRect(){
        return enemySprite.getGlobalBounds();
    }
    void dead() {
        alive = false;
    }
};

#endif // ENEMY_HPP_INCLUDED
