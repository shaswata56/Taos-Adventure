#ifndef MOBINGAME_H_INCLUDED
#define MOBINGAME_H_INCLUDED

#include<iostream>
#include<SFML/Graphics.hpp>
#include "mobinTao.h"

using namespace std;
using namespace sf;

Event ev;
Tao taoChar({20});

void game(){
    RenderWindow win(VideoMode(600, 600), "Tao's Adventure");
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
        taoChar.drawTo(win);
        win.display();
    }
}

#endif // MOBINGAME_H_INCLUDED
