﻿//this source code was auto-generated by tolua#, do not modify it
using System;
using LuaInterface;

public class RPGGame_UIWindowWrap
{
	public static void Register(LuaState L)
	{
		L.BeginClass(typeof(RPGGame.UIWindow), typeof(FairyGUI.Window));
		L.RegFunction("New", _CreateRPGGame_UIWindow);
		L.RegFunction("__tostring", Lua_ToString);
		L.RegVar("onInit", get_onInit, set_onInit);
		L.RegVar("onShow", get_onShow, set_onShow);
		L.RegVar("onHide", get_onHide, set_onHide);
		L.RegVar("WindowName", get_WindowName, set_WindowName);
		L.RegFunction("UIWindowCallBack", RPGGame_UIWindow_UIWindowCallBack);
		L.EndClass();
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int _CreateRPGGame_UIWindow(IntPtr L)
	{
		try
		{
			int count = LuaDLL.lua_gettop(L);

			if (count == 0)
			{
				RPGGame.UIWindow obj = new RPGGame.UIWindow();
				ToLua.PushObject(L, obj);
				return 1;
			}
			else
			{
				return LuaDLL.luaL_throw(L, "invalid arguments to ctor method: RPGGame.UIWindow.New");
			}
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
	static int get_onInit(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			RPGGame.UIWindow obj = (RPGGame.UIWindow)o;
			RPGGame.UIWindow.UIWindowCallBack ret = obj.onInit;
			ToLua.Push(L, ret);
			return 1;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index onInit on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int get_onShow(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			RPGGame.UIWindow obj = (RPGGame.UIWindow)o;
			RPGGame.UIWindow.UIWindowCallBack ret = obj.onShow;
			ToLua.Push(L, ret);
			return 1;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index onShow on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int get_onHide(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			RPGGame.UIWindow obj = (RPGGame.UIWindow)o;
			RPGGame.UIWindow.UIWindowCallBack ret = obj.onHide;
			ToLua.Push(L, ret);
			return 1;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index onHide on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int get_WindowName(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			RPGGame.UIWindow obj = (RPGGame.UIWindow)o;
			string ret = obj.WindowName;
			LuaDLL.lua_pushstring(L, ret);
			return 1;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index WindowName on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int set_onInit(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			RPGGame.UIWindow obj = (RPGGame.UIWindow)o;
			RPGGame.UIWindow.UIWindowCallBack arg0 = null;
			LuaTypes funcType2 = LuaDLL.lua_type(L, 2);

			if (funcType2 != LuaTypes.LUA_TFUNCTION)
			{
				 arg0 = (RPGGame.UIWindow.UIWindowCallBack)ToLua.CheckObject(L, 2, typeof(RPGGame.UIWindow.UIWindowCallBack));
			}
			else
			{
				LuaFunction func = ToLua.ToLuaFunction(L, 2);
				arg0 = DelegateFactory.CreateDelegate(typeof(RPGGame.UIWindow.UIWindowCallBack), func) as RPGGame.UIWindow.UIWindowCallBack;
			}

			obj.onInit = arg0;
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index onInit on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int set_onShow(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			RPGGame.UIWindow obj = (RPGGame.UIWindow)o;
			RPGGame.UIWindow.UIWindowCallBack arg0 = null;
			LuaTypes funcType2 = LuaDLL.lua_type(L, 2);

			if (funcType2 != LuaTypes.LUA_TFUNCTION)
			{
				 arg0 = (RPGGame.UIWindow.UIWindowCallBack)ToLua.CheckObject(L, 2, typeof(RPGGame.UIWindow.UIWindowCallBack));
			}
			else
			{
				LuaFunction func = ToLua.ToLuaFunction(L, 2);
				arg0 = DelegateFactory.CreateDelegate(typeof(RPGGame.UIWindow.UIWindowCallBack), func) as RPGGame.UIWindow.UIWindowCallBack;
			}

			obj.onShow = arg0;
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index onShow on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int set_onHide(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			RPGGame.UIWindow obj = (RPGGame.UIWindow)o;
			RPGGame.UIWindow.UIWindowCallBack arg0 = null;
			LuaTypes funcType2 = LuaDLL.lua_type(L, 2);

			if (funcType2 != LuaTypes.LUA_TFUNCTION)
			{
				 arg0 = (RPGGame.UIWindow.UIWindowCallBack)ToLua.CheckObject(L, 2, typeof(RPGGame.UIWindow.UIWindowCallBack));
			}
			else
			{
				LuaFunction func = ToLua.ToLuaFunction(L, 2);
				arg0 = DelegateFactory.CreateDelegate(typeof(RPGGame.UIWindow.UIWindowCallBack), func) as RPGGame.UIWindow.UIWindowCallBack;
			}

			obj.onHide = arg0;
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index onHide on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int set_WindowName(IntPtr L)
	{
		object o = null;

		try
		{
			o = ToLua.ToObject(L, 1);
			RPGGame.UIWindow obj = (RPGGame.UIWindow)o;
			string arg0 = ToLua.CheckString(L, 2);
			obj.WindowName = arg0;
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e, o == null ? "attempt to index WindowName on a nil value" : e.Message);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int RPGGame_UIWindow_UIWindowCallBack(IntPtr L)
	{
		try
		{
			LuaFunction func = ToLua.CheckLuaFunction(L, 1);
			Delegate arg1 = DelegateFactory.CreateDelegate(typeof(RPGGame.UIWindow.UIWindowCallBack), func);
			ToLua.Push(L, arg1);
			return 1;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e);
		}
	}
}

