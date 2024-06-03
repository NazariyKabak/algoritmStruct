#include "kmp_search.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;


vector<int> computePrefixFunction(const string& pattern) {
    vector<int> pf(pattern.length());
    pf[0] = 0;
    for (size_t k = 0, i = 1; i < pattern.length(); ++i) {
        while (k > 0 && pattern[i] != pattern[k])
            k = pf[k - 1];
        if (pattern[i] == pattern[k])
            k++;
        pf[i] = k;
    }
    return pf;
}


vector<size_t> KMPSearch(const string& text, const string& pattern) {
    vector<size_t> matchIndices;
    vector<int> pf = computePrefixFunction(pattern);
    for (size_t k = 0, i = 0; i < text.length(); ++i) {
        while (k > 0 && pattern[k] != text[i])
            k = pf[k - 1];
        if (pattern[k] == text[i])
            k++;
        if (k == pattern.length()) {
            matchIndices.push_back(i - pattern.length() + 1);
            k = pf[k - 1];
        }
    }
    return matchIndices;
}


void directKMPSearch() {
    string text, pattern;
    cout << "Введіть текст: ";
    cin.ignore();
    getline(cin, text);
    cout << "Введіть шаблон для пошуку: ";
    getline(cin, pattern);

    vector<size_t> matches = KMPSearch(text, pattern);
    if (!matches.empty()) {
        cout << "Шаблон знайдено на позиціях: ";
        for (size_t idx : matches) {
            cout << idx << " ";
        }
        cout << endl;
    } else {
        cout << "Шаблон не знайдено." << endl;
    }
}


void predefinedKMPSearch() {
    string text = "Etiam et ex imperdiet purus viverra gravida. Mauris gravida dignissim magna sit amet malesuada. Maecenas tortor nunc aliquam ac tortor varius volutpat efficitur lacus. Praesent turpis mi vestibulum a nisi sit amet aliquam faucibus ipsum. Cras rhoncus est mauris eget sollicitudin arcu eleifend ac. Vivamus tempus tincidunt pharetra. Pellentesque molestie viverra libero nec faucibus. Duis scelerisque eleifend dapibus";
    string pattern;
    cout << "Введіть шаблон для пошуку: ";
    cin.ignore();
    getline(cin, pattern);

    vector<size_t> matches = KMPSearch(text, pattern);
    if (!matches.empty()) {
        cout << "Шаблон знайдено на позиціях: ";
        for (size_t idx : matches) {
            cout << idx << " ";
        }
        cout << endl;
    } else {
        cout << "Шаблон не знайдено." << endl;
    }
}


void caseInsensitiveKMPSearch() {
    string text, pattern;
    cout << "Введіть текст: ";
    cin.ignore();
    getline(cin, text);
    cout << "Введіть шаблон для пошуку: ";
    getline(cin, pattern);

    // Приведення до нижнього регістру
    string text_lower = text;
    string pattern_lower = pattern;
    transform(text_lower.begin(), text_lower.end(), text_lower.begin(), ::tolower);
    transform(pattern_lower.begin(), pattern_lower.end(), pattern_lower.begin(), ::tolower);

    vector<size_t> matches = KMPSearch(text_lower, pattern_lower);
    if (!matches.empty()) {
        cout << "Шаблон знайдено на позиціях: ";
        for (size_t idx : matches) {
            cout << idx << " ";
        }
        cout << endl;
    } else {
        cout << "Шаблон не знайдено." << endl;
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

            vector<size_t> matches = KMPSearch(text, pattern);
            for (auto it = matches.rbegin(); it != matches.rend(); ++it) {
                text.replace(*it, pattern.length(), replacement);
            }

            cout << "Новий текст: " << text << endl;
        }
    } while (choice != '3');
}
