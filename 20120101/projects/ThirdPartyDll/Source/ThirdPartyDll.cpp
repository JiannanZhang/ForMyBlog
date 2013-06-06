#include <iostream>
using namespace std;

#ifdef __cplusplus
extern "C" {
#endif

// __declspec(dllexport) is used to force generate function name as 'realfunction'
// so you can find the address of this function by searching in the dll
__declspec(dllexport) int* realfunction(double* nDoubleArray, unsigned int nSize, bool nPrint)
{
    int* cutOffArray = new int[nSize];
    for (size_t i = 0; i < nSize; i++)
    {
        if (nPrint)
            cout << "Value of " << i << ": " << *(nDoubleArray + i) << endl;
        cutOffArray[i] = (int)(*(nDoubleArray + i));
    }

    return cutOffArray;
}

int main()
{
    double arr[2] = {1.5 , 3.2};
    unsigned int size = 2;
    bool pri = true;

    int* ret = realfunction(arr, size, pri);
    if (ret)
        delete []ret;

    return 0;
}

#ifdef __cplusplus
}
#endif