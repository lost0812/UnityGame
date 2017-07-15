
local Actor = Class(function(self, inst)
	self.components = {}
end)

local function LoadComponent(name)
    
    if Components[name] == nil then
        Components[name] = require("components/"..name)
        assert(Components[name], "could not load component "..name)
        Components[name].WatchWorldState = ComponentWatchWorldState
        Components[name].StopWatchingWorldState = ComponentStopWatchingWorldState
    end
    return Components[name]
end

function Actor:AddComponent(name)
    local lower_name = string.lower(name)
	if self.components[lower_name] then
		return 
	end
    local cmp = LoadComponent(lower_name)
    assert(cmp, "component ".. name .. " does not exist!")
    local loadedcmp = cmp(self)
    self.components[name] = loadedcmp

end

return Actor