﻿//this source code was auto-generated by tolua#, do not modify it
using System;
using LuaInterface;

public class FairyGUI_TimersWrap
{
	public static void Register(LuaState L)
	{
		L.BeginClass(typeof(FairyGUI.Timers), typeof(System.Object));
		L.RegFunction("Add", Add);
		L.RegFunction("CallLater", CallLater);
		L.RegFunction("AddUpdate", AddUpdate);
		L.RegFunction("StartCoroutine", StartCoroutine);
		L.RegFunction("Exists", Exists);
		L.RegFunction("Remove", Remove);
		L.RegFunction("Update", Update);
		L.RegFunction("New", _CreateFairyGUI_Timers);
		L.RegFunction("__tostring", Lua_ToString);
		L.RegVar("repeat", get_repeat, set_repeat);
		L.RegVar("time", get_time, set_time);
		L.RegVar("gameObject", get_gameObject, set_gameObject);
		L.RegVar("inst", get_inst, null);
		L.EndClass();
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int _CreateFairyGUI_Timers(IntPtr L)
	{
		try
		{
			int count = LuaDLL.lua_gettop(L);

			if (count == 0)
			{
				FairyGUI.Timers obj = new FairyGUI.Timers();
				ToLua.PushObject(L, obj);
				return 1;
			}
			else
			{
				return LuaDLL.luaL_throw(L, "invalid arguments to ctor method: FairyGUI.Timers.New");
			}
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int Add(IntPtr L)
	{
		try
		{
			int count = LuaDLL.lua_gettop(L);

			if (count == 4 && TypeChecker.CheckTypes(L, 1, typeof(FairyGUI.Timers), typeof(float), typeof(int), typeof(FairyGUI.TimerCallback)))
			{
				FairyGUI.Timers obj = (FairyGUI.Timers)ToLua.ToObject(L, 1);
				float arg0 = (float)LuaDLL.lua_tonumber(L, 2);
				int arg1 = (int)LuaDLL.lua_tonumber(L, 3);
				FairyGUI.TimerCallback arg2 = null;
				LuaTypes funcType4 = LuaDLL.lua_type(L, 4);

				if (funcType4 != LuaTypes.LUA_TFUNCTION)
				{
					 arg2 = (FairyGUI.TimerCallback)ToLua.ToObject(L, 4);
				}
				else
				{
					LuaFunction func = ToLua.ToLuaFunction(L, 4);
					arg2 = DelegateFactory.CreateDelegate(typeof(FairyGUI.TimerCallback), func) as FairyGUI.TimerCallback;
				}

				obj.Add(arg0, arg1, arg2);
				return 0;
			}
			else if (count == 5 && TypeChecker.CheckTypes(L, 1, typeof(FairyGUI.Timers), typeof(float), typeof(int), typeof(FairyGUI.TimerCallback), typeof(object)))
			{
				FairyGUI.Timers obj = (FairyGUI.Timers)ToLua.ToObject(L, 1);
				float arg0 = (float)LuaDLL.lua_tonumber(L, 2);
				int arg1 = (int)LuaDLL.lua_tonumber(L, 3);
				FairyGUI.TimerCallback arg2 = null;
				LuaTypes funcType4 = LuaDLL.lua_type(L, 4);

				if (funcType4 != LuaTypes.LUA_TFUNCTION)
				{
					 arg2 = (FairyGUI.TimerCallback)ToLua.ToObject(L, 4);
				}
				else
				{
					LuaFunction func = ToLua.ToLuaFunction(L, 4);
					arg2 = DelegateFactory.CreateDelegate(typeof(FairyGUI.TimerCallback), func) as FairyGUI.TimerCallback;
				}

				object arg3 = ToLua.ToVarObject(L, 5);
				obj.Add(arg0, arg1, arg2, arg3);
				return 0;
			}
			else
			{
				return LuaDLL.luaL_throw(L, "invalid arguments to method: FairyGUI.Timers.Add");
			}
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int CallLater(IntPtr L)
	{
		try
		{
			int count = LuaDLL.lua_gettop(L);

			if (count == 2 && TypeChecker.CheckTypes(L, 1, typeof(FairyGUI.Timers), typeof(FairyGUI.TimerCallback)))
			{
				FairyGUI.Timers obj = (FairyGUI.Timers)ToLua.ToObject(L, 1);
				FairyGUI.TimerCallback arg0 = null;
				LuaTypes funcType2 = LuaDLL.lua_type(L, 2);

				if (funcType2 != LuaTypes.LUA_TFUNCTION)
				{
					 arg0 = (FairyGUI.TimerCallback)ToLua.ToObject(L, 2);
				}
				else
				{
					LuaFunction func = ToLua.ToLuaFunction(L, 2);
					arg0 = DelegateFactory.CreateDelegate(typeof(FairyGUI.TimerCallback), func) as FairyGUI.TimerCallback;
				}

				obj.CallLater(arg0);
				return 0;
			}
			else if (count == 3 && TypeChecker.CheckTypes(L, 1, typeof(FairyGUI.Timers), typeof(FairyGUI.TimerCallback), typeof(object)))
			{
				FairyGUI.Timers obj = (FairyGUI.Timers)ToLua.ToObject(L, 1);
				FairyGUI.TimerCallback arg0 = null;
				LuaTypes funcType2 = LuaDLL.lua_type(L, 2);

				if (funcType2 != LuaTypes.LUA_TFUNCTION)
				{
					 arg0 = (FairyGUI.TimerCallback)ToLua.ToObject(L, 2);
				}
				else
				{
					LuaFunction func = ToLua.ToLuaFunction(L, 2);
					arg0 = DelegateFactory.CreateDelegate(typeof(FairyGUI.TimerCallback), func) as FairyGUI.TimerCallback;
				}

				object arg1 = ToLua.ToVarObject(L, 3);
				obj.CallLater(arg0, arg1);
				return 0;
			}
			else
			{
				return LuaDLL.luaL_throw(L, "invalid arguments to method: FairyGUI.Timers.CallLater");
			}
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int AddUpdate(IntPtr L)
	{
		try
		{
			int count = LuaDLL.lua_gettop(L);

			if (count == 2 && TypeChecker.CheckTypes(L, 1, typeof(FairyGUI.Timers), typeof(FairyGUI.TimerCallback)))
			{
				FairyGUI.Timers obj = (FairyGUI.Timers)ToLua.ToObject(L, 1);
				FairyGUI.TimerCallback arg0 = null;
				LuaTypes funcType2 = LuaDLL.lua_type(L, 2);

				if (funcType2 != LuaTypes.LUA_TFUNCTION)
				{
					 arg0 = (FairyGUI.TimerCallback)ToLua.ToObject(L, 2);
				}
				else
				{
					LuaFunction func = ToLua.ToLuaFunction(L, 2);
					arg0 = DelegateFactory.CreateDelegate(typeof(FairyGUI.TimerCallback), func) as FairyGUI.TimerCallback;
				}

				obj.AddUpdate(arg0);
				return 0;
			}
			else if (count == 3 && TypeChecker.CheckTypes(L, 1, typeof(FairyGUI.Timers), typeof(FairyGUI.TimerCallback), typeof(object)))
			{
				FairyGUI.Timers obj = (FairyGUI.Timers)ToLua.ToObject(L, 1);
				FairyGUI.TimerCallback arg0 = null;
				LuaTypes funcType2 = LuaDLL.lua_type(L, 2);

				if (funcType2 != LuaTypes.LUA_TFUNCTION)
				{
					 arg0 = (FairyGUI.TimerCallback)ToLua.ToObject(L, 2);
				}
				else
				{
					LuaFunction func = ToLua.ToLuaFunction(L, 2);
					arg0 = DelegateFactory.CreateDelegate(typeof(FairyGUI.TimerCallback), func) as FairyGUI.TimerCallback;
				}

				object arg1 = ToLua.ToVarObject(L, 3);
				obj.AddUpdate(arg0, arg1);
				return 0;
			}
			else
			{
				return LuaDLL.luaL_throw(L, "invalid arguments to method: FairyGUI.Timers.AddUpdate");
			}
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int StartCoroutine(IntPtr L)
	{
		try
		{
			ToLua.CheckArgsCount(L, 2);
			FairyGUI.Timers obj = (FairyGUI.Timers)ToLua.CheckObject(L, 1, typeof(FairyGUI.Timers));
			System.Collections.IEnumerator arg0 = (System.Collections.IEnumerator)ToLua.CheckObject(L, 2, typeof(System.Collections.IEnumerator));
			obj.StartCoroutine(arg0);
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int Exists(IntPtr L)
	{
		try
		{
			ToLua.CheckArgsCount(L, 2);
			FairyGUI.Timers obj = (FairyGUI.Timers)ToLua.CheckObject(L, 1, typeof(FairyGUI.Timers));
			FairyGUI.TimerCallback arg0 = null;
			LuaTypes funcType2 = LuaDLL.lua_type(L, 2);

			if (funcType2 != LuaTypes.LUA_TFUNCTION)
			{
				 arg0 = (FairyGUI.TimerCallback)ToLua.CheckObject(L, 2, typeof(FairyGUI.TimerCallback));
			}
			else
			{
				LuaFunction func = ToLua.ToLuaFunction(L, 2);
				arg0 = DelegateFactory.CreateDelegate(typeof(FairyGUI.TimerCallback), func) as FairyGUI.TimerCallback;
			}

			bool o = obj.Exists(arg0);
			LuaDLL.lua_pushboolean(L, o);
			return 1;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int Remove(IntPtr L)
	{
		try
		{
			ToLua.CheckArgsCount(L, 2);
			FairyGUI.Timers obj = (FairyGUI.Timers)ToLua.CheckObject(L, 1, typeof(FairyGUI.Timers));
			FairyGUI.TimerCallback arg0 = null;
			LuaTypes funcType2 = LuaDLL.lua_type(L, 2);

			if (funcType2 != LuaTypes.LUA_TFUNCTION)
			{
				 arg0 = (FairyGUI.TimerCallback)ToLua.CheckObject(L, 2, typeof(FairyGUI.TimerCallback));
			}
			else
			{
				LuaFunction func = ToLua.ToLuaFunction(L, 2);
				arg0 = DelegateFactory.CreateDelegate(typeof(FairyGUI.TimerCallback), func) as FairyGUI.TimerCallback;
			}

			obj.Remove(arg0);
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int Update(IntPtr L)
	{
		try
		{
			ToLua.CheckArgsCount(L, 1);
			FairyGUI.Timers obj = (FairyGUI.Timers)ToLua.CheckObject(L, 1, typeof(FairyGUI.Timers));
			obj.Update();
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
	static int get_repeat(IntPtr L)
	{
		LuaDLL.lua_pushinteger(L, FairyGUI.Timers.repeat);
		return 1;
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int get_time(IntPtr L)
	{
		LuaDLL.lua_pushnumber(L, FairyGUI.Timers.time);
		return 1;
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int get_gameObject(IntPtr L)
	{
		ToLua.Push(L, FairyGUI.Timers.gameObject);
		return 1;
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int get_inst(IntPtr L)
	{
		ToLua.PushObject(L, FairyGUI.Timers.inst);
		return 1;
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int set_repeat(IntPtr L)
	{
		try
		{
			int arg0 = (int)LuaDLL.luaL_checknumber(L, 2);
			FairyGUI.Timers.repeat = arg0;
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int set_time(IntPtr L)
	{
		try
		{
			float arg0 = (float)LuaDLL.luaL_checknumber(L, 2);
			FairyGUI.Timers.time = arg0;
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e);
		}
	}

	[MonoPInvokeCallbackAttribute(typeof(LuaCSFunction))]
	static int set_gameObject(IntPtr L)
	{
		try
		{
			UnityEngine.GameObject arg0 = (UnityEngine.GameObject)ToLua.CheckUnityObject(L, 2, typeof(UnityEngine.GameObject));
			FairyGUI.Timers.gameObject = arg0;
			return 0;
		}
		catch(Exception e)
		{
			return LuaDLL.toluaL_exception(L, e);
		}
	}
}

