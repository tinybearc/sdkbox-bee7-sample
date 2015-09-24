#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "PluginBee7/PluginBee7.h"

class HelloWorld : public cocos2d::CCLayer, public sdkbox::Bee7Listener
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* createScene();
    static cocos2d::CCScene* scene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    
    void onAvailableChange(bool available);
    void onVisibleChange(bool available);
    void onGameWallWillClose();
    void onGiveReward(long bee7Points,
                      long virtualCurrencyAmount,
                      const std::string& appId,
                      bool cappedReward,
                      long campaignId,
                      bool videoReward);
    
    cocos2d::Label *_bee7PointsLabel;
    cocos2d::Label *_virtualCurrencyAmountLabel;
    cocos2d::MenuItem *_showGameWallButton;
};

#endif // __HELLOWORLD_SCENE_H__
