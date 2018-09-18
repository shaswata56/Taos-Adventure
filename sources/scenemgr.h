#ifndef SCENEMGR_H_INCLUDED
#define SCENEMGR_H_INCLUDED
#include "scene.h"

class SceneMgr
{
    public:
        SceneMgr();
        ~SceneMgr();
        void fSetScene(Scene*);
        void fDrawScene();                                                  //! Scene - draw level (menu, map...) LOAD and draw scene
    protected:
    private:
        Scene* tAcualScene;

};

#endif // SCENEMGR_H_INCLUDED
