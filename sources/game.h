#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <SFML/Graphics.hpp>
#include "scenemgr.h"

class Game
{
public:
    sf::Event event;
    Game();
    ~Game();

    void fRun();                                                        //! Run game. Main loop, events, ee

    sf::RenderWindow* pWindow;                                          //! Pointer to rendder window witch may use OpenGL too
    cSceneManager* pSceneManager;                                       //! Pointer to Scene Manager. W.O functionality
    sf::VideoMode oVideoMode;                                           //! Video mode is value/member of game. Eitar pointer tui korbi, mubin

protected:
private:
    int fMakeWindow();                                                  //! Used when creating a window
    void fDeleteWindow();                                               //! Used when deleting a window
    void fGetEvents();                                                  //! Event manager, function, not class
};

#endif // GAME_H_INCLUDED
