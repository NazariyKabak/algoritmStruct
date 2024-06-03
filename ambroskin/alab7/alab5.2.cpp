#include <iostream>
#include <string>
using namespace std;

int main() {
    string text = "Hello World Hello World";
    string pattern;
    cout << "Введіть шаблон для пошуку: ";
    getline(cin, pattern);

    size_t pos = text.find(pattern);
    while (pos != string::npos) {
        cout << "Шаблон знайдено на позиції: " << pos << endl;
        pos = text.find(pattern, pos + 1);
    }

    return 0;
}
