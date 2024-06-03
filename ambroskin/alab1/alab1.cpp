#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


void task1() {
    int a, b, c, n;
    cout << "Введіть три числа: ";
    cin >> a >> b >> c;
    cout << "Введіть останню цифру вашого номеру: ";
    cin >> n;

    cout << "Числа, які належать інтервалу [1, " << n << "]: ";
    if (a >= 1 && a <= n) cout << a << " ";
    if (b >= 1 && b <= n) cout << b << " ";
    if (c >= 1 && c <= n) cout << c << " ";
    cout << endl;
}


void task2() {
    int a, b, c, n;
    cout << "Введіть три числа: ";
    cin >> a >> b >> c;
    cout << "Введіть останню цифру вашого номеру: ";
    cin >> n;

    if (n % 2 == 0) {
        int minVal = min(a, min(b, c));
        cout << "Мінімальне число: " << minVal << endl;
    } else {
        int maxVal = max(a, max(b, c));
        cout << "Максимальне число: " << maxVal << endl;
    }
}


void task3() {
    int n;
    cout << "Введіть кількість елементів (n): ";
    cin >> n;

    double sum = 0;
    double term = 1;
    cout << "Ряд чисел: ";
    for (int i = 0; i < n; i++) {
        cout << term << " ";
        sum += term;
        term /= -2;
    }
    cout << endl;
    cout << "Сума ряду: " << sum << endl;
}


void task4() {
    int n;
    cout << "Введіть число не менше 2: ";
    cin >> n;

    int divisor = 2;
    while (n % divisor != 0) {
        divisor++;
    }
    cout << "Найменший натуральний дільник, відмінний від 1: " << divisor << endl;
}


void task5() {
    int n;
    cout << "Введіть кількість елементів послідовності Фібоначчі: ";
    cin >> n;

    int a = 0, b = 1;
    cout << "Послідовність Фібоначчі: " << a << " " << b << " ";
    for (int i = 2; i < n; i++) {
        int next = a + b;
        cout << next << " ";
        a = b;
        b = next;
    }
    cout << endl;
}


void task6() {
    srand(time(0));
    int secret = rand() % 21;
    int guess, attempts = 0;

    cout << "Вгадайте число від 1 до 20" << endl;
    do {
        cout << "Введіть число від 0 до 20: ";
        cin >> guess;
        if (guess < 0 || guess > 20) {
            cout << "Невірне значення!!!" << endl;
            continue;
        }
        attempts++;
        if (guess < secret) {
            cout << "Запропоноване число менше задуманого" << endl;
        } else if (guess > secret) {
            cout << "Запропоноване число більше задуманого" << endl;
        } else {
            cout << "Ви вгадали число з " << attempts << " разу!" << endl;
        }
    } while (guess != secret);
}

int main() {
    int choice;
    do {
        cout << "Виберіть завдання:" << endl;
        cout << "1. Вибір чисел, які належать інтервалу [1, №]" << endl;
        cout << "2. Знайти мінімальне або максимальне число серед трьох" << endl;
        cout << "3. Знайти суму n елементів ряду чисел" << endl;
        cout << "4. Найменший натуральний дільник числа, відмінний від 1" << endl;
        cout << "5. Вивести ряд послідовності Фібоначчі" << endl;
        cout << "6. Гра \"Вгадайте число від 1 до 20\"" << endl;
        cout << "7. Вихід" << endl;
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
            case 3:
                task3();
                break;
            case 4:
                task4();
                break;
            case 5:
                task5();
                break;
            case 6:
                task6();
                break;
            case 7:
                cout << "Вихід з програми." << endl;
                break;
            default:
                cout << "Невірний вибір, спробуйте ще раз." << endl;
        }
        cout << endl;
    } while (choice != 7);

    return 0;
}
