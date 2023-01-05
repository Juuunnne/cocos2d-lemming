#include "LemmingGame.h"
#include "Lemming.h"
#include "Timer.h"
#include "PauseMenu.h"

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
    //Input Manager
    InputHandler();
    //Mouse Manager
    MouseHandler();

    this->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_SHAPE);
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();

    // Load map
    _tileMap = TMXTiledMap::create("tiled/Level1.mini.tmx");
	_tileMap->setScale(MAP_SCALE);
    Size mapSize = _tileMap->getMapSize();
    this->addChild(_tileMap);

    breakable = _tileMap->getLayer("breakable");
    unbreakable = _tileMap->getLayer("unbreakable");

    // Create collisions
    PhysicsBody* collideBody;
    for (int i = 0; i < mapSize.width; ++i)
    {
        for (int j = 0; j < mapSize.height; ++j)
        {
			Vec2 tileCoord = Vec2(i, j);
			Sprite* tile_b = breakable->getTileAt(tileCoord);
            Sprite* tile_u = unbreakable->getTileAt(tileCoord);
            if (tile_b)
            {
                collideBody = PhysicsBody::createBox(Size(16, 16), PhysicsMaterial(0.1f, 0.5f, 0.0f));
                collideBody->setDynamic(false);
                tile_b->addComponent(collideBody);
            }
            if (tile_u)
            {
                collideBody = PhysicsBody::createBox(Size(16, 16), PhysicsMaterial(0.1f, 0.5f, 0.0f));
                collideBody->setDynamic(false);
                tile_u->addComponent(collideBody);
            }
        }
    }

    TMXObjectGroup* objects = _tileMap->getObjectGroup("interractions");
    ValueMap spawnPoint = objects->getObject("start");
    int x = spawnPoint["x"].asInt() * MAP_SCALE;
    int y = spawnPoint["y"].asInt() * MAP_SCALE;

    ValueMap endPoint = objects->getObject("end");

    //Function which calls automatically update function
    this->scheduleUpdate();

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

void LemmingGame::SpawnLemming(Vec2, bool direction)
{
	//Lemming* lemming = Lemming::create(Vec2(x, y), direction);
    Lemming* lemming = Lemming::create();
    lemming->init2(spawnLemmingPoint, direction);
	this->addChild(lemming);
	lemmings.push_back(lemming);
}

void LemmingGame::InputHandler()
{
    auto keyboardListener = EventListenerKeyboard::create();
    Director::getInstance()->getOpenGLView()->setIMEKeyboardState(true);

    keyboardListener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event){
        keys.push_back(keyCode);
    };
    keyboardListener->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event){
        // remove the key.
        keys.erase(std::remove(keys.begin(), keys.end(),keyCode), keys.end());
    };
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListener,this);
}

bool LemmingGame::isKeyPressed(EventKeyboard::KeyCode code) {
    // Check if the key is pressed
    return std::find(keys.begin(), keys.end(), code) != keys.end();
}

void LemmingGame::update(float delta)
{
    time += delta;
    if (isKeyPressed(EventKeyboard::KeyCode::KEY_ESCAPE))
    {
		keys.clear();
		Director::getInstance()->pushScene(PauseMenu::create());
    }

    if(lemmings.size() < maxNumber &&  time > 1.5f )
    {
        SpawnLemming(spawnLemmingPoint, true);
        time = 0;
    }
    mousePos = Vec2(cursorX,cursorY);
    explode(mousePos,16);

}

void LemmingGame::MouseHandler()
{
        _mouseListener = EventListenerMouse::create();
        _mouseListener->onMouseDown = [this](cocos2d::Event *event) {
        auto *mouseEvent = dynamic_cast<EventMouse *>(event);

         this->cursorX = mouseEvent->getCursorX();
         this->cursorY = mouseEvent->getCursorY();

    };
}

void LemmingGame::explode(Vec2 mousPos, int radius)
{
/*    for (int i = x - radius; i < x + radius; ++i)
    {
        for (int j = y - radius; j < y + radius; ++j)
        {
            if (i >= 0 && i < 30 && j >= 0 && j < 20)
            {
                breakable->removeTileAt(Vec2(i, j));
            }
        }
    }*/
    breakable->removeTileAt(mousPos);
}