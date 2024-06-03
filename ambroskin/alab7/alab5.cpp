#include <iostream>
#include <string>
using namespace std;

int main() {
    string text, pattern;
    cout << "Введіть текст: ";
    getline(cin, text);
    cout << "Введіть шаблон для пошуку: ";
    getline(cin, pattern);

    size_t pos = text.find(pattern);
    if (pos != string::npos) {
        cout << "Шаблон знайдено на позиції: " << pos << endl;
    } else {
        cout << "Шаблон не знайдено." << endl;
    }

    return 0;
}
