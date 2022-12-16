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








    this->addChild(menu);
    return true;
}


void GameMenu::InitMenuElement(){
    menu = Menu::create();
    play    = Sprite::create("assets/Menu/Buttons/Play.png");
    setting = Sprite::create("assets/Menu/Buttons/Settings.png");
    close   = Sprite::create("assets/Menu/Buttons/Close.png");

    auto playButton    = MenuItemSprite::create(play,play, CC_CALLBACK_0(GameMenu::menuItemCallBack, this));
    auto settingButton = MenuItemSprite::create(setting,setting, CC_CALLBACK_0(GameMenu::menuItemCallBack, this));
    auto closeButton   = MenuItemSprite::create(close,close, CC_CALLBACK_1(GameMenu::menuCloseCallback, this));
    menuElement.push_back(closeButton); menuElement.push_back(settingButton); menuElement.push_back(playButton);

    for (int i = 1; i < menuElement.size() + 1; ++i) {
        menuElement[i-1]->setPosition(origin.x  , origin.y + i * 50 - 100);
        menuElement[i-1]->setScale(2);
        menu->addChild(menuElement[i-1]);
    }

}

void GameMenu::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
}

void GameMenu::menuItemCallBack() {
    Director::getInstance()->replaceScene(HelloWorld::create());
}

void GameMenu::MouseOnHover() {

}

auto func = [] () {
    //Lamda expression callback
    //Scene switching
    std::cout << "Hello World";
};