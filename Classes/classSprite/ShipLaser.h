﻿

#ifndef __SHIPLASER_H__
#define __SHIPLASER_H__

#include "cocos2d.h"
using namespace cocos2d;
USING_NS_CC;

class ShipLaser : public cocos2d::Node
{
public:
    static ShipLaser* createShipLaser(int a);
    virtual bool init();

    Sprite* spriteShipLaser;
    Animation* createAnimation(std::string tenFrame, int soFrame, float delay);
    

    PhysicsBody* physicsLaser;
    void spriteMoveFinished(Node* sender);
    void animateNo();
    CREATE_FUNC(ShipLaser);

};

#endif // __ShipLaser_H__
