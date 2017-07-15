-- class.lua
-- Compatible with Lua 5.1 (not 5.0).

local function Class(base, _ctor)
    local c = {}    -- a new class instance
	if not _ctor and type(base) == 'function' then
        _ctor = base
        base = nil
    elseif type(base) == 'table' then
        for i,v in pairs(base) do
            c[i] = v
        end
        c._base = base
    end
    
    c.__index = c
    
    local mt = {}
    
	mt.__call = function(class_tbl, ...)
		local obj = {}
		setmetatable(obj, c)
		if c._ctor then
		   c._ctor(obj, ...)
		end
		return obj
	end    
	
    c._ctor = _ctor
    c.is_a = function(self, klass)
        local m = getmetatable(self)
        while m do 
            if m == klass then return true end
            m = m._base
        end
        return false
    end
    setmetatable(c, mt)
    return c
end

return Class