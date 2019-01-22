#include "../Header/scenes.hpp"
#include "../Scenes/game.hpp"
#include "../Scenes/menu.hpp"
#include "../Scenes/GameOver.hpp"
#include "../Scenes/story.hpp"
#include "../Scenes/addedLater.hpp"
#include "../Scenes/anim1.hpp"
#include "../Scenes/anim2.hpp"
#include "../Scenes/pause.hpp"
#include "../Scenes/help.hpp"
#include "../Scenes/credits.hpp"

int updateScene() {
    RenderWindow app(VideoMode(1200,800), "Pos:", Style::Close);
    app.setFramerateLimit(60);
    app.setVerticalSyncEnabled(false);
    currentScene = mainMenu;
    Font AmaticB;
    AmaticB.loadFromFile("Resource/Fonts/Amatic-Bold.ttf");
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
        //app.clear();

        switch(currentScene){
            case startingAnime:
                anim1(app);
                break;
            case secondLevelAnime:
                anim2(app);
                break;
            case gamePlay:
                game(app);
                break;
            case gamePaused:
                pause(app);
                break;
            case mainMenu:
                menu(app);
                break;
            case storyLine:
                story(app);
                break;
            case helpPage:
                help(app);
                break;
            case creditPage:
                credit(app);
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
