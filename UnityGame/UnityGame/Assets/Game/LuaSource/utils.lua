
local Actor= require("actor")
local  Util = Class(function(self)

	self.prefabs = {}
	end)

function Util:SpawnPrefab(name)
	if self.prefas[name] then
		return self.prefas[name]
	end
	local prefab = require("prefab../"..name)
	local inst = GameInterface.CreateEntity(prefab.resPath)
	local actor = Actor(inst)
	GActorManager:AddActor(actor)
end

return Util