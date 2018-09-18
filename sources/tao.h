#ifndef TAO_H_INCLUDED
#define TAO_H_INCLUDED
#include <SFML/Graphics.hpp>
#include "game.h"

class Tao
{
public:
    Tao(pos , int, int);
    ~cTao();
    void fDrawTao(Game*, pos);
    void fMoveTao(Game*, pos, int);


protected:
    sf::Texture* T1;
    int x, y, r;
    sf::CircleShape* tShape;

private:


};

#endif // TAO_H_INCLUDED
