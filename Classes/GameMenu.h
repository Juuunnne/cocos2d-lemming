//
// Created by Jüne on 14/12/2022.
//

#ifndef GTECH_LEMMINGS_GAMEMENU_H
#define GTECH_LEMMINGS_GAMEMENU_H
#include "cocos2d.h"
#include "settings.h"
#include "LemmingGame.h"
#include "ui/CocosGUI.h"
#include <iostream>
USING_NS_CC;

class GameMenu
{
public:
	GameMenu();
    void InitMenuElements();
    
    // Scene management
	Scene* GetScene();
    void Quit();
    void CallGameScene();
	void CallSettingsScene();
    
private:
    //Menu
    Menu *menu;
    //Menu Items's sprite
    std::vector<MenuItem*> menuElements;
    //Menu's background
    Sprite* menuBG;
    //Mouse event listener
    EventListenerMouse* mouseListener;

	Scene* scene;
	// Other scenes
	Settings* settings;
	LemmingGame* game;
};


#endif //GTECH_LEMMINGS_GAMEMENU_H
