#include <iostream>
#include "kmp_search.h"

using namespace std;

int main() {
    int choice;
    do {
        cout << "Виберіть завдання:" << endl;
        cout << "1. Прямий пошук рядка в тексті методом КМП" << endl;
        cout << "2. Пошук рядка в заданому тексті методом КМП" << endl;
        cout << "3. Пошук рядка незалежно від регістру методом КМП" << endl;
        cout << "4. Аналіз тексту" << endl;
        cout << "5. Пошук та заміна рядків методом КМП" << endl;
        cout << "6. Вихід" << endl;
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
            case 1:
                directKMPSearch();
                break;
            case 2:
                predefinedKMPSearch();
                break;
            case 3:
                caseInsensitiveKMPSearch();
                break;
            case 4:
                analyzeText();
                break;
            case 5:
                searchAndReplace();
                break;
            case 6:
                cout << "Вихід з програми." << endl;
                break;
            default:
                cout << "Невірний вибір, спробуйте ще раз." << endl;
        }
        cout << endl;
    } while (choice != 6);

    return 0;
}
