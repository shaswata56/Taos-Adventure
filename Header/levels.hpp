#ifndef LEVELS_HPP_INCLUDED
#define LEVELS_HPP_INCLUDED

float x = 200;
float y = 200;
int ground = 564;
int water = 760;
int level = 1;

void updateGround(){
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
        if(x > 38 && x <= 440 && y <= 652) ground = 652;
        else if(x >= 688 && x <= 1192 && y <= 500) ground = 500;
        else if(x >= 1388 && x <= 1690 && y <= 362) ground = 362;
        else if(x >= 1938 && x <= 2240 && y <= 262) ground = 262;
        else if(x >= 2440 && x <= 2992 && y <= 500) ground = 500;
        else if(x >= 3088 && x <= 3440 && y <= 362) ground = 362;
        else if(x >= 3538 && x <= 3690 && y <= 262) ground = 262;
        else if(x >= 3790 && x <= 3940 && y <= 362) ground = 362;
        else if(x >= 4138 && x <= 4542 && y <= 500) ground = 500;
        else if(x >= 4688 && x < 5000 && y <= 312) ground = 312;
        else if(x>5000) level=3;
        else ground = water;
    }
}

#endif // LEVELS_HPP_INCLUDED
