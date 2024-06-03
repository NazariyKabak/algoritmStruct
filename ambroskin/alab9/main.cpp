#include <iostream>
#include "selection_sort.h"

using namespace std;

int main() {
    int choice;
    do {
        cout << "Виберіть завдання:" << endl;
        cout << "1. Сортування одновимірного масиву вибором" << endl;
        cout << "2. Сортування колоди карт" << endl;
        cout << "3. Вихід" << endl;
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
            case 1:
                selectionSortArray();
                break;
            case 2:
                sortDeckOfCards();
                break;
            case 3:
                cout << "Вихід з програми." << endl;
                break;
            default:
                cout << "Невірний вибір, спробуйте ще раз." << endl;
        }
        cout << endl;
    } while (choice != 3);

    return 0;
}
