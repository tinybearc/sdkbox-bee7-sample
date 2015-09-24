#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    auto size = Director::getInstance()->getWinSize();
    MenuItemFont::setFontName("Arial");
    // ui
    {
        Menu* menu = Menu::create(
              MenuItemFont::create("Plugin", [](Ref*) {
                    CCLOG("[Plugin]");
                }),
              NULL);
        menu->alignItemsVerticallyWithPadding(20);
        menu->setPosition(size.width/2, size.height/2);
        addChild(menu);

    }
//    PluginX::init();
//    PluginX::setListener(x);
    
    return true;
}
