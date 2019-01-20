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
World world1, world2, world3, world4;
bool gameStarted = true;
int bx = 600;
View view;
Enemy shoytans[10];

void MoiraGechi(void){
    world1.StopSFX();
    world2.StopSFX();
    world4.StopSFX();
    level = 0;
    chk = false;
    x = 100;
    y = 400;
    bx = 600;
    velocityX = 0;
    currentScene = gameOver;
    Enemy* shoytans = new Enemy[10];
}

void game(RenderWindow &app) {
    if(gameStarted) {
        tao.LoadTao("Resource/Levels/co/TaoSmall.png");
        world1.StopSFX();
        world2.StopSFX();
        world4.StopSFX();
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
            shoytans[9].jinda();
        }
        world1.PosBG(bx / 9.23 + bx - 1401);
        if(x >= 610 && x <= 2390) bx=x;
        world1.drawTo(app);
        shoytans[9].updateEnemy();
        if(tao.getRect().intersects(shoytans[9].getRect())){
            if(shoytans[9].getRect().top-tao.getRect().top>=30){
                shoytans[9].dead();
                velocityY = -20;
            }
            else {
                MoiraGechi();
            }
        }
        shoytans[9].drawEnemy(app);
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
            shoytans[0].jinda();
            shoytans[1].initEnemy(1938, 2190, 268);
            shoytans[1].jinda();
            shoytans[2].initEnemy(3088, 3390, 368);
            shoytans[2].jinda();
            shoytans[3].initEnemy(4138, 4492, 505);
            shoytans[3].jinda();
        }
        world2.PosBG(bx / 9.23 + bx - 1401);
        if(x >= 610 && x <= 4380) bx=x;
        world2.drawTo(app);
        for(int shoytanNumber=0; shoytanNumber < 4; shoytanNumber++){
            shoytans[shoytanNumber].updateEnemy();
            if(tao.getRect().intersects(shoytans[shoytanNumber].getRect())){
            if(shoytans[shoytanNumber].getRect().top-tao.getRect().top>=30){
                shoytans[shoytanNumber].dead();
                velocityY = -20;
            }
            else {
                MoiraGechi();
            }
        }
        shoytans[shoytanNumber].drawEnemy(app);
        }
    }
    else if(level == 3){
        if(chk == false){
            world2.StopSFX();
            world3.LoadBG("Resource/Levels/3/bg.png");
            world3.LoadFG("Resource/Levels/3/fg.png");
            world3.PosFG(-50);
            world2.LoadSFX("Resource/Levels/2/night-sfx.ogg");
            chk = true;
            x = 100;
            y = 100;
            bx = 600;
            velocityX = 0;
            shoytans[4].initEnemy(509, 835, 315);
            shoytans[4].jinda();
            shoytans[5].initEnemy(2145, 2733, 506);
            shoytans[5].jinda();
            shoytans[6].initEnemy(3370, 3850, 400);
            shoytans[6].jinda();
            world2.PlaySFX();
        }
        world3.PosBG(bx / 9.23 + bx - 1401);
        if(x >= 610 && x <= 4770) bx=x;
        world3.drawTo(app);
        for(int shoytanNumber=4; shoytanNumber < 7; shoytanNumber++){
            shoytans[shoytanNumber].updateEnemy();
            if(tao.getRect().intersects(shoytans[shoytanNumber].getRect())){
            if(shoytans[shoytanNumber].getRect().top - tao.getRect().top >= 30){
                shoytans[shoytanNumber].dead();
                velocityY = -20;
            }
            else {
                MoiraGechi();
            }
        }
        shoytans[shoytanNumber].drawEnemy(app);
        }
    }
    else if(level == 4){
        if(chk == false){
            world2.StopSFX();
            world4.LoadBG("Resource/Levels/4/bg.png");
            world4.LoadFG("Resource/Levels/4/fg.png");
            world4.PosFG(0);
            world2.LoadSFX("Resource/Levels/2/night-sfx.ogg");
            world4.LoadSFX("Resource/Levels/4/ghost.ogg");
            world4.setVol(25);
            chk = true;
            x = 100;
            y = 400;
            bx = 600;
            velocityX = 0;
            world2.PlaySFX();
            world4.PlaySFX();
        }
        world4.PosBG(bx / 9.23 + bx - 1401);
        if(x >= 610 && x <= 7390) bx=x;
        world4.drawTo(app);
    }

    View view(Vector2f(bx, 400), Vector2f(1200, 800));
    view.setCenter(Vector2f(bx, 400));
    view.setSize(Vector2f(1200, 800));
    updateMovement();
    user_interact(tao);
    tao.setPos(x, y);
    if(!(level == 3 && x > 5000)) tao.drawTo(app);
    app.setView(view);
}

#endif
