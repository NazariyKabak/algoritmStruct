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


void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


void insertionSort2D(vector<vector<int>>& arr) {
    for (auto& row : arr) {
        insertionSort(row);
    }
}


void sortColumns(vector<vector<int>>& arr) {
    int N = arr.size();
    int M = arr[0].size();
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N - 1; j++) {
            for (int k = 0; k < N - j - 1; k++) {
                if (arr[k][i] < arr[k + 1][i]) {
                    swap(arr[k], arr[k + 1]);
                } else if (arr[k][i] == arr[k + 1][i]) {
                    for (int l = 1; l < M; l++) {
                        if (arr[k][l] > arr[k + 1][l]) {
                            swap(arr[k], arr[k + 1]);
                            break;
                        }
                    }
                }
            }
        }
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

    insertionSort2D(arr);

    cout << "Масив після сортування вставками: " << endl;
    print2DArray(arr);

    sortColumns(arr);

    cout << "Масив після сортування кожного стовпця за спаданням: " << endl;
    print2DArray(arr);

    return 0;
}
