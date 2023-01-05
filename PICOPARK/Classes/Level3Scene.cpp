#include "Level3Scene.h"
#include "MyBodyParser.h"
#include "Definitions.h"
#include "MainMenuScene.h"

USING_NS_CC;

Scene* Level3Scene::createScene()
{


    auto scene = Scene::createWithPhysics();
    PhysicsWorld* world = scene->getPhysicsWorld();



    auto layer = Level3Scene::create();
    layer->SetPysicsWorld( scene->getPhysicsWorld( ) );

    scene->addChild(layer);
  
    return scene;
}


// on "init" you need to initialize your instance
bool Level3Scene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Layer::init())
    {

        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();



    auto whiteback = Sprite::create("gray.png");
    whiteback->setScale(1.0);
    whiteback->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(whiteback);

    auto ard = Sprite::create("12.png");
    ard->setPosition(280,125);
    ard->setScale(1.9);
    MyBodyParser::getInstance()->parseJsonFile("12.json");
    auto ardBody = MyBodyParser::getInstance()->bodyFormJson(ard, "12.png", PhysicsMaterial(0.2, 0.2, 0.2));
    if (ardBody != nullptr) {

        ardBody->setDynamic(false);
        ard->setPhysicsBody(ardBody);
    }
    this->addChild(ard, 1);





    auto grd3 = Sprite::create("22.png");
    grd3->setPosition(300,120);
    grd3->setScale(1.5);
    grd3->setName("22.png");
    MyBodyParser::getInstance()->parseJsonFile("22.json");
    auto spritegrd3 = MyBodyParser::getInstance()->bodyFormJson(grd3, "22.png", PhysicsMaterial(0.2, 0.2, 0.2));
    spritegrd3->setGravityEnable(false);
    spritegrd3->setDynamic(false);
    spritegrd3->setContactTestBitmask(1);
    spritegrd3->setCollisionBitmask(1);
    spritegrd3->setCategoryBitmask(1);
    spritegrd3->setRotationEnable(0.0f);
    grd3->setPhysicsBody(spritegrd3);
    this->addChild(grd3, 1);

    auto bab = Sprite::create("33.png");
    bab->setScale(1.2);
    bab->setPosition(350, 113);
    MyBodyParser::getInstance()->parseJsonFile("kk.json");
    auto babBody = MyBodyParser::getInstance()->bodyFormJson(bab, "33.png", PhysicsMaterial(0.2, 0.2, 0.2));
    if (babBody != nullptr) {

        babBody->setDynamic(false);
        bab->setPhysicsBody(babBody);
    }
    this->addChild(bab, 1);

   

    auto pico = Sprite::create("pico.png");
    pico->setPosition((Vec2(visibleSize.width * 0.1, visibleSize.height * 0.5)));
    pico->setScale(0.5);
    pico->setName("pico.png");
    MyBodyParser::getInstance()->parseJsonFile("pico.json");
    auto spriteBody= MyBodyParser::getInstance()->bodyFormJson(pico, "pico.png", PhysicsMaterial(0.2, 0.2, 0.2));
    spriteBody->setGravityEnable(true);
    spriteBody->setDynamic(true);
    spriteBody->setContactTestBitmask(1);
    spriteBody->setCollisionBitmask(1);
    spriteBody->setCategoryBitmask(1);
    spriteBody->setRotationEnable(0.0f);
    pico->setPhysicsBody(spriteBody);
    this->addChild(pico, 1);
    
  
    auto eventListner = EventListenerKeyboard::create();
    eventListner->onKeyPressed = [](EventKeyboard::KeyCode KeyCode, Event* event) {
        Vec2 loc = event->getCurrentTarget()->getPosition();
        switch (KeyCode)
        {
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        case EventKeyboard::KeyCode::KEY_A:
            event->getCurrentTarget()->runAction(MoveBy::create(0.09f, Vec2(-4, 0)));

            break;
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        case EventKeyboard::KeyCode::KEY_D:
            event->getCurrentTarget()->runAction(MoveBy::create(0.09f, Vec2(4, 0)));
            break;

        case EventKeyboard::KeyCode::KEY_SPACE:
        case EventKeyboard::KeyCode::KEY_W:

            event->getCurrentTarget()->runAction(JumpBy::create(0.5, Vec2(50, 0), 50, 1));
            break;
        case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
        case EventKeyboard::KeyCode::KEY_S:
            event->getCurrentTarget()->runAction(JumpBy::create(0.5, Vec2(-50, 0), 50, 1));
            break;
        }

    };
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListner, pico);
    this->scheduleUpdate();

    Rect frame = Rect(0,0, 01000, 1000);
    auto followplayer = Follow::create(pico, frame);
    this->runAction(followplayer);


    auto doorbtn = MenuItemImage::create("33.png", "b.png", CC_CALLBACK_1(Level3Scene::GoToMainMenuScene, this));
    doorbtn->setScale(0.5);
    doorbtn->setPosition(430, 114);

    auto door = Menu::create(doorbtn, NULL);
    door->setPosition(Point::ZERO);
    this->addChild(door);
    return true;
}
void Level3Scene::GoToMainMenuScene(cocos2d::Ref* sender)
{
    auto scene = MainMenuScene::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));

}
