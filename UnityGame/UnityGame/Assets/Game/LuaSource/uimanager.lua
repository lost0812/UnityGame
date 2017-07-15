
local UIPage = require("ui/page/uipage")

local UIManager = Class(function(self)
	self.pages = {}
end)

function UIManager:Initialize()
	self.pageStartMain = self:CreatePage("pagestarttest")
end

function UIManager:CreatePage(name)
	local page = self.pages[name]
	if not page then
		page = require("ui/page/"..name)()
		self.pages[name] = page
	end
	return page
end

function UIManager:OpenPage(name)
	local page = self.pages[name]
	if page then
		page:OnCreate()
		page.window:Show()
	end
end

function UIManager:ClosePage(name)
	local page = self.pages[name]
	if page then
		page.window:Hide()
	end
end

function UIManager:Update(deltaTime)
	for _,v in pairs(self.pages) do
		v:Update(deltaTime)
	end
end

return UIManager()