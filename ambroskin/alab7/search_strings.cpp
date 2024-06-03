#include "search_strings.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;


void directSearch() {
    string text, pattern;
    cout << "Введіть текст: ";
    cin.ignore();
    getline(cin, text);
    cout << "Введіть шаблон для пошуку: ";
    getline(cin, pattern);

    size_t pos = text.find(pattern);
    if (pos != string::npos) {
        cout << "Шаблон знайдено на позиції: " << pos << endl;
    } else {
        cout << "Шаблон не знайдено." << endl;
    }
}


void predefinedTextSearch() {
    string text = "Hello World Hello World";
    string pattern;
    cout << "Введіть шаблон для пошуку: ";
    cin.ignore();
    getline(cin, pattern);

    size_t pos = text.find(pattern);
    while (pos != string::npos) {
        cout << "Шаблон знайдено на позиції: " << pos << endl;
        pos = text.find(pattern, pos + 1);
    }
}


void caseInsensitiveSearch() {
    string text, pattern;
    cout << "Введіть текст: ";
    cin.ignore();
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
}


void analyzeText() {
    string text;
    cout << "Введіть текст: ";
    cin.ignore();
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
}


void searchAndReplace() {
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
            string pattern, replacement;
            cout << "Введіть шаблон для пошуку: ";
            getline(cin, pattern);
            cout << "Введіть слово для заміни: ";
            getline(cin, replacement);

            size_t pos = text.find(pattern);
            while (pos != string::npos) {
                text.replace(pos, pattern.length(), replacement);
                pos = text.find(pattern, pos + replacement.length());
            }

            cout << "Новий текст: " << text << endl;
        }
    } while (choice != '3');
}
