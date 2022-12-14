#include "LemmingGame.h"

USING_NS_CC;

Scene* LemmingGame::createScene()
{
    return LemmingGame::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool LemmingGame::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::initWithPhysics())
    {
        return false;
    }
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();

    _tileMap = cocos2d::TMXTiledMap::create("tiled/Level1.mini.tmx");
    Size mapSize = _tileMap->getMapSize();

	this->addChild(_tileMap);

	this->CreateLemmings(10);

    return true;
}


void LemmingGame::CreateLemmings(int n)
{
    TMXObjectGroup* objects = _tileMap->getObjectGroup("interractions");

    if (objects == NULL)
    {
		CCLOG("Cannot find object group 'interractions'");
		return;
    }

	cocos2d::ValueMap spawnPoint = objects->getObject("start");
    int x = spawnPoint["x"].asInt();
    int y = spawnPoint["y"].asInt();
    
    // See collision boxes 
	this->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_SHAPE);
    
    for (int i = 0; i < n; ++i) {
        auto physicsBody = PhysicsBody::createBox(Size(15, 15), PhysicsMaterial(0.1f, 1.0f, 0.0f));
        physicsBody->setDynamic(true);
        physicsBody->setRotationEnable(false);
        cocos2d::Sprite* MySprite = Sprite::create("lemmings.png", Rect(0, 0, 15, 15));
		MySprite->setPosition(Vec2(x, y));
        MySprite->addComponent(physicsBody);
        this->addChild(MySprite);
    }
}