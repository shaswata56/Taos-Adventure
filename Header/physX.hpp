#ifndef PHYSX_HPP_INCLUDED
#define PHYSX_HPP_INCLUDED
#include"levels.hpp"

float friction = -0.4;
float velocityX = 0;
float velocityY = 0;
float accelerationX = 0;
float accelerationY = 0;
float gravity = 1.9;
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

    updateGround();

    velocityX += accelerationX*friction;
    velocityY += accelerationY*friction;

    x += velocityX;
    y += velocityY;
}

#endif // PHYSX_HPP_INCLUDED
