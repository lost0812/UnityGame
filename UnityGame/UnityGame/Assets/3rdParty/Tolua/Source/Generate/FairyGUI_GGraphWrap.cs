﻿//this source code was auto-generated by tolua#, do not modify it
using System;
using LuaInterface;

public class FairyGUI_GGraphWrap
{
	public static void Register(LuaState L)
	{
		L.BeginClass(typeof(FairyGUI.GGraph), typeof(FairyGUI.GObject));
		L.RegFunction("ReplaceMe", ReplaceMe);
		L.RegFunction("AddBeforeMe", AddBeforeMe);
		L.RegFunction("AddAfterMe", AddAfterMe);
		L.RegFunction("SetNativeObject", SetNativeObject);
		L.RegFunction("DrawRect", DrawRect);
		L.RegFunction("DrawEllipse", DrawEllipse);
		L.RegFunction("Setup_BeforeAdd", Setup_BeforeAdd);
		L.RegFunction("New", _CreateFairyGUI_GGraph);
		L.RegFunction("__tostring", Lua_ToString);
		L.RegVar("color", get_color, set_color);
		L.RegVar("shape", get_shape, null);
		L.EndClass();
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int _CreateFairyGUI_GGraph(IntPtr L)
	{
		try
		{
			int count = LuaDLL.lua_gettop(L);

			if (count == 0)
			{
				FairyGUI.GGraph obj = new FairyGUI.GGraph();
				ToLua.PushObject(L, obj);
				return 1;
			}
			else
			{
				return LuaDLL.luaL_throw(L, "invalid arguments to ctor method: FairyGUI.GGraph.New");
			}
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int ReplaceMe(IntPtr L)
	{
		try
		{
			ToLua.CheckArgsCount(L, 2);
			FairyGUI.GGraph obj = (FairyGUI.GGraph)ToLua.CheckObject(L, 1, typeof(FairyGUI.GGraph));
			FairyGUI.GObject arg0 = (FairyGUI.GObject)ToLua.CheckObject(L, 2, typeof(FairyGUI.GObject));
			obj.ReplaceMe(arg0);
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int AddBeforeMe(IntPtr L)
	{
		try
		{
			ToLua.CheckArgsCount(L, 2);
			FairyGUI.GGraph obj = (FairyGUI.GGraph)ToLua.CheckObject(L, 1, typeof(FairyGUI.GGraph));
			FairyGUI.GObject arg0 = (FairyGUI.GObject)ToLua.CheckObject(L, 2, typeof(FairyGUI.GObject));
			obj.AddBeforeMe(arg0);
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int AddAfterMe(IntPtr L)
	{
		try
		{
			ToLua.CheckArgsCount(L, 2);
			FairyGUI.GGraph obj = (FairyGUI.GGraph)ToLua.CheckObject(L, 1, typeof(FairyGUI.GGraph));
			FairyGUI.GObject arg0 = (FairyGUI.GObject)ToLua.CheckObject(L, 2, typeof(FairyGUI.GObject));
			obj.AddAfterMe(arg0);
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int SetNativeObject(IntPtr L)
	{
		try
		{
			ToLua.CheckArgsCount(L, 2);
			FairyGUI.GGraph obj = (FairyGUI.GGraph)ToLua.CheckObject(L, 1, typeof(FairyGUI.GGraph));
			FairyGUI.DisplayObject arg0 = (FairyGUI.DisplayObject)ToLua.CheckObject(L, 2, typeof(FairyGUI.DisplayObject));
			obj.SetNativeObject(arg0);
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int DrawRect(IntPtr L)
	{
		try
		{
			ToLua.CheckArgsCount(L, 6);
			FairyGUI.GGraph obj = (FairyGUI.GGraph)ToLua.CheckObject(L, 1, typeof(FairyGUI.GGraph));
			float arg0 = (float)LuaDLL.luaL_checknumber(L, 2);
			float arg1 = (float)LuaDLL.luaL_checknumber(L, 3);
			int arg2 = (int)LuaDLL.luaL_checknumber(L, 4);
			UnityEngine.Color arg3 = ToLua.ToColor(L, 5);
			UnityEngine.Color arg4 = ToLua.ToColor(L, 6);
			obj.DrawRect(arg0, arg1, arg2, arg3, arg4);
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int DrawEllipse(IntPtr L)
	{
		try
		{
			ToLua.CheckArgsCount(L, 4);
			FairyGUI.GGraph obj = (FairyGUI.GGraph)ToLua.CheckObject(L, 1, typeof(FairyGUI.GGraph));
			float arg0 = (float)LuaDLL.luaL_checknumber(L, 2);
			float arg1 = (float)LuaDLL.luaL_checknumber(L, 3);
			UnityEngine.Color arg2 = ToLua.ToColor(L, 4);
			obj.DrawEllipse(arg0, arg1, arg2);
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int Setup_BeforeAdd(IntPtr L)
	{
		try
		{
			ToLua.CheckArgsCount(L, 2);
			FairyGUI.GGraph obj = (FairyGUI.GGraph)ToLua.CheckObject(L, 1, typeof(FairyGUI.GGraph));
			FairyGUI.Utils.XML arg0 = (FairyGUI.Utils.XML)ToLua.CheckObject(L, 2, typeof(FairyGUI.Utils.XML));
			obj.Setup_BeforeAdd(arg0);
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int Lua_ToString(IntPtr L)
	{
		object obj = ToLua.ToObject(L, 1);

		if (obj != null)
		{
			LuaDLL.lua_pushstring(L, obj.ToString());
		}
		else
		{
			LuaDLL.lua_pushnil(L);
		}

		return 1;
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int get_color(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			FairyGUI.GGraph obj = (FairyGUI.GGraph)o;
			UnityEngine.Color ret = obj.color;
			ToLua.Push(L, ret);
			return 1;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index color on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int get_shape(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			FairyGUI.GGraph obj = (FairyGUI.GGraph)o;
			FairyGUI.Shape ret = obj.shape;
			ToLua.PushObject(L, ret);
			return 1;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index shape on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int set_color(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			FairyGUI.GGraph obj = (FairyGUI.GGraph)o;
			UnityEngine.Color arg0 = ToLua.ToColor(L, 2);
			obj.color = arg0;
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index color on a nil value" : e.Message);
		}
	}
}
