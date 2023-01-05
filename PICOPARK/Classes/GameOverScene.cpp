#include "GameOverScene.h"

USING_NS_CC;

Scene* GameOverScene::createScene()
{
    auto scene = Scene::create();

    auto layer = GameOverScene::create();

    return scene;
}


// on "init" you need to initialize your instance
bool GameOverScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Layer::init())
    {

        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
}
