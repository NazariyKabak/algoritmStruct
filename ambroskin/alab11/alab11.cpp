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


void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        cout << "Початковий елемент для вставки: " << key << endl;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            cout << "Переміщуємо елемент " << arr[j] << " на позицію " << j + 1 << endl;
            j = j - 1;
        }
        arr[j + 1] = key;
        cout << "Вставляємо елемент " << key << " на позицію " << j + 1 << endl;
        cout << "Масив після вставки: ";
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
        arr[i] = rand() % 100; // Генерація випадкових чисел від 0 до 99
    }

    cout << "Масив до сортування: ";
    printArray(arr);

    insertionSort(arr);

    cout << "Масив після сортування: ";
    printArray(arr);

    return 0;
}
