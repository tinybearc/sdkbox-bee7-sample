#include "HelloWorldScene.h"
#include <string>

USING_NS_CC;

#if (COCOS2D_VERSION < 0x00030000)
#define MessageBox CCMessageBox
#endif

using namespace sdkbox;

#include <string>
#include <sstream>

template <typename T>
std::string to_string(T value)
{
    std::ostringstream os ;
    os << value ;
    return os.str() ;
}

static std::string point2String(long points)
{
    return (to_string(points) + " bee7 points");
}
static std::string amount2String(long amount)
{
    return (to_string(amount) + " virtual currency amount");
}

CCScene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    CCScene* scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld* layer = HelloWorld::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

CCScene* HelloWorld::scene()
{
    return HelloWorld::createScene();
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    CCLOG("%s", cocos2dVersion());
    
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    _bee7PointsLabel = nullptr;
    _virtualCurrencyAmountLabel = nullptr;
    _showGameWallButton = nullptr;
    
    Size size = CCDirector::getInstance()->getWinSize();
    // ui
    {
        MenuItemFont::setFontName("Arial");
        _showGameWallButton = MenuItemFont::create("showGameWall", [](Ref*) {
            CCLOG("[Bee7] showGameWall");
            sdkbox::PluginBee7::showGameWall();
        });
        _showGameWallButton->setEnabled(false);
        
        Menu* menu = Menu::create(_showGameWallButton, NULL);
        menu->alignItemsVerticallyWithPadding(20);
        menu->setPosition(size.width/2, size.height/2);
        addChild(menu);
        
        _bee7PointsLabel = Label::createWithSystemFont(point2String(0), "Arial", 32);
        _bee7PointsLabel->setPosition(size.width/2, 100);
        _virtualCurrencyAmountLabel = Label::createWithSystemFont(amount2String(0), "Arial", 32);
        _virtualCurrencyAmountLabel->setPosition(size.width/2, 150);
        
        addChild(_bee7PointsLabel);
        addChild(_virtualCurrencyAmountLabel);
    }
    
    PluginBee7::setListener(this);
    PluginBee7::init();
    
    return true;
}

#pragma mark - Bee7Listener -

void HelloWorld::onAvailableChange(bool available)
{
    CCLOG("Bee7::%s available=%s", __FUNCTION__, available ? "yes" : "no");
    _showGameWallButton->setEnabled(available);
}
void HelloWorld::onVisibleChange(bool available)
{
    CCLOG("Bee7::%s available=%s", __FUNCTION__, available ? "yes" : "no");
}
void HelloWorld::onGameWallWillClose()
{
    CCLOG("Bee7::%s", __FUNCTION__);
}
void HelloWorld::onGiveReward(long bee7Points,
                              long virtualCurrencyAmount,
                              const std::string& appId,
                              bool cappedReward,
                              long campaignId,
                              bool videoReward)
{
    static long points = 0;
    static long amount = 0;
    
    CCLOG("Bee7::%s bee7Points=%ld virtualCurrencyAmount=%ld appId=%s cappedReward=%s campaignId=%ld isVideoReward=%s",
          __FUNCTION__,
          bee7Points,
          virtualCurrencyAmount,
          appId.data(),
          cappedReward ? "yes" : "no",
          campaignId,
          videoReward ? "yes" : "no");
    
    points += bee7Points;
    amount += virtualCurrencyAmount;
    
    _bee7PointsLabel->setString(point2String(points));
    _virtualCurrencyAmountLabel->setString(amount2String(amount));
}
