#include "../Header/scenes.hpp"
#include "../Scenes/game.hpp"
#include "../Scenes/menu.hpp"

int updateScene() {
    RenderWindow app(VideoMode(1200,800), "Pos:", Style::Close);
    app.setFramerateLimit(30);
    app.setVerticalSyncEnabled(true);
    currentScene = mainMenu;

    while (app.isOpen())
    {
        Event e;
        while(app.pollEvent(e)){
            if (e.type==Event::Closed){
                app.close();
            }
        }
        app.clear();

        switch(currentScene){
        case gamePlay:
            game(app);
            break;
        case mainMenu:
            menu(app);
            break;
        }

        app.display();
    }
    return 0;
}
