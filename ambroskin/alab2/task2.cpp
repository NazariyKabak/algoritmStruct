#include <iostream>
#include "Arrays.h"
using namespace std;

void replaceNegativeToPositive(int arr[], int size) {
    for(int i = 0; i < size; ++i) {
        if(arr[i] < 0)
            arr[i] = abs(arr[i]);
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    const int N = 12;
    int arr[N];

    ArrayUtils::generateArray(arr, N);
    ArrayUtils::printArray(arr, N);
    replaceNegativeToPositive(arr, N);
    ArrayUtils::printArray(arr, N);
}