#ifndef PHYSX_HPP_INCLUDED
#define PHYSX_HPP_INCLUDED
#include "levels.hpp"

float friction = -0.4;
float velocityX = 0;
float velocityY = 0;
float accelerationX = 0;
float accelerationY = 0;
float gravity = 1.4;
int pressUpCount=0;

void updateMovement()
{
    if(y < ground){
        velocityY += gravity;
    }
    else if(y > ground){
        y = ground;
        pressUpCount = 0;
    }
    if(velocityX > 0 && y >= ground){
        velocityX -= 1;
    }
    else if(velocityX < 0 && y >= ground){
        velocityX += 1;
    }

    switch(level){
        case 1:
            updateGround1();
            break;
        case 2:
            updateGround2();
            break;
        case 3:
            updateGround3();
            break;
        case 4:
            updateGround4();
            break;
        default:
            break;
    }

    velocityX += accelerationX*friction;
    velocityY += accelerationY*friction;

    x += velocityX;
    y += velocityY;
}

#endif // PHYSX_HPP_INCLUDED
