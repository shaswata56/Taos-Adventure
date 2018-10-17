#ifndef INCLUDES_HPP_INCLUDED
#define INCLUDES_HPP_INCLUDED
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

Event ev;
Texture TrunH[10], TidleH[10], TdeadH[10], TjumpH[10];

void include(){
    char url[50][50];
    for(int i=0; i<10; i++){
        sprintf(url[i], "resources/char1/Run__00%d.png", i);
        TrunH[i].loadFromFile(url[i]);
        TrunH[i].setSmooth(true);
        sprintf(url[i], "resources/char1/Idle__00%d.png", i);
        TidleH[i].loadFromFile(url[i]);
        TidleH[i].setSmooth(true);
        sprintf(url[i], "resources/char1/Dead__00%d.png", i);
        TdeadH[i].loadFromFile(url[i]);
        TdeadH[i].setSmooth(true);
        sprintf(url[i], "resources/char1/Jump__00%d.png", i);
        TjumpH[i].loadFromFile(url[i]);
        TjumpH[i].setSmooth(true);

    }
}

#endif // INCLUDES_HPP_INCLUDED
