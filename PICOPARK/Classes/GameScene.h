#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"

class GameScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    CREATE_FUNC(GameScene);
    
private:
    void SetPysicsWorld(cocos2d::PhysicsWorld *world) { sceneworld = world; };
    void firstground(float dt);
    cocos2d::PhysicsWorld *sceneworld;
    cocos2d::Sprite* pico;

    void GoToLevel3Scene(cocos2d::Ref* sender);


};

#endif // __GAME_SCENE_H__
