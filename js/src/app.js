
var HelloWorldLayer = cc.Layer.extend({
    showbtn:null,
    ctor:function () {
        //////////////////////////////
        // 1. super init first
        this._super();

        /////////////////////////////
        // 2. add a menu item with "X" image, which is clicked to quit the program
        //    you may modify it.
        // ask the window size
        var size = cc.winSize;

        // ui

        console.log("sdkbox-bee7: init");

        cc.MenuItemFont.setFontName('Arial');
        cc.MenuItemFont.setFontSize(32);

        showbtn = new cc.MenuItemFont("show game wall", this.showGameWallTest, this);
        showbtn.setEnabled(false);
        var menu = new cc.Menu(showbtn);
        menu.setPosition(size.width/2, size.height/2);
        menu.alignItemsVerticallyWithPadding(20);
        this.addChild(menu);

        // bee7 init
        sdkbox.PluginBee7.init();
        sdkbox.PluginBee7.setListener({
            onGiveReward : function (bee7Points, virtualCurrencyAmount, appId, cappedReward, campaignId, videoReward) {
                var msg =   " bee7Points=" + bee7Points +
                            " virtualCurrencyAmount=" + virtualCurrencyAmount +
                            " appId=" + appId;
                console.log("sdkbox-bee7 cb [onGiveReward]" + msg);
            },
            onAvailableChange : function  (available) {
                showbtn.setEnabled(available);
            }
            });

        return true;
    },
    showGameWallTest:function(sender) {
        console.log("sdkbox-bee7: show game wall");
        sdkbox.PluginBee7.showGameWall();
    }
});

var HelloWorldScene = cc.Scene.extend({
    onEnter:function () {
        this._super();
        var layer = new HelloWorldLayer();
        this.addChild(layer);
    }
});

