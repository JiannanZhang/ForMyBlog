#include "CallThirdParty.h"
#include "ThirdParty.h"
#include <iostream>
#include <Windows.h>
using namespace std;

#ifdef __cplusplus
extern "C" {
#endif

typedef int* (*ThirdPartyFunc)(double*, unsigned int, bool);

JNIEXPORT jintArray JNICALL Java_CallThirdParty_CallThirdPartyDll (JNIEnv *env, jobject _obj, jdoubleArray _arg_doublearray, jint _arg_int, jboolean _arg_boolean)
{
    HMODULE dlh = NULL;
    ThirdPartyFunc thirdPartyFunc;

    if (!(dlh=LoadLibrary("ThirdPartyDll.dll")))      
    {
    printf("LoadLibrary() failed: %d\n", GetLastError()); 
    }
    if (!(thirdPartyFunc = (ThirdPartyFunc)GetProcAddress(dlh, "realfunction")))  
    {
        printf("GetProcAddress() failed: %d\n", GetLastError()); 
    }

    int        m_int = _arg_int;  
    double*    m_doublearray = env->GetDoubleArrayElements(_arg_doublearray, NULL);
    bool       m_boolean = _arg_boolean;

    int* ret = (*thirdPartyFunc)(m_doublearray, m_int, m_boolean); /* actual function call */
    
    jintArray result = NULL;
    if (ret)
    {
        result = env->NewIntArray(_arg_int);
        env->SetIntArrayRegion(result, 0, _arg_int, (const jint*)ret);
    }

    FreeLibrary(dlh); /* unload DLL and free memory */
    if(ret) 
    {
        free(ret); 
    }

    return result;
}

#ifdef __cplusplus
}
#endif