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
    RenderWindow win(VideoMode(1920, 1080), "Tao's Adventure", Style::Fullscreen, settings);
    win.setVerticalSyncEnabled(true);
    while(win.isOpen())
    {
        while(win.pollEvent(ev))
        {
            switch(ev.type)
            {
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
