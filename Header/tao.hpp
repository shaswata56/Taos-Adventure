#ifndef TAO_HPP_INCLUDED
#define TAO_HPP_INCLUDED
#include<bits/stdc++.h>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include "../Header/physX.hpp"
using namespace std;
using namespace sf;

class Tao{
private:
    float val;
    Texture taoTex;
    Sprite sTao;
    SoundBuffer kicksb;
    Sound kickwav;

public:
    void LoadTao(string s){
        taoTex.loadFromFile(s);
        taoTex.setSmooth(true);
        sTao.setTexture(taoTex);
        FloatRect taoBound = sTao.getLocalBounds();
        sTao.setOrigin(taoBound.width/2,taoBound.height/2);
        kicksb.loadFromFile("Resource/Levels/co/kick.wav");
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
    void kick(){
        kickwav.setBuffer(kicksb);
        kickwav.play();
    }
    Vector2f getpos(){
        return sTao.getPosition();
    }
    FloatRect getRect(){
        return sTao.getGlobalBounds();
    }
};

#endif // TAO_HPP_INCLUDED
