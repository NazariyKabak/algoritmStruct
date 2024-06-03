#include <iostream>
#include <string>
using namespace std;

int main() {
    string text;
    char choice;

    do {
        cout << "1. Ввести текст" << endl;
        cout << "2. Ввести шаблон для пошуку" << endl;
        cout << "3. Вийти" << endl;
        cout << "Виберіть опцію: ";
        cin >> choice;
        cin.ignore();

        if (choice == '1') {
            string newText;
            cout << "Введіть текст: ";
            getline(cin, newText);
            text += newText + " ";
        } else if (choice == '2') {
            string pattern;
            cout << "Введіть шаблон для пошуку: ";
            getline(cin, pattern);

            size_t pos = text.find(pattern);
            while (pos != string::npos) {
                cout << "Шаблон знайдено на позиції: " << pos << endl;
                pos = text.find(pattern, pos + 1);
            }
        }
    } while (choice != '3');

    return 0;
}
