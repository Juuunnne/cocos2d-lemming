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

    this->CreateLemmings(20);

    return true;
}


void LemmingGame::CreateLemmings(int n)
{
    for (int i = 0; i < n; ++i) {
        auto physicsBody = PhysicsBody::createBox(Size(15, 15), PhysicsMaterial(0.1f, 1.0f, 0.0f));
        physicsBody->setDynamic(true);
        physicsBody->setRotationEnable(false);
        cocos2d::Sprite* MySprite = Sprite::create("lemmings.png", Rect(0, 0, 15, 15));
        MySprite->setPosition(Vec2(400, 500));
        MySprite->setScale(4);
        MySprite->addComponent(physicsBody);
        this->addChild(MySprite);
    }
}