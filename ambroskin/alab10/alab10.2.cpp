#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Card {
    string suit;
    string value;
};


void printDeck(const vector<Card>& deck) {
    for (const auto& card : deck) {
        cout << card.value << " " << card.suit << " ";
    }
    cout << endl;
}


bool compareBySuit(const Card& a, const Card& b) {
    return a.suit < b.suit;
}


bool compareByValue(const Card& a, const Card& b) {
    vector<string> values = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    auto itA = find(values.begin(), values.end(), a.value);
    auto itB = find(values.begin(), values.end(), b.value);
    return itA < itB;
}

int main() {
    vector<Card> deck = {
            {"Піки", "A"}, {"Черви", "K"}, {"Бубни", "10"}, {"Хрести", "3"},
            {"Піки", "2"}, {"Черви", "Q"}, {"Бубни", "9"}, {"Хрести", "J"},
            {"Піки", "K"}, {"Черви", "5"}, {"Бубни", "A"}, {"Хрести", "7"}
    };

    cout << "Несортована колода: ";
    printDeck(deck);

    sort(deck.begin(), deck.end(), compareBySuit);
    cout << "Колода, відсортована за мастю: ";
    printDeck(deck);

    stable_sort(deck.begin(), deck.end(), compareByValue);
    cout << "Колода, відсортована за мастю та номіналом: ";
    printDeck(deck);

    return 0;
}
