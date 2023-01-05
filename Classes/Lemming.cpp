#pragma once
#include "Lemming.h"
#include "LemmingGame.h"

#define NORMAL_SPEED 75.0f

void Lemming::init2(Vec2 position, bool direction)
{
	// Graphics
	this->initWithFile("lemmings.png");
	this->setTextureRect(Rect(0, 0, 15, 15));
	this->setScale(MAP_SCALE);

	// Physics
	PhysicsBody* physicsBody = PhysicsBody::createBox(Size(4, 9), PhysicsMaterial(1.0f, 0.4f, 0.0f), Vec2(1, 2));
	physicsBody->setDynamic(true);
	physicsBody->setRotationEnable(false);
	
	this->addComponent(physicsBody);
	
	// Other
	this->setPosition(position);
	this->direction = direction;

}

void Lemming::update(float dt)
{	
	actualFrame = (actualFrame + 1) % 10;
	if (actualFrame == 0)
	{
		currSpriteFrame = (currSpriteFrame + 1) % 8;
		this->setTextureRect(Rect(currSpriteFrame * 20, 0, 15, 15));
	}

	bool falling = abs(this->getPhysicsBody()->getVelocity().y) >= 0.2f;
	if (!falling && speed < NORMAL_SPEED) speed = direction ? NORMAL_SPEED : -NORMAL_SPEED;
	else speed *= 0.97f;
	this->getPhysicsBody()->setVelocity(Vec2(speed, this->getPhysicsBody()->getVelocity().y));
}

void Lemming::ChangeDir()
{
	this->direction = !this->direction;
}