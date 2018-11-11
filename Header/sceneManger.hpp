#include "../Header/scenes.hpp"
#include "../Scenes/game.hpp"
#include "../Scenes/menu.hpp"
#include "../Scenes/GameOver.hpp"

int updateScene() {
    RenderWindow app(VideoMode(1200,800), "Pos:", Style::Close);
    app.setFramerateLimit(60);
    app.setVerticalSyncEnabled(false);
    currentScene = mainMenu;

    Font AmaticB;
    AmaticB.loadFromFile("Resource/Fonts/Amatic-Bold.ttf");
    Text startGameText("Press Enter To Start Game", AmaticB, 70);
    startGameText.setOrigin(startGameText.getLocalBounds().width/2, startGameText.getLocalBounds().height/2);
    startGameText.setPosition(600, 400);
    startGameText.setFillColor(Color::Yellow);
    Text endGameText("Game Over", AmaticB, 70);
    endGameText.setOrigin(endGameText.getLocalBounds().width/2, endGameText.getLocalBounds().height/2);
    endGameText.setPosition(600, 400);
    endGameText.setFillColor(Color::Red);

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
                menu(app, startGameText);
                break;
            case gameOver:
                game_over(app, endGameText);
                break;
            default :
                break;
        }

        app.display();
    }
    return 0;
}
