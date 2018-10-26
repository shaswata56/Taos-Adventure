#include "../Header/tao.hpp"
#include "../Header/world.hpp"

Tao tao;
World world, world2, world3;

int main() {
    RenderWindow app(VideoMode(1200,800), "Pos:");
    app.setFramerateLimit(30);
    app.setVerticalSyncEnabled(true);
    tao.LoadTao("Resource/img/Object/ball.png");
    world.LoadBG("Resource/img/BG/bgscr.png");
    world.LoadFG("Resource/img/BG/12.png");
    world.PosFG(195+49);
    int s = 15, bx=600;

    while (app.isOpen())
    {
        Event e;
        while(app.pollEvent(e)){
            if (e.type==Event::Closed){
                app.close();
            }
        }

        if(level == 2){
            if(chk == false){
                world2.LoadBG("Resource/Levels/2/bg.png");
                world2.LoadFG("Resource/Levels/2/fg.png");
                world2.PosFG(55);
                chk = true;
                x = 100;
                y = 400;
                bx = 600;
                velocityX = 0;
            }
            if(x >= 610 && x <= 4480) bx=x;
        }
        else if(level == 3){
            if(chk == false){
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

        if(Keyboard::isKeyPressed(Keyboard::Left) && y >= ground){
            tao.RolnRun(-s);
        }
        else if(Keyboard::isKeyPressed(Keyboard::Right) && y >= ground){
            tao.RolnRun(s);
        }
        if(Keyboard::isKeyPressed(Keyboard::Up) && pressUpCount == 0){
                ++pressUpCount;
                if(pressUpCount==1) velocityY = -30;
        }
        if(velocityX != 0){
                tao.roll(velocityX);
        }

        View view(Vector2f(bx, 400), Vector2f(1200, 800));
        if(level == 1) if(x >= 610 && x <= 2390) bx=x;

        updateMovement();

        tao.setPos(x, y);
        app.clear();
        if(level == 1) world.drawTo(app);
        else if(level == 2) world2.drawTo(app);
        else if(level == 3) world3.drawTo(app);
        tao.drawTo(app);
        app.setView(view);
        app.display();
    }
    return 0;
}
