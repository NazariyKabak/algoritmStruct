#include <iostream>
#include <vector>

using namespace std;


void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}


void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
        cout << "Масив після " << i + 1 << " проходу: ";
        printArray(arr);
    }
}

int main() {
    int N;
    cout << "Введіть кількість елементів у масиві: ";
    cin >> N;

    vector<int> arr(N);
    cout << "Введіть елементи масиву: ";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cout << "Масив до сортування: ";
    printArray(arr);

    selectionSort(arr);

    cout << "Масив після сортування: ";
    printArray(arr);

    return 0;
}
