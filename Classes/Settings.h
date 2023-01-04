#pragma once

#include "cocos2d.h"
USING_NS_CC;

class Settings
{
public:
    Settings(Scene* callBackScene);
	
	void CallBackScene();
	Scene* GetScene();

private:
	Scene* scene;
	Scene* callBackScene;
};

