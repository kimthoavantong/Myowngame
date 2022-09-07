

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "Definitions.h"
#include "GamePlayScene.h"
#include "GameOverScene.h"
#include "ui/CocosGUI.h"

using namespace cocos2d;
using namespace experimental;
using namespace CocosDenshion;

USING_NS_CC;

int scoreOver;
int highScoreOver;
bool getGameOver;
Scene* GameOver::createScene(int score,int highScore,bool setGameover)
{
    highScoreOver = highScore;
    scoreOver = score;
    getGameOver = setGameover;
    return GameOver::create();
}

bool GameOver::init()
{
    if ( !Scene::init() )
    {
        return false;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    CCLOG("Diem %i", scoreOver);
    SimpleAudioEngine::getInstance()->playBackgroundMusic(Music_Background_GameOver, true);

    auto backGround = Sprite::create(BackGround_full_one);
    backGround->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    this->addChild(backGround,-1);

    GameOver::addButtonRestart();
    GameOver::addButtonResume();
    GameOver::addButtonSetting();
    GameOver::addButtonAbouts();
    GameOver::addButtonQuit();
    GameOver::addLabelScore();


    
    return true;
}
void GameOver::addButtonRestart()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    buttonRestart = cocos2d::ui::Button::create(GameOver_Sprite_ButtonRestart);
    buttonRestart->setPosition(Vec2(visibleSize.width * 0.5 + origin.x - buttonRestart->getContentSize().width / 2 - 10,
        origin.y + visibleSize.height / 2 - buttonRestart->getContentSize().height - 20));
    this->addChild(buttonRestart, 1);
    buttonRestart->addTouchEventListener([&](Ref* sender, cocos2d::ui::Widget::TouchEventType type)
        {
            switch (type)
            {
            case cocos2d::ui::Widget::TouchEventType::BEGAN:
            {
                SimpleAudioEngine::getInstance()->stopBackgroundMusic(true);
                SimpleAudioEngine::getInstance()->playEffect(Music_Effect_Click, false);
                break;
            }
            case cocos2d::ui::Widget::TouchEventType::ENDED:
            {
                auto moveSceneGamePlayScene = GamePlayScene::createPhysicsWorld();
                Director::getInstance()->replaceScene(TransitionMoveInR::create(2, moveSceneGamePlayScene));
                break;
            }
            default:
                break;
            }
        });
}

void GameOver::addButtonResume()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    buttonResume = cocos2d::ui::Button::create(GameOver_Sprite_ButtonResume);
    buttonResume->setPosition(Vec2(visibleSize.width * 0.5 + origin.x + buttonResume->getContentSize().width/2 + 10,
        origin.y +  visibleSize.height / 2 - buttonResume->getContentSize().height - 20));
    this->addChild(buttonResume, 1);
    buttonResume->addTouchEventListener([&](Ref* sender, cocos2d::ui::Widget::TouchEventType type)
        {
            switch (type)
            {
            case cocos2d::ui::Widget::TouchEventType::BEGAN:
            {
                SimpleAudioEngine::getInstance()->stopBackgroundMusic(true);
                SimpleAudioEngine::getInstance()->playEffect(Music_Effect_Click, false);
                break;
            }
            case cocos2d::ui::Widget::TouchEventType::ENDED:
            {
                auto moveSceneHelloWorld = HelloWorld::createScene();
                Director::getInstance()->replaceScene(TransitionFade::create(2, moveSceneHelloWorld));
                break;
            }
            default:
                break;
            }
        });
}

void GameOver::addButtonSetting()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    buttonSetting = cocos2d::ui::Button::create(GameOver_Sprite_ButtonSetting);
    buttonSetting->setPosition(Vec2(visibleSize.width / 2 + origin.x - 20 - buttonSetting->getContentSize().width,
        origin.y + visibleSize.height / 2 - 40 - buttonSetting->getContentSize().height * 2));
    this->addChild(buttonSetting, 1);
}
void GameOver::addButtonAbouts()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    buttonAbouts = cocos2d::ui::Button::create(GameOver_Sprite_ButtonAbout);
    buttonAbouts->setPosition(Vec2(visibleSize.width / 2 + origin.x,
        origin.y + visibleSize.height/2 - buttonAbouts->getContentSize().height*2 - 40));
    this->addChild(buttonAbouts, 1);
}
void GameOver::addButtonQuit()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    buttonQuit = cocos2d::ui::Button::create(GameOver_Sprite_ButtonQuit);
    buttonQuit->setPosition(Vec2(visibleSize.width / 2 + origin.x + 20 + buttonQuit->getContentSize().width,
        origin.y + visibleSize.height / 2 - 40 - buttonQuit->getContentSize().height * 2));
    buttonQuit->addTouchEventListener([&](Ref* sender, cocos2d::ui::Widget::TouchEventType type)
        {
            switch (type)
            {
            case cocos2d::ui::Widget::TouchEventType::ENDED:
            {
                SimpleAudioEngine::getInstance()->stopBackgroundMusic(true);
                Director::getInstance()->end();
                break;
            }
            default:
                break;
            }
        });
    this->addChild(buttonQuit, 1);
}

void GameOver::addLabelScore()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();


    if (getGameOver == true)
    {
        String* playScore = String::createWithFormat("GAME OVER");
        gameOver = Label::createWithTTF(playScore->getCString(), Font_Arial, visibleSize.height * 0.2);
        gameOver->setAnchorPoint(Vec2(0.5, 0.5));
        gameOver->setPosition(Vec2(visibleSize.width * 0.5, visibleSize.height * 0.8));
        gameOver->setColor(Color3B::WHITE);
        this->addChild(gameOver);
    }
    else
    {
        String* playScore = String::createWithFormat("YOU WIN");
        labelWin = Label::createWithTTF(playScore->getCString(), Font_Arial, visibleSize.height * 0.2);
        labelWin->setAnchorPoint(Vec2(0.5, 0.5));
        labelWin->setPosition(Vec2(visibleSize.width * 0.5, visibleSize.height * 0.8));
        labelWin->setColor(Color3B::WHITE);
        this->addChild(labelWin);
    }

    String* playScore = String::createWithFormat("Score %i",scoreOver);
    labelScore = Label::createWithTTF(playScore->getCString(), Font_Arial, visibleSize.height * 0.05);
    labelScore->setAnchorPoint(Vec2(0.5, 0.5));
    labelScore->setPosition(Vec2(visibleSize.width * 0.5, visibleSize.height * 0.6));
    labelScore->setColor(Color3B::WHITE);
    this->addChild(labelScore);

    String* playHighScore = String::createWithFormat("HighScore %i", highScoreOver);
    labelScore = Label::createWithTTF(playHighScore->getCString(), Font_Arial, visibleSize.height * 0.05);
    labelScore->setPosition(Vec2(visibleSize.width * 0.5, visibleSize.height * 0.5));
    labelScore->setColor(Color3B::RED);
    this->addChild(labelScore);
}







