#include "search.h"
#include <iostream>
using namespace std;


void showArr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void linSearch() {
    const int arrSize = 10;
    int arr[arrSize];
    int requiredKey = 0;

    cout << "Введіть елементи масиву: ";
    for (int i = 0; i < arrSize; i++) {
        cin >> arr[i];
    }

    cout << "Введіть число для пошуку: ";
    cin >> requiredKey;

    int index = -1;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == requiredKey) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        cout << "Значення " << requiredKey << " знаходиться в ячейці з індексом: " << index << " і значенням: " << arr[index] << endl;
    } else {
        cout << "В масиві немає такого значення" << endl;
    }
}
