#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string text;
    cout << "Введіть текст: ";
    getline(cin, text);

    int words = 0, sentences = 0, characters = 0;
    bool in_word = false;

    for (char c : text) {
        if (isalpha(c)) {
            characters++;
            if (!in_word) {
                in_word = true;
                words++;
            }
        } else {
            if (c == '.' || c == '!' || c == '?') {
                sentences++;
            }
            in_word = false;
        }
    }

    cout << "Кількість слів: " << words << endl;
    cout << "Кількість речень: " << sentences << endl;
    cout << "Кількість символів: " << characters << endl;

    return 0;
}
