#include "../Header/tao.hpp"
#include "../Header/world.hpp"

Tao tao;
World world;

int main() {
    RenderWindow app(VideoMode(1000,750), "Pos:");
    app.setFramerateLimit(30);
    app.setVerticalSyncEnabled(true);
    tao.LoadTao("Resource/img/Object/ball.png");
    world.LoadBG("Resource/img/BG/bgscr.png");
    world.LoadFG("Resource/img/BG/12.png");
    int s = 15, bx=500, level ;
    //ground=621;
    while (app.isOpen())
    {
        Event e;
        while(app.pollEvent(e)){
            if (e.type==Event::Closed){
                app.close();
            }
        }

        if(Keyboard::isKeyPressed(Keyboard::Left) && x > 20 && y >= ground){
            tao.RolnRun(-s);
        }
        else if(Keyboard::isKeyPressed(Keyboard::Right) && x < 2990 && y >= ground){
            tao.RolnRun(s);
        }
        if(Keyboard::isKeyPressed(Keyboard::Up) && pressUpCount == 0){
                ++pressUpCount;
                if(pressUpCount==1) velocityY = -30;
        }
        if(velocityX > 0){
                tao.roll(velocityX);
        }
        if(velocityX < 0){
                tao.roll(velocityX);
        }

        View view(Vector2f(bx, 375), Vector2f(1000, 750));
        if(x >= 510 && x <= 2490) bx=x;

        string str = to_string(Mouse::getPosition(app).x);
        str.append(",");
        str.append(to_string(Mouse::getPosition(app).y));
        app.setTitle(str);

        updateMovement();

        tao.setPos(x, y);
        app.clear();
        world.drawTo(app);
        tao.drawTo(app);
        app.setView(view);
        app.display();
    }
    return 0;
}
