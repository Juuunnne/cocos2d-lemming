#include "Timer.h"

Timer::Timer()
{
}

Timer::~Timer()
{
}

bool Timer::init()
{

	if (!Scene::init())
	{
		return false;
	}

	visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
	origin = cocos2d::Director::getInstance()->getVisibleOrigin();
	
	timerLabel = cocos2d::Label::createWithTTF("Hello", "fonts/Marker Felt.ttf", 24);
	timerLabel->setPosition(cocos2d::Vec2(100, 100));
	
	this->addChild(timerLabel);
	
	time = 90.f;
	this->schedule(CC_SCHEDULE_SELECTOR(Timer::update), 0.01);
	
	
	
	return true;
}
void Timer::update(float dt)
{
	if (time > 1)
	{
		time -= dt;
		timerLabel->setString(std::to_string(time));
	}
	else
	{
		timerLabel->setString("0");
	}
}