#ifndef SCENE_H_INCLUDED
#define SCENE_H_INCLUDED
#include <SFML/Graphics.hpp>
#include "component.h"
#include <list>
class Game;

class Scene
{
    public:
        Scene();
        ~Scene();
        void fAddComponent();
        void fDrawScene();
    protected:
    private:
        std::list<Component> lListOfComponents;
};

#endif // SCENE_H_INCLUDED
