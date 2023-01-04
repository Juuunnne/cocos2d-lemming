#pragma once

#include "cocos2d.h"

class Timer : public cocos2d::Scene
{
public:
	Timer();
	~Timer();
	
	virtual bool init();
	
	virtual void update(float dt);

	CREATE_FUNC(Timer);
	
private:
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	cocos2d::Label* timerLabel;
	float time;
};
