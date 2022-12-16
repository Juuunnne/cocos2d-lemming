//
// Created by Jüne on 14/12/2022.
//

#include "GameMenu.h"
USING_NS_CC;
using namespace ui;

Scene* GameMenu::createScene() {

    return GameMenu::create();
}

bool GameMenu::init() {
    if (!Scene::init())
    {
        return false;
    }
    screenSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();
    this->InitMenuElement();

    this->addChild(menuBG,-2);
    this->addChild(menu);
    return true;
}

void GameMenu::InitMenuElement(){
    menu = Menu::create();
    auto  play    = Sprite::create("assets/Menu/Buttons/Play.png");
    auto  play_pressed  = Sprite::create("assets/Menu/Buttons/Play_pressed.png");
    auto  setting = Sprite::create("assets/Menu/Buttons/Settings.png");
    auto setting_pressed = Sprite::create("assets/Menu/Buttons/Settings_pressed.png");
    auto  close   = Sprite::create("assets/Menu/Buttons/Close.png");
    auto close_pressed = Sprite::create("assets/Menu/Buttons/Close_pressed.png");

     playButton    = MenuItemSprite::create(play,play_pressed, CC_CALLBACK_0(GameMenu::CallGameScene, this));
     settingButton = MenuItemSprite::create(setting,setting_pressed, CC_CALLBACK_0(GameMenu::CallGameScene, this));
     closeButton   = MenuItemSprite::create(close,close_pressed, CC_CALLBACK_1(GameMenu::Quit, this));
    menuElement.push_back(closeButton); menuElement.push_back(settingButton); menuElement.push_back(playButton);

    for (int i = 1; i < menuElement.size() + 1; ++i) {
        menuElement[i-1]->setPosition(origin.x , origin.y + i * 70 - 200);
        menuElement[i-1]->setScale(3);
        menu->addChild(menuElement[i-1]);
    }
    menuBG = Sprite::create("menuBG.png");
    menuBG->setPosition(origin.x + screenSize.width / 2, origin.y + screenSize.height / 2 );
}

void GameMenu::Quit(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
}

void GameMenu::CallGameScene() {
    Director::getInstance()->replaceScene(HelloWorld::create());
}

