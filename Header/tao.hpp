#ifndef TAO_HPP_INCLUDED
#define TAO_HPP_INCLUDED
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include "physX.hpp"
using namespace std;
using namespace sf;

class Tao{
private:
    float val;
    Texture taoTex;
    Sprite sTao;
public:
    void LoadTao(string s){
        taoTex.loadFromFile(s);
        taoTex.setSmooth(true);
        sTao.setTexture(taoTex);
        sTao.setScale(0.1,0.1);
        FloatRect taoBound = sTao.getLocalBounds();
        sTao.setOrigin(taoBound.width/2,taoBound.height/2);
    }
    void drawTo(RenderWindow& win){
        win.draw(sTao);
    }
    void setPos(float x, float y){
        sTao.setPosition(x, y);
    }
    void RolnRun(float val){
        velocityX = val;
    }
    void roll(float val){
        sTao.rotate(val);
    }
};

#endif // TAO_HPP_INCLUDED
