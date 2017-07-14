﻿using UnityEngine;
using System;
using System.Collections.Generic;
using LuaInterface;

using BindType = ToLuaMenu.BindType;

public static class CustomSettings
{
    public static string saveDir = Application.dataPath + "/3rdParty/Tolua/Source/Generate/";
    public static string luaDir = Application.dataPath + "/3rdParty/Tolua/Lua/";
    public static string toluaBaseType = Application.dataPath + "/3rdParty/Tolua/ToLua/BaseType/";
    public static string toluaLuaDir = Application.dataPath + "/3rdParty/Tolua/ToLua/Lua";

    //导出时强制做为静态类的类型(注意customTypeList 还要添加这个类型才能导出)
    //unity 有些类作为sealed class, 其实完全等价于静态类
    public static List<Type> staticClassTypes = new List<Type>
    {        
        typeof(UnityEngine.Application),
        typeof(UnityEngine.Time),
        typeof(UnityEngine.Screen),
        typeof(UnityEngine.SleepTimeout),
        typeof(UnityEngine.Input),
        typeof(UnityEngine.Resources),
        typeof(UnityEngine.Physics),
        typeof(UnityEngine.RenderSettings),
        typeof(UnityEngine.QualitySettings),
    };

    //附加导出委托类型(在导出委托时, customTypeList 中牵扯的委托类型都会导出， 无需写在这里)
    public static DelegateType[] customDelegateList = 
    {        
        _DT(typeof(Action)),        
        _DT(typeof(UnityEngine.Events.UnityAction)),
        _DT(typeof(FairyGUI.EventCallback1)),
    };

    //在这里添加你要导出注册到lua的类型列表
    public static BindType[] customTypeList = 
    {                
        //------------------------为例子导出--------------------------------
        //_GT(typeof(TestEventListener)),                
        //_GT(typeof(TestAccount)),
        //_GT(typeof(Dictionary<int, TestAccount>)).SetLibName("AccountMap"),                
        //_GT(typeof(KeyValuePair<int, TestAccount>)),    
        //-------------------------------------------------------------------        
                                       
        _GT(typeof(Debugger)),                       
                                       
        _GT(typeof(Component)),
        _GT(typeof(Behaviour)),
        _GT(typeof(MonoBehaviour)),        
        _GT(typeof(GameObject)),
        _GT(typeof(Transform)),
        _GT(typeof(TrackedReference)),
        _GT(typeof(Application)),
        _GT(typeof(Physics)),
        _GT(typeof(Collider)),
        _GT(typeof(Time)),        
        _GT(typeof(Texture)),
        _GT(typeof(Texture2D)),
        _GT(typeof(Shader)),
        _GT(typeof(Material)),
        _GT(typeof(Renderer)),
        _GT(typeof(WWW)),
        _GT(typeof(Screen)),
        _GT(typeof(Camera)),
        _GT(typeof(CameraClearFlags)),
        _GT(typeof(AudioClip)),
        _GT(typeof(AudioSource)),
        _GT(typeof(AssetBundle)),
        _GT(typeof(ParticleSystem)),
        _GT(typeof(AsyncOperation)).SetBaseType(typeof(System.Object)),
        _GT(typeof(Light)),
        _GT(typeof(LightType)),
        _GT(typeof(SleepTimeout)),
        _GT(typeof(Animator)),
        _GT(typeof(Input)),
        _GT(typeof(KeyCode)),
        _GT(typeof(SkinnedMeshRenderer)),
        _GT(typeof(Space)),        
                                           
        _GT(typeof(MeshRenderer)),            
        _GT(typeof(ParticleEmitter)),
        _GT(typeof(ParticleRenderer)),
        _GT(typeof(ParticleAnimator)), 
                              
        _GT(typeof(BoxCollider)),
        _GT(typeof(MeshCollider)),
        _GT(typeof(SphereCollider)),        
        _GT(typeof(CharacterController)),
        _GT(typeof(CapsuleCollider)),
        
        _GT(typeof(Animation)),        
        _GT(typeof(AnimationClip)).SetBaseType(typeof(UnityEngine.Object)),        
        _GT(typeof(AnimationState)),
        _GT(typeof(AnimationBlendMode)),
        _GT(typeof(QueueMode)),  
        _GT(typeof(PlayMode)),
        _GT(typeof(WrapMode)),

        _GT(typeof(QualitySettings)),
        _GT(typeof(RenderSettings)),                                                   
        _GT(typeof(BlendWeights)),           
        _GT(typeof(RenderTexture)),
        _GT(typeof(Rigidbody)),         

        //fairygui
        _GT(typeof(FairyGUI.EventContext)),
        _GT(typeof(FairyGUI.EventDispatcher)),
        _GT(typeof(FairyGUI.EventListener)),
        _GT(typeof(FairyGUI.InputEvent)),
        _GT(typeof(FairyGUI.DisplayObject)),
        _GT(typeof(FairyGUI.Container)),
        _GT(typeof(FairyGUI.Stage)),
        _GT(typeof(FairyGUI.Controller)),
        _GT(typeof(FairyGUI.GObject)),
        _GT(typeof(FairyGUI.GGraph)),
        _GT(typeof(FairyGUI.GGroup)),
        _GT(typeof(FairyGUI.GImage)),
        _GT(typeof(FairyGUI.GLoader)),
        _GT(typeof(FairyGUI.PlayState)),
        _GT(typeof(FairyGUI.GMovieClip)),
        _GT(typeof(FairyGUI.TextFormat)),
        _GT(typeof(FairyGUI.GTextField)),
        _GT(typeof(FairyGUI.GRichTextField)),
        _GT(typeof(FairyGUI.GTextInput)),
        _GT(typeof(FairyGUI.GComponent)),
        _GT(typeof(FairyGUI.GList)),
        _GT(typeof(FairyGUI.GRoot)),
        _GT(typeof(FairyGUI.GLabel)),
        _GT(typeof(FairyGUI.GButton)),
        _GT(typeof(FairyGUI.GComboBox)),
        _GT(typeof(FairyGUI.GProgressBar)),
        _GT(typeof(FairyGUI.GSlider)),
        _GT(typeof(FairyGUI.PopupMenu)),
        _GT(typeof(FairyGUI.ScrollPane)),
        _GT(typeof(FairyGUI.Transition)),
        _GT(typeof(FairyGUI.UIPackage)),
        _GT(typeof(FairyGUI.Window)),
        _GT(typeof(FairyGUI.GObjectPool)),
        _GT(typeof(FairyGUI.Relations)),
        _GT(typeof(FairyGUI.RelationType)),
        _GT(typeof(FairyGUI.Timers)),
          
    };

    public static List<Type> dynamicList = new List<Type>()
    {        
        typeof(MeshRenderer),
        typeof(ParticleEmitter),
        typeof(ParticleRenderer),
        typeof(ParticleAnimator),

        typeof(BoxCollider),
        typeof(MeshCollider),
        typeof(SphereCollider),
        typeof(CharacterController),
        typeof(CapsuleCollider),

        typeof(Animation),
        typeof(AnimationClip),
        typeof(AnimationState),        

        typeof(BlendWeights),
        typeof(RenderTexture),
        typeof(Rigidbody),
    };

    //重载函数，相同参数个数，相同位置out参数匹配出问题时, 需要强制匹配解决
    //使用方法参见例子14
    public static List<Type> outList = new List<Type>()
    {
        
    };

    static BindType _GT(Type t)
    {
        return new BindType(t);
    }

    static DelegateType _DT(Type t)
    {
        return new DelegateType(t);
    }    
}
