
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

    local info = cc.MenuItemFont:create("bee7Points=0 virtualCurrencyAmount=0")
    local bee7Points = 0
    local virtualCurrencyAmount = 0

    cc.Menu:create(btn,info)
        :move(display.cx, display.cy)
        :addTo(self)
        :alignItemsVerticallyWithPadding(20)

    -- bee7

    bee7 = sdkbox.PluginBee7
    bee7:init()
    bee7:setListener(function(args)
            dump(args, "sdkbox-bee7 callback")
            local funcname = args.name
            if funcname == "onAvailableChange" then
                btn:setEnabled(args.available)
            elseif funcname == "onGiveReward" then
                bee7Points = bee7Points + args.points
                virtualCurrencyAmount = virtualCurrencyAmount + args.amount
                info:setString("bee7Points=" .. bee7Points .. " virtualCurrencyAmount=" .. virtualCurrencyAmount)
            end
        end)

end

return MainScene
