#include "Settings.h"

bool Settings::init()
{
	this->initMenu();
	
	return true;
}

void Settings::initMenu()
{
	Menu* menu = Menu::create();
	
	Size screenSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// Close button
	Sprite* close = Sprite::create("assets/Menu/Buttons/Back_green.png");
	Sprite* close_pressed = Sprite::create("assets/Menu/Buttons/Back_green_pressed.png");
	MenuItemSprite* closeButton = MenuItemSprite::create(close, close_pressed, CC_CALLBACK_0(Settings::returnToMenu, this));
	closeButton->setPosition(origin.x - 250, origin.y + 250);
	closeButton->setScale(3);
	menu->addChild(closeButton);

	// Resolution button
	Label* resolutionLabel = Label::createWithTTF("> Click here to change resolution <", "fonts/arial.ttf", 24);
	MenuItemLabel* resolutionButton = MenuItemLabel::create(resolutionLabel, CC_CALLBACK_0(Settings::changeWindowSize, this));
	resolutionButton->setPosition(origin.x + 200, origin.y);
	menu->addChild(resolutionButton);
	/*windowSizeLabel = Label::createWithTTF("(" + std::to_string(screenSize.width) + "x" + std::to_string(screenSize.height) + ")", "fonts/arial.ttf", 24);
	windowSizeLabel->setPosition(origin.x + 174, origin.y);
	menu->addChild(windowSizeLabel);*/

	this->addChild(menu);

	// Set background
	Sprite* menuBG = Sprite::create("menuBG.png");
	menuBG->setPosition(origin.x + screenSize.width / 2, origin.y + screenSize.height / 2);
	this->addChild(menuBG, -2);
}

void Settings::returnToMenu() {
	Director::getInstance()->replaceScene(GameMenu::create());
	
	// Save settings
	if (newWindowSize.width != 0 && newWindowSize.height != 0) {
		GLView* gv = Director::getInstance()->getOpenGLView();
		gv->setFrameSize(newWindowSize.width, newWindowSize.height);
		Director::getInstance()->setOpenGLView(gv);
	}
}

void Settings::changeWindowSize()
{
	if (newWindowSize.equals(Size(0, 0))) {
		newWindowSize = Director::getInstance()->getVisibleSize();
	}
	if (newWindowSize.equals(Size(800, 600))) {
		newWindowSize = Size(1024, 768);
	}
	else if (newWindowSize.equals(Size(1024, 768))) {
		newWindowSize = Size(1280, 720);
	}
	else if (newWindowSize.equals(Size(1280, 720))) {
		newWindowSize = Size(1920, 1080);
	}
	else if (newWindowSize.equals(Size(1920, 1080))) {
		newWindowSize = Size(800, 600);
	}
	
	windowSizeLabel = Label::createWithTTF("(" + std::to_string(newWindowSize.width) + "x" + std::to_string(newWindowSize.height) + ")", "fonts/arial.ttf", 24);
}
