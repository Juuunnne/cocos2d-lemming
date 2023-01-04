#pragma once
#include "cocos2d.h"
USING_NS_CC;

class Lemming : public Sprite
{
public:
	Lemming(Vec2 position, bool direction);
	~Lemming ();
	
	void Update();
	void ChangeDir();

private:
	bool direction; // false for right, true for left
	MoveBy* moveAction;
};