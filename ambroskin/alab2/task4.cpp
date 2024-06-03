#include <iostream>
#include "Arrays.h"
using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    const int N = 12;
    int arr1[N];
    int arr2[N];

    ArrayUtils::generateArray(arr1, N);
    ArrayUtils::printArray(arr1, N);
    ArrayUtils::generateArray(arr2, N);
    ArrayUtils::printArray(arr2, N);
    int* resultArray = ArrayUtils::concatArrays(arr1, arr2, N, N);
    ArrayUtils::sortArray(resultArray, N);
    ArrayUtils::printArray(resultArray, N);


}