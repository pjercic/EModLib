using System.Collections;
using System.Collections.Generic;
using UnityEngine;

using System.Runtime.InteropServices;

public class EModLibWrapper
{
#if UNITY_STANDALONE_WIN
    const string dll = "libEModLib";
#elif UNITY_STANDALONE_OSX
    const string dll = "PluginUnmanagedTestBundle";
#elif UNITY_STANDALONE_LIN
    const string dll = "PluginUnmanagedTestLin";
#elif UNITY_IOS
    const string dll = "__Internal";
#elif UNITY_ANDROID
    const string dll = "???";
#else
    const string dll = " ";
#endif

    [DllImport(dll)]
    private static extern void Instantiate();

    [DllImport(dll)]
    private static extern void inStimulus(int persId, double arousal, double valence);

    [DllImport(dll)]
    private static extern int getEmotion(int persId);

    [DllImport(dll)]
    private static extern double getArousal(int persId);

    [DllImport(dll)]
    private static extern double getValence(int persId);

    [DllImport(dll)]
    private static extern int createPerson(int type);

    [DllImport(dll)]
    private static extern void Start();

    [DllImport(dll)]
    private static extern void Stop();

    public static void InstantiateEx()
    {
#if (UNITY_STANDALONE_WIN || UNITY_STANDALONE_OSX || UNITY_STANDALONE_LIN)
        Instantiate();
#endif
    }

    public static void inStimulusEx(int persId, double arousal, double valence)
    {
#if (UNITY_STANDALONE_WIN || UNITY_STANDALONE_OSX || UNITY_STANDALONE_LIN)
        inStimulus(persId, arousal, valence);
#endif
    }

    public static int getEmotionEx(int persId)
    {
#if (UNITY_STANDALONE_WIN || UNITY_STANDALONE_OSX || UNITY_STANDALONE_LIN)
        return getEmotion(persId);
#else
        return -1;
#endif
    }

    public static double getArousalEx(int persId)
    {
#if (UNITY_STANDALONE_WIN || UNITY_STANDALONE_OSX || UNITY_STANDALONE_LIN)
        return getArousal(persId);
#else
        return -1;
#endif
    }

    public static double getValenceEx(int persId)
    {
#if (UNITY_STANDALONE_WIN || UNITY_STANDALONE_OSX || UNITY_STANDALONE_LIN)
        return getValence(persId);
#else
        return -1;
#endif
    }

    public static int createPersonEx(int type)
    {
#if (UNITY_STANDALONE_WIN || UNITY_STANDALONE_OSX || UNITY_STANDALONE_LIN)
        return createPerson(type);
#else
        return -1;
#endif
    }

    public static void StartEx()
    {
#if (UNITY_STANDALONE_WIN || UNITY_STANDALONE_OSX || UNITY_STANDALONE_LIN)
        Start();
#endif
    }

    public static void StopEx()
    {
#if (UNITY_STANDALONE_WIN || UNITY_STANDALONE_OSX || UNITY_STANDALONE_LIN)
        Stop();
#endif
    }
}
