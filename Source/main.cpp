#include "../Header/tao.hpp"
#include "../Header/world.hpp"

Tao tao;
World world, world3;

int main() {
<<<<<<< HEAD
    RenderWindow app(VideoMode(1200,800), "Pos:");
    app.setFramerateLimit(30);
    app.setVerticalSyncEnabled(true);
    tao.LoadTao("Resource/img/Object/ball.png");
    world.LoadBG("Resource/img/BG/bgscr.png");
    world.LoadFG("Resource/img/BG/12.png");
    world.PosFG(195+49);
    int s = 15, bx=600;
    bool chk=false;
=======
    RenderWindow app(VideoMode(1000,750), "Tao's Adventure");
    app.setFramerateLimit(30);
    app.setVerticalSyncEnabled(true);
    tao.LoadTao("Resource/img/Object/ball.png");
    world.LoadBG("Resource/Levels/1/bg.png");
    world.LoadFG("Resource/Levels/1/fg.png");

    int s = 15, bx=500;                                 //S = Movement Speed, bx = View Control

>>>>>>> cba0a56e113201f3084e159dacd734ca3bce6913
    while (app.isOpen())
    {
        Event e;
        while(app.pollEvent(e)){
            if (e.type==Event::Closed){
                app.close();
            }
        }

        if(level == 3){
            if(chk == false){
                world3.LoadBG("Resource/img/3/bg.png");
                world3.LoadFG("Resource/img/3/level.png");
                world3.PosFG(-50);
                chk = true;
                x = 100;
                y = 100;
                bx = 600;
                velocityX = 0;
            }
            if(x >= 610 && x <= 4790) bx=x;
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
        if(level == 3) world3.drawTo(app);
        tao.drawTo(app);
        app.setView(view);
        app.display();
    }
    return 0;
}
