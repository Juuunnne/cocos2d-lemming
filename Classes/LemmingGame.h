#ifndef __LEMMINGGAME_SCENE_H__
#define __LEMMINGGAME_SCENE_H__

#include "cocos2d.h"
#include "Lemming.h"
#define MAP_SCALE 2

class LemmingGame : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

	void SpawnLemming(int x, int y, bool direction);

    CREATE_FUNC(LemmingGame);

private:
    cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;
    cocos2d::TMXTiledMap* _tileMap;
    cocos2d::TMXLayer* breakable;
    cocos2d::TMXLayer* unbreakable;
    std::vector<Lemming*> lemmings;
    float time;
};

#endif