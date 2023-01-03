//
// Created by Jüne on 14/12/2022.
//

#include "GameMenu.h"

GameMenu::GameMenu()
{
	this->scene = Scene::create();
	this->settings = new Settings(scene);
	this->game = new LemmingGame();
    this->InitMenuElements();
}

void GameMenu::InitMenuElements()
{
    menu = Menu::create();

    // Load images
    Sprite* play = Sprite::create("assets/Menu/Buttons/Play.png");
    Sprite* play_pressed = Sprite::create("assets/Menu/Buttons/Play_pressed.png");
    Sprite* setting = Sprite::create("assets/Menu/Buttons/Settings.png");
    Sprite* setting_pressed = Sprite::create("assets/Menu/Buttons/Settings_pressed.png");
    Sprite* close = Sprite::create("assets/Menu/Buttons/Close.png");
    Sprite* close_pressed = Sprite::create("assets/Menu/Buttons/Close_pressed.png");
    
	// Close button
    this->menuElements.push_back(MenuItemSprite::create(close, close_pressed, CC_CALLBACK_0(GameMenu::Quit, this)));
	// Settings button
    this->menuElements.push_back(MenuItemSprite::create(setting, setting_pressed, CC_CALLBACK_0(GameMenu::CallSettingsScene, this)));
	// Play button
    this->menuElements.push_back(MenuItemSprite::create(play, play_pressed, CC_CALLBACK_0(GameMenu::CallGameScene, this)));
    
    Size screenSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // Set position and scale of menu items
    for (int i = 0; i < this->menuElements.size(); ++i) {
        this->menuElements[i]->setPosition(origin.x, origin.y + (i + 1) * 70 - 200);
        this->menuElements[i]->setScale(3);
        this->menu->addChild(this->menuElements[i]);
    }
    this->scene->addChild(menu);
    
	// Set background
    this->menuBG = Sprite::create("menuBG.png");
    this->menuBG->setPosition(origin.x + screenSize.width / 2, origin.y + screenSize.height / 2 );
    this->scene->addChild(menuBG, -2);
}

Scene* GameMenu::GetScene()
{
	return this->scene;
}

void GameMenu::Quit()
{
    Director::getInstance()->end();
}

void GameMenu::CallGameScene() {
    Director::getInstance()->replaceScene(LemmingGame::create());
}

void GameMenu::CallSettingsScene() {
    Director::getInstance()->replaceScene(this->settings->GetScene());
}
