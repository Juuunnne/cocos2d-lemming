//
// Created by Jüne on 14/12/2022.
//

#include "GameMenu.h"

bool GameMenu::init()
{
    this->InitMenu();
    
    return true;
}

void GameMenu::InitMenu()
{
    Menu* menu = Menu::create();
	std::vector<MenuItem*> menuItems;

    // Load images
    Sprite* play = Sprite::create("assets/Menu/Buttons/Play.png");
    Sprite* play_pressed = Sprite::create("assets/Menu/Buttons/Play_pressed.png");
    Sprite* setting = Sprite::create("assets/Menu/Buttons/Settings.png");
    Sprite* setting_pressed = Sprite::create("assets/Menu/Buttons/Settings_pressed.png");
    Sprite* close = Sprite::create("assets/Menu/Buttons/Close.png");
    Sprite* close_pressed = Sprite::create("assets/Menu/Buttons/Close_pressed.png");
    
	// Close button
    menuItems.push_back(MenuItemSprite::create(close, close_pressed, CC_CALLBACK_0(GameMenu::Quit, this)));
	// Settings button
    menuItems.push_back(MenuItemSprite::create(setting, setting_pressed, CC_CALLBACK_0(GameMenu::CallSettingsScene, this)));
	// Play button
    menuItems.push_back(MenuItemSprite::create(play, play_pressed, CC_CALLBACK_0(GameMenu::CallGameScene, this)));
    
    Size screenSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // Set position and scale of menu items
    for (int i = 0; i < menuItems.size(); ++i) {
        menuItems[i]->setPosition(origin.x, origin.y + (i + 1) * 70 - 200);
        menuItems[i]->setScale(3);
        menu->addChild(menuItems[i]);
    }
    this->addChild(menu);
    
	// Set background
    Sprite* menuBG = Sprite::create("menuBG.png");
    menuBG->setPosition(origin.x + screenSize.width / 2, origin.y + screenSize.height / 2 );
    addChild(menuBG, -2);
}

void GameMenu::Quit()
{
    Director::getInstance()->end();
}

void GameMenu::CallGameScene() {
    Director::getInstance()->replaceScene(LemmingGame::create());
}

void GameMenu::CallSettingsScene() {
	Director::getInstance()->replaceScene(Settings::create());
}
