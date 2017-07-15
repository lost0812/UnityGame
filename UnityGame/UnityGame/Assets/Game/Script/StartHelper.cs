using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class StartHelper : MonoBehaviour {

	// Use this for initialization

    private bool OnPreCheck()
    {
        return true;
    }

	void Start () {
        if (!OnPreCheck())
            return;
        GameObject gameManager = GameObject.Find("GameManager");
        if (gameManager == null)
        {
            gameManager = new GameObject("GamaManger");
            gameManager.AddComponent<GameManager>();
        }
	}
	
	// Update is called once per frame
	void Update () {
		
	}
}
