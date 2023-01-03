#include "Settings.h"

Settings::Settings(Scene* callBackScene)
{
	this->callBackScene = callBackScene;

	auto dirs = Director::getInstance();
	Size visibleSize = dirs->getVisibleSize();

	scene = Scene::create();
}

void Settings::CallBackScene()
{
	Director::getInstance()->replaceScene(this->callBackScene);
}

Scene* Settings::GetScene()
{
	return scene;
}