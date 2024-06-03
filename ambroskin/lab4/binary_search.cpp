#include "binary_search.h"
#include <iostream>
#include <algorithm>
using namespace std;


void showArr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void sortArr(int arr[], int size) {
    sort(arr, arr + size);
}


void binarySearch() {
    const int arrSize = 10;
    int arr[arrSize];
    int requiredKey = 0;

    cout << "Введіть елементи масиву: ";
    for (int i = 0; i < arrSize; i++) {
        cin >> arr[i];
    }

    sortArr(arr, arrSize);
    cout << "Відсортований масив: ";
    showArr(arr, arrSize);

    cout << "Введіть число для пошуку: ";
    cin >> requiredKey;

    int left = 0, right = arrSize - 1;
    int index = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == requiredKey) {
            index = mid;
            break;
        } else if (arr[mid] < requiredKey) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (index != -1) {
        cout << "Значення " << requiredKey << " знаходиться в ячейці з індексом: " << index << " і значенням: " << arr[index] << endl;
    } else {
        cout << "В масиві немає такого значення" << endl;
    }
}
