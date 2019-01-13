using System.Collections;
using System.Collections.Generic;
using UnityEngine;

using System.Runtime.InteropServices;

public class PluginUnmanagedTest : MonoBehaviour
{
    void Start()
    {
        EModLibWrapper.InstantiateEx();
        EModLibWrapper.createPersonEx(0);
        EModLibWrapper.inStimulusEx(0, 0.5, 0.5);
        EModLibWrapper.StartEx();
    }

    void Update()
    {
        print("Native random number " + EModLibWrapper.getEmotionEx(0));
    }
}
