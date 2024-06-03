
#include "Arrays.h"

using namespace std;

namespace ArrayUtils {

    void generateArray(int arr[], int size) {
        for(int i = 0; i < size; ++i) {
            arr[i] = -100 + rand() % 201;
        }
    }

    void printArray(int arr[], int size) {
        for(int i = 0; i < size; ++i) {
            std::cout << arr[i] << " ";
        }
        cout << endl;
    }

    void sortArray(int arr[], int size) {
        for(int i = 0; i < size; ++i) {
            for(int j = i + 1; j < size; ++j) {
                if(arr[i] > arr[j]) {
                    swap(arr[i], arr[j]);
                }
            }
        }
    }
    int* concatArrays(int arr1[], int arr2[], int size1, int size2) {
        int* result = new int[size1 + size2];

        for(int i = 0; i < size1; ++i) {
            result[i] = arr1[i];
        }
        for(int i = size1, k = 0; i < size1 + size2; ++i, ++k) {
            result[i] = arr2[k];
        }
    }

}
