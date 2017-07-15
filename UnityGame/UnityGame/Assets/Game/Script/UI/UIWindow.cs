using System;
using UnityEngine;

namespace RPGGame
{
    public class UIWindow : FairyGUI.Window
    {
        public delegate void UIWindowCallBack();
        public UIWindowCallBack onInit = delegate{};
        public UIWindowCallBack onShow = delegate{};
        public UIWindowCallBack onHide = delegate{};

        public string WindowName
        {
            get
            {
                return this.rootContainer.gameObject.name;
            }
            set
            {
                this.rootContainer.gameObject.name = value;
            }
        }

        override protected void OnHide()
        {
            onHide();
        }
        override protected void OnInit()
        {
            onInit();
        }
        override protected void OnShown()
        {
            onShow();
        }

    }
}
