#include "LemmingGame.h"
#include "Lemming.h"
#include "Timer.h"

cocos2d::Scene* LemmingGame::createScene()
{
    return LemmingGame::create();
}

bool LemmingGame::init()
{
    if (!Scene::initWithPhysics())
    {
        return false;
    }
    this->getPhysicsWorld()->setDebugDrawMask(cocos2d::PhysicsWorld::DEBUGDRAW_SHAPE);
    visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    origin = cocos2d::Director::getInstance()->getVisibleOrigin();

    _tileMap = cocos2d::TMXTiledMap::create("tiled/Level1.mini.tmx");
	_tileMap->setScale(MAP_SCALE);
    cocos2d::Size mapSize = _tileMap->getMapSize();

    breakable = _tileMap->getLayer("breakable");
    unbreakable = _tileMap->getLayer("unbreakable");
    
    this->addChild(_tileMap);
    
    cocos2d::TMXObjectGroup* objects = _tileMap->getObjectGroup("interractions");
    cocos2d::ValueMap spawnPoint = objects->getObject("start");
	int x = spawnPoint["x"].asInt() * MAP_SCALE;
	int y = spawnPoint["y"].asInt() * MAP_SCALE;
	SpawnLemming(x, y, false);

	return true;
}

void LemmingGame::SpawnLemming(int x, int y, bool direction)
{
    auto physicsBody = cocos2d::PhysicsBody::createBox(cocos2d::Size(15, 15), cocos2d::PhysicsMaterial(0.1f, 1.0f, 0.0f));
    physicsBody->setDynamic(false);
    physicsBody->setRotationEnable(false);
	Lemming* lemming = new Lemming(cocos2d::Vec2(x, y), direction);
    lemming->setScale(4);
    lemming->addComponent(physicsBody);
	this->addChild(lemming);
	lemmings.push_back(lemming);
}