

local SortOrder = 
{
	["common"] = 1,
	["alert"] = 2,
}

local UIPage = Class(function(self)
	self.window = nil
	self.panel = nil
end)

function UIPage:InitWindow(packageName, componentName)
	local UIPackage = FairyGUI.UIPackage
	local GRoot = FairyGUI.GRoot
	UIPackage.AddPackage("UIProject/"..packageName)
	--适配
	GRoot.inst:SetContentScaleFactor(1366, 768)
	local panel = UIPackage.CreateObject(packageName, componentName)
	panel:SetSize(GRoot.inst.width, GRoot.inst.height)

	local uiWindow = RPGGame.UIWindow.New()
	uiWindow.contentPane = panel
	uiWindow.WindowName = componentName
	self.window = uiWindow
	self.panel = panel
	self.window.onInit = function() self:OnInit() end
	self.window.onHide = function() self:OnHide() end
	self.window.onShown = function() self:OnShown() end
end

function UIPage:OnCreate()

end

function UIPage:OnShown()

end

function UIPage:OnHide()

end

function UIPage:OnInit()
	
end

function UIPage:Update(deltaTie)

end

return UIPage