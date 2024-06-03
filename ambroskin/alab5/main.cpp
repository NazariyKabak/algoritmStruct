#include <iostream>

using namespace std;

int* generateArray(int size) {
    int* arr = new int[size];

    for(int i = 0; i < size; ++i) {
        arr[i] = -100 + rand() % 201;
    }

    return arr;
}

void printArray(int* arr, int size) {
    cout << "Array: {" << arr[0];
    for(int i = 1; i < size; ++i) {
        cout << ", " << arr[i];
    }
    cout << "}" << endl;
}

int binarySearch(int* arr, int size, int target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int interpolatingSearch(int* arr, int size, int target) {
    int low = 0, high = size - 1;
    while (low <= high && target >= arr[low] && target <= arr[high]) {
        int pos = low + ((target - arr[low]) * (high - low) / (arr[high] - arr[low]));
        if (arr[pos] == target) return pos;
        if (arr[pos] < target) low = pos + 1;
        else high = pos - 1;
    }
    return -1;
}

void bubbleSort(int* arr, int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main() {
    srand(time(0));
    int size;
    cin >> size;
    int* arr = generateArray(size);
    if(size > 100 || size < 0) return 0;
    bubbleSort(arr, size);
    printArray(arr, size);
    int target, secondTarget;
    cin >> target >> secondTarget;
    int targetIndex = -1, secondTargetIndex = -1;
    if(size <= 20) {
        targetIndex = binarySearch(arr, size, target);
        secondTargetIndex = binarySearch(arr, size, secondTarget);
    }
    else if (size <= 100) {
        targetIndex = interpolatingSearch(arr, size, target);
        secondTargetIndex = interpolatingSearch(arr, size, secondTarget);
    }


    cout << (targetIndex > -1 ? to_string(targetIndex) : "There is no target value in array") << endl;
    cout << (targetIndex > -1 ? to_string(secondTargetIndex) : "There is no second target value in array") << endl;

    return 0;
}