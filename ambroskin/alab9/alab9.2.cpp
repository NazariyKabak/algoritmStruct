#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;


void print2DArray(const vector<vector<int>>& arr) {
    for (const auto& row : arr) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    cout << endl;
}


void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            cout << "Порівнюємо " << arr[j] << " та " << arr[j + 1] << endl;
            if (arr[j] < arr[j + 1]) { // Сортування за спаданням
                swap(arr[j], arr[j + 1]);
                cout << "Міняємо місцями " << arr[j] << " та " << arr[j + 1] << endl;
            }
        }
        cout << "Рядок після " << i + 1 << " проходу: ";
        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;
    }
}


void bubbleSort2D(vector<vector<int>>& arr) {
    for (auto& row : arr) {
        bubbleSort(row);
    }
}

int main() {
    srand(time(0));

    int N, M;
    cout << "Введіть кількість рядків у масиві: ";
    cin >> N;
    cout << "Введіть кількість стовпців у масиві: ";
    cin >> M;

    vector<vector<int>> arr(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            arr[i][j] = rand() % 100;
        }
    }

    cout << "Масив до сортування: " << endl;
    print2DArray(arr);

    bubbleSort2D(arr);

    cout << "Масив після сортування: " << endl;
    print2DArray(arr);

    return 0;
}
