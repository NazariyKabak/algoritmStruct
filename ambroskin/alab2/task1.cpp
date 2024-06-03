#include <iostream>
#include <vector>
#include "Arrays.h"

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));
    const int N = 12;
    int x[N];

    int m;
    cin >> m;

    ArrayUtils::generateArray(x, N);
    ArrayUtils::printArray(x, N);

    vector<int> y;

    for (int i : x) {
        if (abs(i) > m) {
            y.push_back(i);
            cout << i << " ";
        }
    }
    cout << endl << m;
}