#include "../Header/tao.hpp"
#include "../Header/world.hpp"
#include "../Header/control.hpp"

Tao tao;
World world1, world2, world3;

int game() {
    RenderWindow app(VideoMode(1200,800), "Pos:", Style::Close);
    app.setFramerateLimit(30);
    app.setVerticalSyncEnabled(true);
    tao.LoadTao("Resource/Levels/co/ball.png");
    int bx=600;

    while (app.isOpen())
    {
        Event e;
        while(app.pollEvent(e)){
            if (e.type==Event::Closed){
                app.close();
            }
        }

        if(level == 1){
            if(chk == false){
                world1.LoadBG("Resource/Levels/1/bg.png");
                world1.LoadFG("Resource/Levels/1/fg.png");
                world1.PosFG(195+45);
                chk = true;
                x = 100;
                y = 400;
                bx = 600;
                velocityX = 0;
            }
            if(x >= 610 && x <= 2390) bx=x;
        }
        else if(level == 2){
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
            if(x >= 610 && x <= 4380) bx=x;
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

        user_interact(tao);

        View view(Vector2f(bx, 400), Vector2f(1200, 800));

        updateMovement();

        tao.setPos(x, y);
        app.clear();
        if(level == 1) world1.drawTo(app);
        else if(level == 2) world2.drawTo(app);
        else if(level == 3) world3.drawTo(app);
        if(!(level == 3 && x > 5000)) tao.drawTo(app);
        app.setView(view);
        app.display();
    }
    return 0;
}
