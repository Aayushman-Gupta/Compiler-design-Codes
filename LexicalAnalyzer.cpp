#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <unordered_set>

using namespace std;

unordered_set<string> keywords = {
    "int", "float", "if", "else", "while", "return", "void", "for", "char", "double"
};

bool isKeyword(const string &str) {
    return keywords.find(str) != keywords.end();
}

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=' || ch == '<' || ch == '>' || ch == '!';
}

bool isDelimiter(char ch) {
    return ch == ' ' || ch == ',' || ch == ';' || ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == '[' || ch == ']';
}

bool isNumber(const string &str) {
    for (char ch : str) {
        if (!isdigit(ch)) return false;
    }
    return !str.empty();
}

bool isIdentifier(const string &str) {
    if (!isalpha(str[0]) && str[0] != '_') return false;
    for (char ch : str) {
        if (!isalnum(ch) && ch != '_') return false;
    }
    return true;
}

vector<string> tokenize(const string &input) {
    vector<string> tokens;
    string current;
    for (size_t i = 0; i < input.size(); ++i) {
        char ch = input[i];

        if (isDelimiter(ch)) {
            if (!current.empty()) {
                tokens.push_back(current);
                current.clear();
            }
            if (!isspace(ch)) {
                string temp(1, ch);
                tokens.push_back(temp);
            }
        } else if (isOperator(ch)) {
            if (!current.empty()) {
                tokens.push_back(current);
                current.clear();
            }
            string temp(1, ch);
            if (i + 1 < input.size() && isOperator(input[i + 1])) {
                temp += input[++i];
            }
            tokens.push_back(temp);
        } else {
            current += ch;
        }
    }
    if (!current.empty()) {
        tokens.push_back(current);
    }
    return tokens;
}

void analyze(const string &input) {
    vector<string> tokens = tokenize(input);
    for (const string &token : tokens) {
        if (isKeyword(token)) {
            cout << token << " : Keyword" << endl;
        } else if (isNumber(token)) {
            cout << token << " : Number" << endl;
        } else if (isIdentifier(token)) {
            cout << token << " : Identifier" << endl;
        } else if (isOperator(token[0])) {
            cout << token << " : Operator" << endl;
        } else if (isDelimiter(token[0])) {
            cout << token << " : Delimiter" << endl;
        } else {
            cout << token << " : Unknown" << endl;
        }
    }
}

int main() {
    string input;
    cout << "Enter a line of code: ";
    getline(cin, input);

    cout << "\nLexical Analysis:\n";
    analyze(input);

    return 0;
}


// output  int x = 10 + 20; if (x > 15) x = x * 2;