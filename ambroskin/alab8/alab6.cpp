#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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


vector<size_t> KMP(const string& text, const string& pattern) {
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


vector<size_t> KMPCaseInsensitive(const string& text, const string& pattern) {
    string textLower = text;
    string patternLower = pattern;
    transform(textLower.begin(), textLower.end(), textLower.begin(), ::tolower);
    transform(patternLower.begin(), patternLower.end(), patternLower.begin(), ::tolower);
    return KMP(textLower, patternLower);
}


string replacePattern(const string& text, const string& pattern, const string& replacement) {
    string result = text;
    vector<size_t> matchIndices = KMP(text, pattern);
    for (auto it = matchIndices.rbegin(); it != matchIndices.rend(); ++it) {
        result.replace(*it, pattern.length(), replacement);
    }
    return result;
}


string replaceLongWords(const string& text, const string& replacement) {
    string result;
    size_t start = 0, end = 0;
    while (end != string::npos) {
        end = text.find_first_of(" \t\n", start);
        string word = text.substr(start, end - start);
        if (word.length() > 7) {
            result += replacement;
        } else {
            result += word;
        }
        if (end != string::npos) {
            result += text[end];
            start = end + 1;
        }
    }
    return result;
}


int main() {
    string text = "Etiam et ex imperdiet purus viverra gravida. Mauris gravida dignissim magna sit amet malesuada. Maecenas tortor nunc aliquam ac tortor varius volutpat efficitur lacus. Praesent turpis mi vestibulum a nisi sit amet aliquam faucibus ipsum. Cras rhoncus est mauris eget sollicitudin arcu eleifend ac. Vivamus tempus tincidunt pharetra. Pellentesque molestie viverra libero nec faucibus. Duis scelerisque eleifend dapibus.";
    string pattern, replacement;
    char choice;

    do {
        cout << "1. Ввести шаблон для пошуку" << endl;
        cout << "2. Пошук незалежно від регістру" << endl;
        cout << "3. Замінити знайдене слово" << endl;
        cout << "4. Замінити слова довше 7 символів" << endl;
        cout << "5. Вийти" << endl;
        cout << "Виберіть опцію: ";
        cin >> choice;
        cin.ignore();

        if (choice == '1') {
            cout << "Введіть шаблон для пошуку: ";
            getline(cin, pattern);
            vector<size_t> matches = KMP(text, pattern);
            if (!matches.empty()) {
                cout << "Шаблон знайдено на позиціях: ";
                for (size_t idx : matches) {
                    cout << idx << " ";
                }
                cout << endl;
            } else {
                cout << "Шаблон не знайдено." << endl;
            }
        } else if (choice == '2') {
            cout << "Введіть шаблон для пошуку: ";
            getline(cin, pattern);
            vector<size_t> matches = KMPCaseInsensitive(text, pattern);
            if (!matches.empty()) {
                cout << "Шаблон знайдено на позиціях: ";
                for (size_t idx : matches) {
                    cout << idx << " ";
                }
                cout << endl;
            } else {
                cout << "Шаблон не знайдено." << endl;
            }
        } else if (choice == '3') {
            cout << "Введіть шаблон для пошуку: ";
            getline(cin, pattern);
            cout << "Введіть слово для заміни: ";
            getline(cin, replacement);
            string newText = replacePattern(text, pattern, replacement);
            cout << "Новий текст: " << newText << endl;
        } else if (choice == '4') {
            cout << "Введіть слово для заміни слів довше 7 символів: ";
            getline(cin, replacement);
            string newText = replaceLongWords(text, replacement);
            cout << "Новий текст: " << newText << endl;
        }
    } while (choice != '5');

    return 0;
}

