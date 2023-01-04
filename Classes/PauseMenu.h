//
// Created by Jüne on 16/12/2022.
//

#ifndef GTECH_LEMMINGS_PAUSEMENU_H
#define GTECH_LEMMINGS_PAUSEMENU_H

#include "cocos2d.h"

class PauseMenu : public cocos2d::Layer{
public:
    CREATE_FUNC(PauseMenu);
    bool init();

    void InitPauseMenuElement();
    void CallBackResumeButton();
    void CallBackToMenuButton();


private:
    cocos2d::Menu * pauseMenu;
    std::vector<cocos2d::MenuItemSprite*> pausemenuElements;
};


#endif //GTECH_LEMMINGS_PAUSEMENU_H
