#ifndef ASSESTMGR_H_INCLUDED
#define ASSESTMGR_H_INCLUDED
#include <SFML/Graphics.hpp>

class AssestMgr
{
    public:
        AssestManager();
        virtual ~AssestMgr();
        sf::Texture fLoadTexture();
    protected:
    private:
};

#endif // ASSESTMGR_H_INCLUDED
