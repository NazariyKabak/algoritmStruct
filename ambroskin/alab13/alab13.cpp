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


void shellSort(vector<int>& arr) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}


void shellSortEven(vector<int>& arr) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            if (arr[i] % 2 == 0) {
                int temp = arr[i];
                int j;
                for (j = i; j >= gap && arr[j - gap] > temp && arr[j - gap] % 2 == 0; j -= gap) {
                    arr[j] = arr[j - gap];
                }
                arr[j] = temp;
            }
        }
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

    shellSort(arr);

    cout << "Масив після сортування Шелла: ";
    printArray(arr);


    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 100;
    }

    cout << "Новий масив до сортування (лише парні числа): ";
    printArray(arr);

    shellSortEven(arr);

    cout << "Масив після сортування Шелла (лише парні числа): ";
    printArray(arr);

    return 0;
}
