
local ActorManager = Class(function(self)
	self.actors = {}
	end)

function ActorManager:AddActor(actor)
	if self.actors[actor] then 
		return 
	end
	table.insert(self.actors, actor)
end

return ActorManager