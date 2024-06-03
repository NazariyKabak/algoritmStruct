#include <iostream>
#include "prime_search.h"

using namespace std;

int main() {
    int choice;
    do {
        cout << "Виберіть завдання:" << endl;
        cout << "1. Пошук простих чисел методом Решета Ератосфена" << endl;
        cout << "2. Пошук простих чисел методом Решета Сундарама" << endl;
        cout << "3. Генерація масиву та пошук простих чисел" << endl;
        cout << "4. Вихід" << endl;
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int n;
                cout << "Введіть верхню межу діапазону (N): ";
                cin >> n;
                sieveOfEratosthenes(n);
                break;
            }
            case 2: {
                int n;
                cout << "Введіть верхню межу діапазону (N): ";
                cin >> n;
                sieveOfSundaram(n);
                break;
            }
            case 3:
                generateAndProcessArray();
                break;
            case 4:
                cout << "Вихід з програми." << endl;
                break;
            default:
                cout << "Невірний вибір, спробуйте ще раз." << endl;
        }
        cout << endl;
    } while (choice != 4);

    return 0;
}
