using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour
{
    void Awake()
    {
        gameObject.AddComponent<LuaClient>();
    }

    void Start()
    {

    }

    void Update()
    {

    }
}