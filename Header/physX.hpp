#ifndef PHYSX_HPP_INCLUDED
#define PHYSX_HPP_INCLUDED

float friction = -0.4;
float x = 200;
float y = 200;
float velocityX = 0;
float velocityY = 0;
float accelerationX = 0;
float accelerationY = 0;
float gravity = 1.9;
int pressUpCount=0;
int ground = 564;
int water = 760;
int level = 1;
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

    if(level == 1){
        if(x > 0 && x <= 500 && y <= 564) ground = 564;
        else if(x >= 835 && x <= 1349 && y <= 470) ground = 470;
        else if(x >= 1505 && x <= 1900 && y <= 143+142) ground = 143+142;
        else if(x >= 1935 && x <= 2320 && y <= 143+336) ground = 143+336;
        else if(x > 2320 && x <= 3010 && y <= 143+433){
            ground = 143+433;
            if(x > 3000) level=2;
        }
        else ground = water;
    }
    else if(level == 2){
        if(x > 0 && x <= 500 && y <= 564) ground = 564;
        else if(x >= 835 && x <= 1349 && y <= 470) ground = 470;
        else if(x >= 1505 && x <= 1900 && y <= 143+142) ground = 143+142;
        else if(x >= 1935 && x <= 2320 && y <= 143+336) ground = 143+336;
        else if(x > 2320 && x <= 3010 && y <= 143+433) ground = 143+433;
        else ground = water;
    }

    velocityX += accelerationX*friction;
    velocityY += accelerationY*friction;

    x += velocityX;
    y += velocityY;
}

#endif // PHYSX_HPP_INCLUDED
