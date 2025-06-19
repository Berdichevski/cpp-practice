#include <iostream>
#include <string>
#include <set>

using namespace std;

void passwordVariations(const string& word, int index, string currentPassword, set<string>& passwordSet) {
    if (index == word.length()) {
        passwordSet.insert(currentPassword);
        return;
    }

    passwordVariations(word, index + 1, currentPassword + string(1, tolower(word[index])), passwordSet);

    passwordVariations(word, index + 1, currentPassword + string(1, toupper(word[index])), passwordSet);
}

int main() {
    string word;
    cout << "Insert word in lowercase: ";
    cin >> word;

    set<string> passwordSet;
    passwordVariations(word, 0, "", passwordSet);

    for (const string& password : passwordSet) {
        cout << password << endl;
    }

    return 0;
}