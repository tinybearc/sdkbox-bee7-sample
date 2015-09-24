
local MainScene = class("MainScene", cc.load("mvc").ViewBase)

--MainScene.RESOURCE_FILENAME = "MainScene.csb"

function MainScene:onCreate()
--    printf("resource node = %s", tostring(self:getResourceNode()))

	local bee7 = sdkbox.PluginBee7
    bee7:init()
    bee7:setListener(function(args)
            dump(args, "sdkbox-bee7 callback")
        end)

    -- ui

    cc.MenuItemFont:setFontName("Arial")
    cc.Menu:create(
                   cc.MenuItemFont:create("show game wall"):onClicked(function()
                        print("sdkbox-fyber requestInterstitial")
                        bee7:showGameWall()
                    end)
                   )
        :move(display.cx, display.cy)
        :addTo(self)
        :alignItemsVerticallyWithPadding(20)

end

return MainScene
