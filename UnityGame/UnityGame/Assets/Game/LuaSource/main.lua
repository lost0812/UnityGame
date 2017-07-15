--主入口函数。从这里开始lua逻辑

require("fairygui")
require("globalmodule")

function Main()					
	print("lua start!")
	GUIMgr:Initialize()
	GUIMgr:OpenPage("pagestarttest")
end

function Update(deltaTime)
	GUIMgr:Update(deltaTime)
end

--场景切换通知
function OnLevelWasLoaded(level)

end