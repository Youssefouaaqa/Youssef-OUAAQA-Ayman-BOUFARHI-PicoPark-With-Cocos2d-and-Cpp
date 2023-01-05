#include "MainMenuScene.h"
#include "Level1Scene.h"
#include "Definitions.h"

USING_NS_CC;

Scene* MainMenuScene::createScene()
{
    auto scene = Scene::create();

    auto layer = MainMenuScene::create();

    scene->addChild(layer);

    return scene;
}


// on "init" you need to initialize  your instance
bool MainMenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Layer::init())
    {

        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    //background
    auto background = Sprite::create("newback.jpg");
    background->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(background);
    //playItem

    auto playbtn = MenuItemImage::create ("playbttn.png","playbttnclicked.png", CC_CALLBACK_1(MainMenuScene::GoToLevel1Scene, this));
    playbtn->setScale(0.5);
    playbtn->setPosition( Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y) );

    auto menu = Menu::create(playbtn, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);

    return true;
}
 

void MainMenuScene::GoToLevel1Scene(cocos2d::Ref* sender)
{
    auto scene = Level1Scene::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));

}