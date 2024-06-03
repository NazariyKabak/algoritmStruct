#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>


using namespace std;
int** generateMatrix(int rows, int cols) {
    int** matrix = new int*[rows];
    for (int r = 0; r < rows; r++) {
        matrix[r] = new int[cols];
    }

    for (int r = 0; r < rows; r++) {
        for(int c = 0; c < cols; c++) {
            matrix[r][c] = -100 + rand() % 201;
        }
    }

    return matrix;
}

void printMatrix(int** matrix, int rows, int cols) {
    for (int r = 0; r < rows; r++) {
        for(int c = 0; c < cols; c++) {
            cout << matrix[r][c] << " ";
        }
        cout << endl;
    }
}

int** transposeMatrix(int** matrix, int rows, int cols) {
    int **transposed = new int*[cols];
    for(int c = 0; c < rows; c++) {
        transposed[c] = new int[cols];
    }
    for(int r = 0; r < rows; r++) {
        for(int c = 0; c < cols; c++) {
            transposed[r][c] = matrix[r][c];
        }
    }
    return transposed;
}

void findCentralElement(int** matrix, int rows, int cols) {
    if(rows % 2 == 0 || cols % 2 == 0) {
        cout << "No single center element";
        return;
    }

    cout << "Center element: " << matrix[rows / 2][cols / 2];
}

int** generateSingleMatrix(int n) {
    int** matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n]{0};
        matrix[i][i] = 1;
    }

    return matrix;
}

void freeMatrix(int**matrix, int rows){
    for(int r=0;r<rows;r++){
        delete[] matrix[r];
    }
    delete[] matrix;
}

int* generateArray(int size) {
    int* array = new int[size];
    for(int i = 0; i < size; ++i) {
        array[i] = 1 + rand() % 101;
    }
    return array;
}

void printArray(int* array, int size) {
    for(int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}







int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int** findGCDForEachPair(int* arr1, int size1, int* arr2, int size2) {
    int **result = new int*[size1];
    for(int i = 0; i < size1; ++i) {
        result[i] = new int[size2];
    }

    for(int i = 0; i < size1; ++i) {
        for(int j = 0; j < size2; ++j) {
            result[i][j] = gcd(arr1[i], arr2[j]);
        }
    }
    return result;
}

int countMainDiagonal(int** matrix, int n) {
    int sum = 0;
    for(int i = 0; i < n; ++i) {
        sum += matrix[i][i];
    }
    return sum;
}

int countSecondDiagonal(int** matrix, int n) {
    int sum = 0;
    for(int i = n - 1; i >= 0; --i) {
        sum += matrix[n - i - 1][i];
    }
    return sum;
}




int main() {

    srand(time(0));

    int n, m;
    cin >> n >> m;
    int** matrix = generateMatrix(n, m);
    printMatrix(matrix, n, m);

    //Task1

    int** transposedMatrix = transposeMatrix(matrix, n, m);
    cout << endl;
    printMatrix(transposedMatrix, m, n);


    //Task2
    findCentralElement(matrix, n, m);
    cout << endl;


    //Task3

    int** singleMatrix = generateSingleMatrix(n);
    cout<<endl;
    printMatrix(singleMatrix, n, n);


    //Task4
    int* a = generateArray(n);
    int* b = generateArray(m);
    printArray(a, n);
    printArray(b, m);
    int** result = findGCDForEachPair(a, n, b, m);
    printMatrix(result, n, m);

    //Task5
    int mainDiagonal = countMainDiagonal(matrix, n);
    int secondDiagonal = countSecondDiagonal(matrix, n);
    cout << "Main diagonal: " << mainDiagonal << endl;
    cout << "Second diagonal: " << secondDiagonal << endl;
    if(mainDiagonal > secondDiagonal) {
        cout << "Main diagonal greater" << endl;
    } else if(secondDiagonal < mainDiagonal) {
        cout <<"Second diagonal greater" << endl;
    } else {
        cout << "Both diagonals are equal" << endl;
    }
}




