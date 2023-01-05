#ifndef __LEVEL3_SCENE_H__
#define __LEVEL3_SCENE_H__

#include "cocos2d.h"

class Level3Scene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    CREATE_FUNC(Level3Scene);
    
private:
    void SetPysicsWorld(cocos2d::PhysicsWorld *world) { sceneworld = world; };
    void firstground(float dt);
    cocos2d::PhysicsWorld *sceneworld;
    cocos2d::Sprite* pico;
    void GoToMainMenuScene(cocos2d::Ref* sender);



};

#endif // __LEVEL3_SCENE_H__
