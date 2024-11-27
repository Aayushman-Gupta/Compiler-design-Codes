#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class TypeChecker {
private:
    unordered_map<string, string> symbolTable;

public:
    void declareVariable(string name, string type) {
        symbolTable[name] = type;
    }

    bool checkAssignment(string name, string value) {
        if (symbolTable.find(name) == symbolTable.end()) {
            cout << "Error: Variable " << name << " not declared." << endl;
            return false;
        }
        
        string varType = symbolTable[name];

        if (varType == "int" && isInteger(value)) {
            return true;
        }
        if (varType == "float" && isFloat(value)) {
            return true;
        }
        if (varType == "char" && value.length() == 1) {
            return true;
        }
        cout << "Error: Type mismatch for variable " << name << " with value " << value << endl;
        return false;
    }

    bool isInteger(string value) {
        for (char c : value) {
            if (!isdigit(c)) return false;
        }
        return true;
    }

    bool isFloat(string value) {
        bool dotFound = false;
        for (char c : value) {
            if (c == '.') {
                if (dotFound) return false;
                dotFound = true;
            } else if (!isdigit(c)) {
                return false;
            }
        }
        return dotFound;
    }
};

int main() {
    TypeChecker typeChecker;
    int choice;
    string name, type, value;

    do {
        cout << "\n1. Declare Variable\n2. Check Assignment\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter variable name: ";
                cin >> name;
                cout << "Enter variable type (int, float, char): ";
                cin >> type;
                typeChecker.declareVariable(name, type);
                break;
            case 2:
                cout << "Enter variable name: ";
                cin >> name;
                cout << "Enter value to assign: ";
                cin >> value;
                if (typeChecker.checkAssignment(name, value)) {
                    cout << "Assignment successful." << endl;
                }
                break;
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    } while (choice != 3);

    return 0;
}
