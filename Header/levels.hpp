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
        if(x > 0 && x <= 500 && y <= 564) ground = 564;
        else if(x >= 835 && x <= 1349 && y <= 470) ground = 470;
        else if(x >= 1505 && x <= 1900 && y <= 143+142) ground = 143+142;
        else if(x >= 1935 && x <= 2320 && y <= 143+336) ground = 143+336;
        else if(x > 2320 && x <= 3010 && y <= 143+433) ground = 143+433;
        else ground = water;
    }
}

#endif // LEVELS_HPP_INCLUDED
