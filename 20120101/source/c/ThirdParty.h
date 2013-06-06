// The ThirdPartyDll.dll contains the following function.
// Name: 
//   realfunction
// Function:
//   Turn a double type array to an int type array.
// Parameters:
//   nDoubleArray: a double type array needed to cutoff.
//   nSize: the size of nDoubleArray.
//   nPrint: print the original array if nPrint == true.
// Return Value:
//   This function will allocate a new int type array inside for storing the result.
//   So, DO NOT forget to release the space after using the result! 
//   (Of course, we'd better not to design a function like this when coding:))
// ----------------------------------------------------------------------------------

int* realfunction(double* nDoubleArray, unsigned int nSize, bool nPrint);