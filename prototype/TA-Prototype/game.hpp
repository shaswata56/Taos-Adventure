#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include "player.hpp"
#include <iostream>

using namespace sf;

Event ev;
Player hero({20});

void game(){
    hero.setPos({50.0f, 500.0f});
    float gravity=1.0f, moveSpeed=25.0f, vSpeed=0.0f;
    bool isJumping=false, moving=true;
    RenderWindow win(VideoMode(1000, 600), "Hello World");
    win.setFramerateLimit(60);

    RectangleShape groundR({1000, 10});
    groundR.setPosition(0, 540);
    groundR.setFillColor(Color::Green);

    while(win.isOpen()){

        if(Keyboard::isKeyPressed(Keyboard::Up)){
            hero.move({0, -moveSpeed});
            isJumping=true;
        }
        if(Keyboard::isKeyPressed(Keyboard::Right)){
            if(vSpeed<8.0f) vSpeed+=0.2f;
        }
        if(Keyboard::isKeyPressed(Keyboard::Left)){
            if(vSpeed>(-8.0f)) vSpeed-=0.2f;
        }
        if(isJumping) moveSpeed-=gravity;
        if(hero.getY()<500.0f && !isJumping) {
            moveSpeed-=gravity;
            hero.move({0, -moveSpeed});
        }

        if(hero.getY()>=500.0f && isJumping) moveSpeed=25.0f;
        if(hero.getY()>=500.0f && !isJumping) moveSpeed=0.0f, hero.setPos({hero.getX(), 500.0f});

        hero.move({vSpeed, 0});

        if(!moving){
            if(vSpeed>=0.0f) vSpeed-=0.2f;
            if(vSpeed<=0.0f) vSpeed+=0.2f;
            std::cout<<vSpeed<<std::endl;
            if(vSpeed==0.0f) moving=true;
        }

        while(win.pollEvent(ev)){
            switch(ev.type){
            case Event::Closed:
                win.close();
            case Event::KeyReleased:
                if(ev.key.code==Keyboard::Up) isJumping=false;
                if(ev.key.code==Keyboard::Left || ev.key.code==Keyboard::Right) moving=false;
            default:
                break;
            }
        }
        win.clear();
        win.draw(groundR);
        hero.drawTo(win);
        win.display();

    }
}

#endif // GAME_HPP_INCLUDED
