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

    void InitMenuElement();
    void EventManager();
    void menuCloseCallback(cocos2d::Ref* pSender);
    void menuItemCallBack();
    void MouseOnHover();

    CREATE_FUNC(GameMenu);
private:
    //Menu
    cocos2d::Menu *menu;
    //Menu Items's sprite
    cocos2d::Sprite* play;
    cocos2d::Sprite* setting;
    cocos2d::Sprite* close;
    std::vector<cocos2d::MenuItem*> menuElement;
    //Vector for positioning
    cocos2d::Vec2 buttonPosition;
    cocos2d::Size screenSize;
    cocos2d::Vec2 origin;
    //Mouse event listener
    cocos2d::EventListenerMouse* mouseListner;
};


#endif //GTECH_LEMMINGS_GAMEMENU_H
