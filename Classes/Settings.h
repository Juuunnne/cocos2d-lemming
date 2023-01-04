#pragma once

#include "cocos2d.h"
#include "GameMenu.h"
USING_NS_CC;

class Settings : public Scene
{
public:
	// Init
	CREATE_FUNC(Settings);
	bool init();
	void initMenu();

	void returnToMenu();
	
	// Settings
	void changeWindowSize();

private:
	Size newWindowSize = Size(0, 0);
	Label* windowSizeLabel;
};

