#ifndef TILEMAP_H_INCLUDED
#define TILEMAP_H_INCLUDED
#include <SFML/Graphics.hpp>

class Game;

class TileMap
{
    public:
        TileMap(const int, const int); //! Make a tile map. Parameters x, y <- w,h in tile this map
        ~TileMap();
        void fDrawTileMap(Game* tGame); //! To draw it. Actually it need a pointer to game, it should be active by event launcher and be 'transfer' to main loop
        double fGetMaxFactor();
        int fGetSize(char);
        sf::Texture* tTile;
    protected:
    private:
        sf::RectangleShape* aTiles;
        int wWidth;
        int wHeight;
        double wF;
};

#endif // TILEMAP_H_INCLUDED
