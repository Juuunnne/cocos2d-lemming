//
// Created by Jüne on 16/12/2022.
//

#include "PauseMenu.h"
#include "GameMenu.h"
USING_NS_CC;

bool PauseMenu::init()
{
    InitPauseMenuElement();

    this->addChild(pauseMenu);
    return true;
}


void PauseMenu::InitPauseMenuElement()
{
    pauseMenu = Menu::create();
    Size screenSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
	// Create gray background
    bg = LayerColor::create(Color4B(50, 50, 50, 200));
    bg->setContentSize(Size(screenSize.width, screenSize.height));
	this->addChild(bg, -1);

    // Create Menu and its elements
	resumeSprite = Sprite::create("assets/Menu/Buttons/Play.png");
    restartSprite = Sprite::create("assets/Menu/Buttons/Restart.png");
    backToMenuSprite = Sprite::create("assets/Menu/Buttons/Back.png");

    std::vector<MenuItemSprite*> pauseMenuItems;
    pauseMenuItems.push_back(MenuItemSprite::create(resumeSprite, resumeSprite, CC_CALLBACK_0(PauseMenu::CallBackResumeButton,this)));
	pauseMenuItems.push_back(MenuItemSprite::create(restartSprite, restartSprite, CC_CALLBACK_0(PauseMenu::RestartGame, this)));
    pauseMenuItems.push_back(MenuItemSprite::create(backToMenuSprite, backToMenuSprite, CC_CALLBACK_0(PauseMenu::CallBackToMenuButton, this)));

    for (int i = 0; i < pauseMenuItems.size(); ++i) {
        pauseMenuItems[i]->setPosition(origin.x + i * 100 - 150, origin.y );
        pauseMenuItems[i]->setScale(2);
        this->pauseMenu->addChild(pauseMenuItems[i]);
    }
}


void PauseMenu::CallBackResumeButton()
{
    Director::getInstance()->popScene();
}

void PauseMenu::CallBackToMenuButton()
{
	Director::getInstance()->replaceScene(GameMenu::create());
}

void PauseMenu::RestartGame()
{
	Director::getInstance()->replaceScene(LemmingGame::create());
}


