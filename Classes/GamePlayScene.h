﻿
#ifndef __GamePlayScene_SCENE_H__
#define __GamePlayScene_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "classSprite/ShipLaser.h"
#include "classSprite/Ship.h"
#include "classSprite/EnemyObject.h"

USING_NS_CC;

class GamePlayScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createPhysicsWorld();

    virtual bool init();
    
    cocos2d::ui::Button* buttonBanDan;


    Ship* spriteShip;
    ShipLaser* spriteShipLaser1;
    BossOne* bossSprite1;
    BomS* bossBomS;
    void updateEnemy(float);

    cocos2d::Sprite* backGround1;
    cocos2d::Sprite* backGround2;
    cocos2d::Sprite* iBackGround1;
    cocos2d::Sprite* iBackGround2;
    cocos2d::Sprite* iBackGround3;
    cocos2d::Sprite* iBackGround4;
    cocos2d::Sprite* iBackGround5;
    cocos2d::Sprite* spriteLvDan1;
    cocos2d::Sprite* spriteTarget;

    void addLvDan(int a, int b);
    bool isKeyPressed(cocos2d::EventKeyboard::KeyCode);

    virtual void update(float delta);

    
    void keyboard(float delta);
    bool onContactBegin1(cocos2d::PhysicsContact& contact);

    void createDan();
    void createPlayer();
    void createTarget();
    void createButtonBanDan();
    void addLabel();
    void spriteMoveFinished(Node* sender);
    
    int checkMan = 0 ;
    void createEnemyMan1();
    void createEnemyMan2();
    void createBoss1();

    int x1; int y1; // tọa độ add phần quà khi quái chết
    bool check = false; // check để add qua
    int lvDan = 1;
    int mang = 3;
    bool setGameOver;
    void addDanBoss1(float dt);

    CREATE_FUNC(GamePlayScene);
    /*void tick(float dt);*/

private:
    static std::map<cocos2d::EventKeyboard::KeyCode,
        std::chrono::high_resolution_clock::time_point> keys;
    

    cocos2d::Label* labelDiem;
    cocos2d::Label* labelhighScore;
    cocos2d::Label* labelMang;
    cocos2d::Label* labelLvDan;
    int iHighScore = 0;
    int diem;
    
    
    cocos2d::PhysicsWorld* world;

    void setPhysicsWorld(PhysicsWorld* m_world)
    {
        world = m_world;
    }
};

#endif // __HELLOWORLD_SCENE_H__
