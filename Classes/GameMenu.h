//
// Created by Jüne on 14/12/2022.
//

#ifndef GTECH_LEMMINGS_GAMEMENU_H
#define GTECH_LEMMINGS_GAMEMENU_H
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include <iostream>
#include "HelloWorld.h"

class GameMenu : public cocos2d::Scene{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    //Init menu elements
    void InitMenuElement();
    //Scene management
    void Quit(cocos2d::Ref* pSender);
    void CallGameScene();

    CREATE_FUNC(GameMenu);
private:
    //Menu
    cocos2d::Menu *menu;
    //Menu Items's sprite
    cocos2d::MenuItemSprite* playButton;
    cocos2d::MenuItemSprite* settingButton;
    cocos2d::MenuItemSprite* closeButton;
    std::vector<cocos2d::MenuItem*> menuElement;
    //Menu's background
    cocos2d::Sprite* menuBG;
    //Vector for positioning
    cocos2d::Size screenSize;
    cocos2d::Vec2 origin;
    //Mouse event listener
    cocos2d::EventListenerMouse* mouseListener;
};


#endif //GTECH_LEMMINGS_GAMEMENU_H
