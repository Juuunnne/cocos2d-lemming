#ifndef __LEMMINGGAME_SCENE_H__
#define __LEMMINGGAME_SCENE_H__

#include "cocos2d.h"
#include "Lemming.h"

class LemmingGame : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    void CreateLemmings(int n);

    CREATE_FUNC(LemmingGame);

private:
    cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;
    cocos2d::TMXTiledMap* _tileMap;
    std::vector<Lemming*> lemmings;
};

#endif