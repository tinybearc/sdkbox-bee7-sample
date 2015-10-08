
local MainScene = class("MainScene", cc.load("mvc").ViewBase)

function MainScene:onCreate()
    local bee7

    -- ui

    cc.MenuItemFont:setFontName("Arial")
    local btn = cc.MenuItemFont:create("show game wall"):onClicked(function()
                        print("sdkbox-bee7 showGameWall")
                        bee7:showGameWall()
                    end)
    btn:setEnabled(false)
    cc.Menu:create(btn)
        :move(display.cx, display.cy)
        :addTo(self)
        :alignItemsVerticallyWithPadding(20)

    -- bee7

    bee7 = sdkbox.PluginBee7
    bee7:init()
    bee7:setListener(function(args)
            dump(args, "sdkbox-bee7 callback")
            if args.name == "onAvailableChange" then
                btn:setEnabled(args.available)
            end
        end)

end

return MainScene
