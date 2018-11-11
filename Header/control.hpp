#ifndef CONTROL_H_INCLUDED
#define CONTROL_H_INCLUDED
#include "../Header/tao.hpp"

int s =15;

void user_interact(Tao &tao)
{
    if(Keyboard::isKeyPressed(Keyboard::Left) && y >= ground){
        tao.RolnRun(-s);
    }
    else if(Keyboard::isKeyPressed(Keyboard::Right) && y >= ground){
        tao.RolnRun(s);
    }
    if(Keyboard::isKeyPressed(Keyboard::Up) && pressUpCount == 0){
            ++pressUpCount;
            tao.kick();
            if(pressUpCount==1) velocityY = -30;
    }
    if(velocityX != 0){
            tao.roll(velocityX);
    }
}

#endif // CONTROL_H_INCLUDED
