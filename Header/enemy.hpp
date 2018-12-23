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
    float moveSpeed=3;
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
    void drawEnemy(RenderWindow& window){
        window.draw(enemySprite);
    }
    FloatRect getRect(){
        return enemySprite.getGlobalBounds();
    }
};

#endif // ENEMY_HPP_INCLUDED
