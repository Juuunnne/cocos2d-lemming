#ifndef __LEMMINGGAME_SCENE_H__
#define __LEMMINGGAME_SCENE_H__

#include "cocos2d.h"
#include "Lemming.h"
#include "PauseMenu.h"
#define MAP_SCALE 2
USING_NS_CC;

class LemmingGame : public Scene
{
public:
    static Scene* createScene();

    CREATE_FUNC(LemmingGame);
    virtual bool init();

	void SpawnLemming(Vec2, bool direction);

	void onLemmingCollision(PhysicsContact& contact);

    void explode(Vec2, int radius);
    void InputHandler();
    void MouseHandler();
    bool isKeyPressed(EventKeyboard::KeyCode code);

    void update(float delta);

private:
    Size visibleSize;
    Vec2 origin;
    TMXTiledMap* _tileMap;
    TMXLayer* breakable;
    TMXLayer* unbreakable;
    std::vector<Lemming*> lemmings;
    float time;
    //Vector saving keyboard input
    std::vector<cocos2d::EventKeyboard::KeyCode> keys;

    //Mouse Event Listener
    EventListenerMouse* _mouseListener;

    float cursorX;
    float cursorY;

    int maxNumber = 40;
    Vec2 spawnLemmingPoint;
    Vec2 mousePos;
};

#endif