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


void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            cout << "Порівнюємо " << arr[j] << " та " << arr[j + 1] << endl;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                cout << "Міняємо місцями " << arr[j] << " та " << arr[j + 1] << endl;
            }
        }
        cout << "Масив після " << i + 1 << " проходу: ";
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
        arr[i] = rand() % 100; //
    }

    cout << "Масив до сортування: ";
    printArray(arr);

    bubbleSort(arr);

    cout << "Масив після сортування: ";
    printArray(arr);

    return 0;
}
