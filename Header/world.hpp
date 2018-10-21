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
public:
    void LoadFG(string s){
        fg.loadFromFile(s);
        sFG.setTexture(fg);
        sFG.setPosition(0,195);
    }
    void LoadBG(string s){
        bg.loadFromFile(s);
        sBG.setTexture(bg);
    }
    void drawTo(RenderWindow& win){
        win.draw(sBG);
        win.draw(sFG);
    }
};

#endif // WORLD_HPP_INCLUDED
