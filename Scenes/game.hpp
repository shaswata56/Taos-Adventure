///             IMPORTANT NOTE               ///
//============================================//
/// ENEMY START POINT = PLATFORM START POINT ///
/// ENEMY END POINT = PLATFORM END POINT -50 ///
///    ENEMY HEIGHT = PLATFORM HEIGHT - 5    ///

#ifndef GAMEPLAY_HPP_INCLUDED
#define GAMEPLAY_HPP_INCLUDED
#include "../Header/tao.hpp"
#include "../Header/world.hpp"
#include "../Header/control.hpp"
#include "../Header/enemy.hpp"

Tao tao;
World world1, world2, world3;
bool gameStarted = true;
int bx = 600;
View view;
Enemy shoytans[10];

void MoiraGechi(void){
    world1.StopSFX();
    world2.StopSFX();
    level = 1;
    chk = false;
    x = 100;
    y = 400;
    bx = 600;
    velocityX = 0;
    currentScene = gameOver;
}

void game(RenderWindow &app) {
    if(gameStarted) {
        tao.LoadTao("Resource/Levels/co/TaoSmall.png");
        gameStarted = false;
    }
    if(tao.getpos().y > 800)
    {
        MoiraGechi();
    }
    if(level == 1){
        if(chk == false){
            world1.LoadBG("Resource/Levels/1/bg.png");
            world1.LoadFG("Resource/Levels/1/fg.png");
            world1.PosFG(195+45);
            world1.LoadSFX("Resource/Levels/1/day-sfx.ogg");
            chk = true;
            x = 100;
            y = 400;
            bx = 600;
            velocityX = 0;
            world1.PlaySFX();
            shoytans[9].initEnemy(1505.0f, 1850.0f, 330.0f);
        }
        if(x >= 610 && x <= 2390) bx=x;
    }
    else if(level == 2){
        if(chk == false){
            world1.StopSFX();
            world2.LoadBG("Resource/Levels/2/bg.png");
            world2.LoadFG("Resource/Levels/2/fg.png");
            world2.PosFG(55);
            world2.LoadSFX("Resource/Levels/2/night-sfx.ogg");
            chk = true;
            x = 100;
            y = 400;
            bx = 600;
            velocityX = 0;
            world2.PlaySFX();
            shoytans[0].initEnemy(688, 1142, 505);
            shoytans[1].initEnemy(1938, 2190, 268);
            shoytans[2].initEnemy(3088, 3390, 368);
            shoytans[3].initEnemy(4138, 4492, 505);
        }
        if(x >= 610 && x <= 4380) bx=x;
    }
    else if(level == 3){
        if(chk == false){
            world2.StopSFX();
            world3.LoadBG("Resource/Levels/3/bg.png");
            world3.LoadFG("Resource/Levels/3/fg.png");
            world3.PosFG(-50);
            chk = true;
            x = 100;
            y = 100;
            bx = 600;
            velocityX = 0;
        }
        if(x >= 610 && x <= 4770) bx=x;
    }
    user_interact(tao);
    View view(Vector2f(bx, 400), Vector2f(1200, 800));
    view.setCenter(Vector2f(bx, 400));
    view.setSize(Vector2f(1200, 800));
    updateMovement();
    tao.setPos(x, y);
/*

    If player jumps over the enemy then the enemy will die otherwise the player will die when the player and enemy intersects.
    I took 30 as a differences of the top positions of them after tweaking some other values.
    Now it's time to place the enemies at the right places.

*/
    for (int shoytanNumber = 0; shoytanNumber < 10; shoytanNumber++){
        if(tao.getRect().intersects(shoytans[shoytanNumber].getRect())){
            if(shoytans[shoytanNumber].getRect().top-tao.getRect().top>=30){
                shoytans[shoytanNumber].dead();
                velocityY = -20;
            }
            else {
                MoiraGechi();
            }
        }
    }

    if(level == 1){
        shoytans[9].updateEnemy();
        world1.drawTo(app);
        shoytans[9].drawEnemy(app);
    }
    else if(level == 2) {
        world2.drawTo(app);
        for(int shoytanNumber=0; shoytanNumber<4; shoytanNumber++){
            shoytans[shoytanNumber].updateEnemy();
            shoytans[shoytanNumber].drawEnemy(app);
        }
    }
    else if(level == 3) world3.drawTo(app);
    if(!(level == 3 && x > 5000)) tao.drawTo(app);
    app.setView(view);
}

#endif
