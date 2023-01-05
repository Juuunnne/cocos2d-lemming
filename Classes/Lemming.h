#pragma once
#include "cocos2d.h"
USING_NS_CC;

class Lemming : public Sprite
{
public:
	CREATE_FUNC(Lemming);
	bool init() { return true; };
	void init2(Vec2 position, bool direction);
	
	void update(float dt);
	void ChangeDir();

private:
	int currSpriteFrame;
	int actualFrame;

	bool direction; // false for left, true for right
	float speed;
};