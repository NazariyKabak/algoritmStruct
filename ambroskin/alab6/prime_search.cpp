#include "prime_search.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


void sieveOfEratosthenes(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int p = 2; p * p <= n; ++p) {
        if (isPrime[p]) {
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }

    cout << "Прості числа через одне: ";
    bool skip = true;
    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            if (!skip) {
                cout << i << " ";
            }
            skip = !skip;
        }
    }
    cout << endl;
}


void sieveOfSundaram(int n) {
    int newLimit = (n - 1) / 2;
    vector<bool> isPrime(newLimit + 1, true);

    for (int i = 1; i <= newLimit; ++i) {
        for (int j = i; (i + j + 2 * i * j) <= newLimit; ++j) {
            isPrime[i + j + 2 * i * j] = false;
        }
    }

    cout << "Прості числа через два: ";
    if (n > 2) cout << 2 << " ";
    int count = 0;
    for (int i = 1; i <= newLimit; ++i) {
        if (isPrime[i]) {
            if (count % 2 == 1) {
                cout << (2 * i + 1) << " ";
            }
            count++;
        }
    }
    cout << endl;
}


void generateAndProcessArray() {
    int arraySize, maxValue = 1000;
    cout << "Введіть бажаний розмір масиву (до 100 елементів): ";
    cin >> arraySize;
    if (arraySize > 100) {
        cout << "Розмір масиву не може перевищувати 100." << endl;
        return;
    }

    vector<int> arr(arraySize);
    cout << "Згенерований масив: ";
    for (int i = 0; i < arraySize; ++i) {
        arr[i] = rand() % maxValue + 1;
        cout << arr[i] << " ";
    }
    cout << endl;

    int maxElement = *max_element(arr.begin(), arr.end());
    cout << "Максимальне значення у масиві: " << maxElement << endl;


    cout << "Прості числа методом Решета Ератосфена до " << maxElement << ":" << endl;
    sieveOfEratosthenes(maxElement);


    cout << "Прості числа методом Решета Сундарама до " << maxElement << ":" << endl;
    sieveOfSundaram(maxElement);


    vector<int> primesEratosthenes;
    vector<int> primesSundaram;
    vector<bool> isPrime(maxElement + 1, true);

    for (int p = 2; p * p <= maxElement; ++p) {
        if (isPrime[p]) {
            for (int i = p * p; i <= maxElement; i += p) {
                isPrime[i] = false;
            }
        }
    }
    for (int i = 2; i <= maxElement; ++i) {
        if (isPrime[i]) {
            primesEratosthenes.push_back(i);
        }
    }

    int newLimit = (maxElement - 1) / 2;
    fill(isPrime.begin(), isPrime.end(), true);
    for (int i = 1; i <= newLimit; ++i) {
        for (int j = i; (i + j + 2 * i * j) <= newLimit; ++j) {
            isPrime[i + j + 2 * i * j] = false;
        }
    }
    if (maxElement > 2) primesSundaram.push_back(2);
    for (int i = 1; i <= newLimit; ++i) {
        if (isPrime[i]) {
            primesSundaram.push_back(2 * i + 1);
        }
    }

    vector<int> commonElements;
    sort(primesEratosthenes.begin(), primesEratosthenes.end());
    sort(primesSundaram.begin(), primesSundaram.end());
    set_intersection(primesEratosthenes.begin(), primesEratosthenes.end(), primesSundaram.begin(), primesSundaram.end(), back_inserter(commonElements));

    cout << "Прості числа, що є в обох масивах: ";
    for (int num : commonElements) {
        cout << num << " ";
    }
    cout << endl;
}
