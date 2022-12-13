#pragma once
#include "Lemming.h"

#define NORMAL_SPEED 10
#define FAST_SPEED 30

Lemming::Lemming(std::string filename, cocos2d::Vec2 position, bool direction)
{
	this->initWithFile(filename);
	this->setPosition(position);
	this->direction = direction;
	this->Update();
}

Lemming::~Lemming()
{
}

void Lemming::Update()
{
	moveAction = cocos2d::MoveBy::create(1, cocos2d::Vec2((direction ? -1 : 1) * NORMAL_SPEED, 0));
	this->runAction(this->moveAction);
}

void Lemming::ChangeDir()
{
	this->direction = !this->direction;
}