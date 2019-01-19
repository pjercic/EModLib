using System.Collections;
using System.Collections.Generic;
using UnityEngine;

using System.Runtime.InteropServices;

public class EModLibInitialize : MonoBehaviour
{
    bool mStartedLib = false;
    void Awake()
    {
        EModLibWrapper.InstantiateEx();
    }

    void Start()
    {

    }

    void Update()
    {
        if (!mStartedLib)
        {
            EModLibWrapper.StartEx();
            mStartedLib = true;
        }
    }

    void OnDestroy()
    {
        EModLibWrapper.StopEx();
    }
}
