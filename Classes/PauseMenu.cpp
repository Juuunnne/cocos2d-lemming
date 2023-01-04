//
// Created by Jüne on 16/12/2022.
//

#include "PauseMenu.h"
#include "GameMenu.h"
USING_NS_CC;

bool PauseMenu::init()
{
    if (!Layer::init()) return false;
    auto layer = Layer::create();
    InitPauseMenuElement();


    layer->addChild(pauseMenu);
}


void PauseMenu::InitPauseMenuElement()
{
    pauseMenu = Menu::create();
    //Create Menu and its elements
    Sprite* resumeSprite = Sprite::create("assets/Menu/Buttons/Restart.png");
    Sprite* backToMenuSprite = Sprite::create("assets/Menu/Buttons/Back.png");

    this->pausemenuElements.push_back(MenuItemSprite::create(resumeSprite,resumeSprite, CC_CALLBACK_0(PauseMenu::CallBackResumeButton,this)));
    this->pausemenuElements.push_back(MenuItemSprite::create(backToMenuSprite,backToMenuSprite, CC_CALLBACK_0(PauseMenu::CallBackToMenuButton,
                                                                                                               this)));

    for (int i = 0; i < pausemenuElements.size(); ++i) {
        this->pausemenuElements[i]->setPosition(Vec2(50,100 +  i*10));
        this->pausemenuElements[i]->setScale(2);
        this->pauseMenu->addChild(pausemenuElements[i]);
    }

}


void PauseMenu::CallBackResumeButton()
{
    Director::getInstance()->resume();
}

void PauseMenu::CallBackToMenuButton()
{
    GameMenu menu;
    Director::getInstance()->replaceScene(menu.GetScene());
}




