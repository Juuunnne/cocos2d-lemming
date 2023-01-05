//
// Created by Jüne on 16/12/2022.
//

#ifndef GTECH_LEMMINGS_PAUSEMENU_H
#define GTECH_LEMMINGS_PAUSEMENU_H

#include "cocos2d.h"

class PauseMenu : public cocos2d::Scene
{
public:
    CREATE_FUNC(PauseMenu);
    bool init();

    void InitPauseMenuElement();
    
    void CallBackResumeButton();
    void CallBackToMenuButton();

	void RestartGame();

private:
    cocos2d::Menu * pauseMenu;
	cocos2d::LayerColor* bg;
    cocos2d::Sprite* resumeSprite;
    cocos2d::Sprite* restartSprite;
    cocos2d::Sprite* backToMenuSprite;
};


#endif //GTECH_LEMMINGS_PAUSEMENU_H
