#ifndef __LEMMINGGAME_SCENE_H__
#define __LEMMINGGAME_SCENE_H__

#include "cocos2d.h"
#include "Lemming.h"
#define MAP_SCALE 2
USING_NS_CC;

class LemmingGame : public Scene
{
public:
    static Scene* createScene();

    virtual bool init();

	void SpawnLemming(int x, int y, bool direction);

	void onLemmingCollision(PhysicsContact& contact);
    
    CREATE_FUNC(LemmingGame);

private:
    Size visibleSize;
    Vec2 origin;
    TMXTiledMap* _tileMap;
    TMXLayer* breakable;
    TMXLayer* unbreakable;
    std::vector<Lemming*> lemmings;
    float time;
};

#endif