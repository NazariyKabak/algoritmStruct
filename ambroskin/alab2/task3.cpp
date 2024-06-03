#include <iostream>
using namespace std;

int main() {
    int banknotes[] = {1000, 500,  200, 100, 50, 20, 10, 5, 2, 1};

    int sum;
    cin >> sum;

    while(sum > 0) {
        for(int banknote : banknotes) {
            if(sum >= banknote) {
                cout << banknote << " ";
                sum -= banknote;
                break;
            }
        }
    }
}