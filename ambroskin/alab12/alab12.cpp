#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;


void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}


void swapEl(vector<int>& arr, int i) {
    int buff = arr[i];
    arr[i] = arr[i - 1];
    arr[i - 1] = buff;
}


void myShakerSort(vector<int>& arr) {
    int leftMark = 1;
    int rightMark = arr.size() - 1;
    while (leftMark <= rightMark) {
        for (int i = rightMark; i >= leftMark; i--) {
            if (arr[i - 1] > arr[i]) {
                swapEl(arr, i);
            }
        }
        leftMark++;
        for (int i = leftMark; i <= rightMark; i++) {
            if (arr[i - 1] > arr[i]) {
                swapEl(arr, i);
            }
        }
        rightMark--;
        cout << "Ітерація: " << leftMark - 1 << " ";
        printArray(arr);
    }
}

int main() {
    srand(time(0));

    int N;
    cout << "Введіть кількість елементів у масиві: ";
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 100;
    }

    cout << "Масив до сортування: ";
    printArray(arr);

    myShakerSort(arr);

    cout << "Масив після сортування: ";
    printArray(arr);


    int shift;
    cout << "Введіть число для визначення зміщення масиву: ";
    cin >> shift;


    if (shift % 2 == 0) {
        shift = 3;
    } else {
        shift = -3;
    }

    for (int i = 0; i < N; i++) {
        arr[i] += shift;
    }

    cout << "Масив після зміщення: ";
    printArray(arr);

    return 0;
}
