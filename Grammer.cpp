#include <iostream>
#include <string>
using namespace std;

bool checkGrammar(const string &str, int &index) {
    if (index >= str.size()) return true;
    
    if (str[index] == 'a') {
        index++;
        if (checkGrammar(str, index)) {
            if (index < str.size() && str[index] == 'b') {
                index++;
                return true;
            }
        }
        return false;
    }
    return false;
}

bool isStringInGrammar(const string &str) {
    int index = 0;
    if (checkGrammar(str, index) && index == str.size()) {
        return true;
    }
    return false;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    if (isStringInGrammar(input)) {
        cout << "The string belongs to the grammar." << endl;
    } else {
        cout << "The string does not belong to the grammar." << endl;
    }

    return 0;
}