/*

READ IT FIRST
==============
To add enemy in levels, you have to first declare Enemies..
But it won't work, until you call *initEnemy* function for all of the enemies with the parameters
of the floats starting point, ending point and a height..
The enemy will roam around from the starting point to the ending point in the given height..

*/


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
public:
    string enemyLoc = "Resource/Levels/co/enemy.png";
    bool directionOfEnemy;
    float startPoint=-100.0f, endPoint=-100.0f, height=-100.0f;
    void initEnemy(float startP, float endP, float heightP){
        enemmyTexture.loadFromFile(enemyLoc);
        enemySprite.setTexture(enemmyTexture);
        enemySprite.scale(.1,.1);
        this->startPoint=startP;
        this->endPoint=endP;
        this->height=heightP;
        enemySprite.setPosition(startPoint, height);
    }
    void updateEnemy(){
        float enemyX = enemySprite.getPosition().x;
        if(this->directionOfEnemy) {
            enemySprite.move(5,0);
            if(enemyX>=this->endPoint){
                this->directionOfEnemy = false;
            }
        }
        else {
            enemySprite.move(-5,0);
            if(enemyX<=this->startPoint){
                this->directionOfEnemy=true;
            }
        }
    }
    void drawEnemy(RenderWindow& window){
        window.draw(enemySprite);
    }
};

#endif // ENEMY_HPP_INCLUDED
