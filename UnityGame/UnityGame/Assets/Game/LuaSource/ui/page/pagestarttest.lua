

local UIPage = require("ui/page/uipage")

local PageStartTest = Class(UIPage, function(self)
	UIPage._ctor(self)
end)

function PageStartTest:OnCreate()
	self:InitWindow("Start", "PageStart")
	local btn = self.panel:GetChild("Btn")
	btn.onClick:Add(function()
		print("Hello World")
	end)
	self.window:Show()
end


return PageStartTest