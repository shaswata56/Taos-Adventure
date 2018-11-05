#include "../Header/gamePlay.hpp"


int updadeScene() {
    RenderWindow app(VideoMode(1200,800), "Pos:", Style::Close);
    app.setFramerateLimit(30);
    app.setVerticalSyncEnabled(true);

    while (app.isOpen())
    {
        Event e;
        while(app.pollEvent(e)){
            if (e.type==Event::Closed){
                app.close();
            }
        }

        app.clear();
        game(app);
        app.display();
    }
    return 0;
}
