#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string text, pattern;
    cout << "Введіть текст: ";
    getline(cin, text);
    cout << "Введіть шаблон для пошуку: ";
    getline(cin, pattern);


    string text_lower = text;
    string pattern_lower = pattern;
    transform(text_lower.begin(), text_lower.end(), text_lower.begin(), ::tolower);
    transform(pattern_lower.begin(), pattern_lower.end(), pattern_lower.begin(), ::tolower);

    size_t pos = text_lower.find(pattern_lower);
    while (pos != string::npos) {
        cout << "Шаблон знайдено на позиції: " << pos << endl;
        pos = text_lower.find(pattern_lower, pos + 1);
    }

    return 0;
}
