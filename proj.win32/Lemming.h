#pragma once
#include "cocos2d.h"

class Lemming : public cocos2d::Sprite
{
public:
	Lemming(std::string filename, cocos2d::Vec2 position, bool direction);
	~Lemming ();
	
	void Update();
	void ChangeDir();

private:
	bool direction; // false for right, true for left
	cocos2d::MoveBy* moveAction;
};