#pragma once
#include "Lemming.h"

#define NORMAL_SPEED 10
#define FAST_SPEED 30

Lemming::Lemming(Vec2 position, bool direction)
{
	this->initWithFile("lemmings.png");
	this->setTextureRect(Rect(0, 0, 15, 15));
	this->setPosition(position);
	this->direction = direction;
	this->Update();
}

Lemming::~Lemming()
{
}

void Lemming::Update()
{
	moveAction = MoveBy::create(1, Vec2((direction ? -1 : 1) * NORMAL_SPEED, 0));
	this->runAction(this->moveAction);
}

void Lemming::ChangeDir()
{
	this->direction = !this->direction;
}