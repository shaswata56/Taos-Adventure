#ifndef LEVELS_HPP_INCLUDED
#define LEVELS_HPP_INCLUDED

float x = 200;
float y = 200;
int ground = 564;
int water = 760+50;
int level = 3;

void updateGround(){
    if(level == 1){
        if(x > 0 && x <= 500 && y <= 564+50) ground = 564+50;
        else if(x >= 835 && x <= 1349 && y <= 470+50) ground = 470+50;
        else if(x >= 1505 && x <= 1900 && y <= 143+142+50) ground = 143+142+50;
        else if(x >= 1935 && x <= 2320 && y <= 143+336+50) ground = 143+336+50;
        else if(x > 2320 && x <= 3020 && y <= 143+433+50){
            ground = 143+433+50;
            if(x > 3000) level=3;
        }
        else ground = water;
    }
    else if(level == 3){
        if(x > 0 && x <= 395 && y <= 460) ground = 460;
        else if(x >= 490 && x <= 885 && y <= 315) ground = 315;
        else if(x >= 1119 && x <= 1520 && y <= 170) ground = 170;
        else if(x >= 1320 && x <= 1584 && y <= 470 && y > 170) ground = 470;
        else if(x >= 1585 && x <= 1840 && y <= 590 && y > 480) ground = 590;
        else if(x > 2130 && x <= 2780 && y <= 500 && y > 320) ground = 500;
        else if(x > 2630 && x <= 3025 && y <= 320) ground = 320;
        else ground = water;
    }
}

#endif // LEVELS_HPP_INCLUDED
