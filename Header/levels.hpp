#ifndef LEVELS_HPP_INCLUDED
#define LEVELS_HPP_INCLUDED

#include "../Header/scenes.hpp"

float x = 200;
float y = 200;
int ground = 564;
int water = 900;
int level = 0;
bool chk=false;
int stuck;

void updateGround1(){
    if(x > 0 && x <= 500 && y <= 564+51) ground = 564+51;
    else if(x >= 835-30 && x <= 1349 && y <= 470+50) ground = 470+50;
    else if(x >= 1505-30 && x <= 1900 && y <= 143+142+50) ground = 143+142+50;
    else if(x >= 1935-30 && x <= 2320 && y <= 143+336+50) ground = 143+336+50;
    else if(x > 2320-30 && x <= 3020 && y <= 143+433+50){
        if(x <= 2380 && x > 2320 && y >= 143+336+50){
            stuck = -1;
        }
        else{
            stuck = 0;
        }
        ground = 143+433+50;
        if(x > 2450){
            currentScene = secondLevelAnime;
            chk = false;
        }
    }
    else ground = water;
}

void updateGround2(){
    if(x > 0 && x <= 440 && y <= 652) {
        if(x <= 60 && x > -900){
            stuck = -1;
        }
        else{
            stuck = 0;
        }
        ground = 652;
    }
    else if(x >= 688-30 && x <= 1192 && y <= 510) ground = 510;
    else if(x >= 1388-30 && x <= 1690 && y <= 372) ground = 372;
    else if(x >= 1938-30 && x <= 2240 && y <= 272) ground = 272;
    else if(x >= 2440-30 && x <= 2992 && y <= 500) ground = 500;
    else if(x >= 3088-30 && x <= 3440 && y <= 372) ground = 372;
    else if(x >= 3538-30 && x <= 3710 && y <= 272) ground = 272;
    else if(x >= 3790-30 && x <= 3940 && y <= 372) ground = 372;
    else if(x >= 4138-30 && x <= 4542 && y <= 510) ground = 510;
    else if(x >= 4688-30 && x < 5000 && y <= 342) ground = 342;
    else if(x>5000){
        level=3;
        chk = false;
    }
    else ground = water;
}

void updateGround3(){
    if(x > 0 && x <= 395 && y <= 460) ground = 460;
    else if(x >= 490-30 && x <= 885 && y <= 315) ground = 315;
    else if(x >= 1119-30 && x <= 1520 && y <= 170) ground = 170;
    else if(x >= 1320-30 && x <= 1584 && y <= 470 && y > 170) ground = 470;
    else if(x >= 1585-30 && x <= 1840 && y <= 590 && y > 480) {
        if(x <= 1644 && x > 1584){
            stuck = -1;
        }
        else{
            stuck = 0;
        }
        ground = 590;
    }
    else if(x > 2130-30 && x <= 2780 && y <= 500 && y > 320) ground = 500;
    else if(x > 2630-30 && x <= 3025 && y <= 320) ground = 320;
    else if(x > 3370-30 && x <= 3900 && y <= 400) ground = 400;
    else if(x > 3885-30 && x <= 5410 && y <= 590 && y > 480) ground = 590;
    else if(x > 5410) {
        level = 4;
        chk = false;
    }
    else ground = water;
}

void updateGround4(){
    if(x > 0 && x <= 750 && y <= 634 - 40) ground = 634 - 40;
    else if(x > 930 && x <= 1537 && y <= 427 - 40) ground = 427 - 40;
    else if(x > 1786 && x <= 2385 && y <= 565 - 40 && y > 420) ground = 565 - 40;
    else if(x > 2160 && x <= 2757 && y <= 370 - 40) ground = 370 - 40;
    else if(x > 2910 && x <= 3776 && y <= 465 - 40) ground = 465 - 40;
    else if(x > 4080 && x <= 4567 && y <= 570 - 40) ground = 570 - 40;
    else if(x > 4719 && x <= 5430 && y <= 424 - 40) ground = 424 - 40;
    else if(x > 5520 && x <= 5920 && y <= 263 - 40) ground = 263 - 40;
    else if(x > 5932 && x <= 6686 && y <= 629 - 40) {
        if(x <= 6686 && x > 6626 && y > 390){
            stuck = 1;
        }
        else{
            stuck = 0;
        }
        ground = 629 - 40;
    }
    else if(x > 6655 && x <= 6710 && y > 384) {
        x = 6632;
        y = 629 - 38;
    }
    else if(x > 6640 && x <= 7242 && y <= 370 - 30) ground = 370 - 30;
    else if(x > 7499 && x <= 8060 && y <= 628 - 40 ) ground = 628 - 40;
    else ground = water;
}

#endif // LEVELS_HPP_INCLUDED
