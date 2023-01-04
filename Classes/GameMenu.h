//
// Created by Jüne on 14/12/2022.
//

#ifndef GTECH_LEMMINGS_GAMEMENU_H
#define GTECH_LEMMINGS_GAMEMENU_H
#include "cocos2d.h"
#include "Settings.h"
#include "LemmingGame.h"
#include "ui/CocosGUI.h"
#include <iostream>
USING_NS_CC;

class GameMenu : public Scene
{
public:
    // Init
	CREATE_FUNC(GameMenu);
	bool init();
    void InitMenu();
    
    // Scene management
    void Quit();
    void CallGameScene();
	void CallSettingsScene();
    
private:
};


#endif //GTECH_LEMMINGS_GAMEMENU_H
