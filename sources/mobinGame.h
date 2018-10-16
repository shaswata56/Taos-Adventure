#ifndef MOBINGAME_H_INCLUDED
#define MOBINGAME_H_INCLUDED

#include<iostream>
#include<SFML/Graphics.hpp>
#include "mobinTao.h"

using namespace std;
using namespace sf;

Event ev;
Tao taoChar;

void game(){
    taoChar.setPos({256, 256});
    RenderWindow win(VideoMode(1066, 668), "Tao's Adventure");
    win.setFramerateLimit(30);
    while(win.isOpen()){
        while(win.pollEvent(ev)){
            switch(ev.type){
            case Event::Closed:
                win.close();
                break;
            default:
                break;
            }
        }
        win.clear();
        if(taoChar.rotataion<5) taoChar.rotataion++;
        taoChar.move({0, 0});
        taoChar.drawTo(win);
        win.display();
    }
}

#endif // MOBINGAME_H_INCLUDED
