#ifndef MOBINGAME_H_INCLUDED
#define MOBINGAME_H_INCLUDED
#include "mobinTao.h"

using namespace std;
using namespace sf;

Event ev;
Tao taoChar;

void game()
{
    ContextSettings settings;
    settings.antialiasingLevel = 8;
    taoChar.setPos({256, 256});
//<<<<<<< HEAD
    RenderWindow win(VideoMode(1066, 668), "Tao's Adventure");
    win.setFramerateLimit(30);
    while(win.isOpen()){
        while(win.pollEvent(ev)){
            switch(ev.type){/*
=======
    RenderWindow win(VideoMode(1920, 1080), "Tao's Adventure", Style::Fullscreen, settings);
    win.setVerticalSyncEnabled(true);
    while(win.isOpen())
    {
        while(win.pollEvent(ev))
        {
            switch(ev.type)
            {
>>>>>>> dca0480332ab0400424a6b255d89bfb14cf09bf4*/
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
    win.close();
}

#endif // MOBINGAME_H_INCLUDED
