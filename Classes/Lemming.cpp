#pragma once
#include "Lemming.h"
#include "LemmingGame.h"

#define NORMAL_SPEED 100
#define FAST_SPEED 30


void Lemming::init2(Vec2 position, bool direction)
{
	// Graphics
	this->initWithPolygon(AutoPolygon::generatePolygon("lemmings.png", Rect(0, 0, 15, 15)));
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
	
	bool falling = abs(this->getPhysicsBody()->getVelocity().y) >= 0.2f;
	int actualSpeed = direction ? NORMAL_SPEED : -NORMAL_SPEED;
	this->getPhysicsBody()->setVelocity(Vec2(falling ? 0 : actualSpeed, this->getPhysicsBody()->getVelocity().y));
}

void Lemming::ChangeDir()
{
	this->direction = !this->direction;
}