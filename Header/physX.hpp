#ifndef PHYSX_HPP_INCLUDED
#define PHYSX_HPP_INCLUDED

float friction = -0.4;
float x = 200;
float y = 200;
float velocityX = 0;
float velocityY = 0;
float accelerationX = 0;
float accelerationY = 0;
float gravity = 1.5;
int pressUpCount=0;
int ground = 564;
int water = 760;
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
    if(x > 0 && x <= 500) ground = 564;
    if(x>509 && x < 835) ground = water;
    if(x >= 835 && x <= 1349 ) ground = 470;
    if(x > 1349 && x < 1505) ground = water;
    if(x >= 1505 && x <= 1900) ground = 143+142;
    if(x > 1900 && x < 1935) ground = water;
    if(x >= 1935 && x <= 2320) ground = 143+336;
    if(x > 2320 && x <= 3010) ground = 143+433;

    velocityX += accelerationX*friction;
    velocityY += accelerationY*friction;

    x += velocityX;
    y += velocityY;
}

#endif // PHYSX_HPP_INCLUDED
