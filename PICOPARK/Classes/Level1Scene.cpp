#include "Level1Scene.h"
#include "MyBodyParser.h"
#include "GameScene.h"
#include "Definitions.h"

USING_NS_CC;

Scene* Level1Scene::createScene()
{


    auto scene = Scene::createWithPhysics();
    PhysicsWorld* world = scene->getPhysicsWorld();


    auto layer = Level1Scene::create();
    layer->SetPysicsWorld( scene->getPhysicsWorld( ) );

    scene->addChild(layer);
  
    return scene;
}


// on "init" you need to initialize your instance
bool Level1Scene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Layer::init())
    {

        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

   

    auto ard = Sprite::create("120.png");
    ard->setPosition(250,-30);
    ard->setScale(0.9);
    MyBodyParser::getInstance()->parseJsonFile("nn.json");
    auto ardBody = MyBodyParser::getInstance()->bodyFormJson(ard, "120.png", PhysicsMaterial(0.2, 0.2, 0.2));
    if (ardBody != nullptr) {

        ardBody->setDynamic(false);
        ard->setPhysicsBody(ardBody);
    }
    this->addChild(ard, 1);


    auto bab = Sprite::create("33.png");
    bab->setScale(1.2);
    bab->setPosition(350, 144);
    MyBodyParser::getInstance()->parseJsonFile("kk.json");
    auto babBody = MyBodyParser::getInstance()->bodyFormJson(bab, "33.png", PhysicsMaterial(0.2, 0.2, 0.2));
    if (babBody != nullptr) {

        babBody->setDynamic(false);
        bab->setPhysicsBody(babBody);
    }
    this->addChild(bab, 1);

    auto instructionbackground = Sprite::create("instruction.jpg");
    instructionbackground->setScale(1.0);
    instructionbackground->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(instructionbackground);

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
            event->getCurrentTarget()->runAction(MoveBy::create(0.09f, Vec2(-20, 0)));

            break;
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        case EventKeyboard::KeyCode::KEY_D:
            event->getCurrentTarget()->runAction(MoveBy::create(0.09f, Vec2(20, 0)));
            break;

        case EventKeyboard::KeyCode::KEY_SPACE:
        case EventKeyboard::KeyCode::KEY_W:

            event->getCurrentTarget()->runAction(JumpBy::create(0.5, Vec2(30, 0), 30, 1));
            break;
        case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
        case EventKeyboard::KeyCode::KEY_S:
            event->getCurrentTarget()->runAction(JumpBy::create(0.5, Vec2(-30, 0), 30, 1));
            break;
        }

    };
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListner, pico);
    this->scheduleUpdate();


    Rect frame = Rect(0, 0, 01000, 1000);
    auto followplayer = Follow::create(pico, frame);
    this->runAction(followplayer);

    auto doorbtn = MenuItemImage::create("33.png", "b.png", CC_CALLBACK_1(Level1Scene::GoToGameScene, this));
    doorbtn->setScale(0.5);
    doorbtn->setPosition(450, 144);

    auto door = Menu::create(doorbtn, NULL);
    door->setPosition(Point::ZERO);
    this->addChild(door);

    return true;
}
void Level1Scene::GoToGameScene(cocos2d::Ref* sender)
{
    auto scene = GameScene::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));

}
