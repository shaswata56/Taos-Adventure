#ifndef WORLD_HPP_INCLUDED
#define WORLD_HPP_INCLUDED
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include "physX.hpp"
using namespace std;
using namespace sf;

class World{
private:
    Texture fg, bg;
    Sprite sFG, sBG;
    SoundBuffer bgbuff;
    Sound   bgfx;
    
public:
    void LoadFG(string s){
        fg.loadFromFile(s);
        fg.setSmooth(true);
        sFG.setTexture(fg);
    }
    void PosFG(int w){
        sFG.setPosition(0, w);
    }
    void LoadBG(string s){
        bg.loadFromFile(s);
        bg.setSmooth(true);
        sBG.setTexture(bg);
    }
    void LoadSFX(string s){
        bgbuff.loadFromFile(s);
        bgfx.setBuffer(bgbuff);
        bgfx.setLoop(true);
    }
    void PlaySFX(){
        bgfx.play();
    }
    void StopSFX(){
        bgfx.stop();
    }
    void drawTo(RenderWindow& win){
        win.draw(sBG);
        win.draw(sFG);
    }
};

#endif // WORLD_HPP_INCLUDED
