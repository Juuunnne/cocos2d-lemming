#include "LemmingGame.h"
#include "Lemming.h"
#include "Timer.h"

Scene* LemmingGame::createScene()
{
    return LemmingGame::create();
}

bool LemmingGame::init()
{
    if (!Scene::initWithPhysics())
    {
        return false;
    }
    this->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_SHAPE);
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();

    _tileMap = TMXTiledMap::create("tiled/Level1.mini.tmx");
	_tileMap->setScale(MAP_SCALE);
    Size mapSize = _tileMap->getMapSize();

    breakable = _tileMap->getLayer("breakable");
    unbreakable = _tileMap->getLayer("unbreakable");
    
    this->addChild(_tileMap);

    for (int i = 0; i < 30; ++i)
    {
        for (int j = 0; j < 20; ++j)
        {
            auto tile = unbreakable->getTileAt(Vec2(i, j));
            PhysicsBody* physicmap = PhysicsBody::createBox(Size(16, 16),
                PhysicsMaterial(0.1f, 1.0f, 0.0f));
            physicmap->setDynamic(false);
            if (tile != nullptr)
            {
                tile->addComponent(physicmap);
            }
        }
    }
	
    TMXObjectGroup* objects = _tileMap->getObjectGroup("interractions");
    ValueMap spawnPoint = objects->getObject("start");
	int x = spawnPoint["x"].asInt() * MAP_SCALE;
	int y = spawnPoint["y"].asInt() * MAP_SCALE;
	SpawnLemming(x, y, false);

	return true;
}

void LemmingGame::onLemmingCollision(PhysicsContact& contact)
{
    auto lemmingBody = contact.getShapeA()->getBody();
    auto otherBody = contact.getShapeB()->getBody();

    // Check if the other body is a tile
    if (otherBody->getNode()->getParent() == unbreakable)
    {
        // Get the position of the tile
        Vec2 tilePos = otherBody->getNode()->getPosition();

        // Convert the position to tile coordinates
		Size tileSize = unbreakable->getMapTileSize();
        int x = tilePos.x / tileSize.width;
        int y = tilePos.y / tileSize.height;

        // Remove the tile
        unbreakable->removeTileAt(Vec2(x, y));
    }
}

void LemmingGame::SpawnLemming(int x, int y, bool direction)
{
    auto physicsBody = PhysicsBody::createBox(Size(15, 15), PhysicsMaterial(0.1f, 1.0f, 0.0f));
    physicsBody->setDynamic(true);
    physicsBody->setRotationEnable(false);
	Lemming* lemming = new Lemming(Vec2(x, y), direction);
    lemming->setScale(4);
    lemming->addComponent(physicsBody);
	this->addChild(lemming);
	lemmings.push_back(lemming);
}