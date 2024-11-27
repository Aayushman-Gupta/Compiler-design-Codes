#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class SymbolTable {
private:
    unordered_map<string, string> table;

public:
    void insert(string name, string type) {
        table[name] = type;
    }

    bool search(string name) {
        return table.find(name) != table.end();
    }

    void display() {
        cout << "Symbol Table:" << endl;
        cout << "Name\tType" << endl;
        for (const auto &entry : table) {
            cout << entry.first << "\t" << entry.second << endl;
        }
    }
};

int main() {
    SymbolTable symbolTable;
    int choice;
    string name, type;

    do {
        cout << "\n1. Insert\n2. Search\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter type: ";
                cin >> type;
                symbolTable.insert(name, type);
                break;
            case 2:
                cout << "Enter name to search: ";
                cin >> name;
                if (symbolTable.search(name)) {
                    cout << "Symbol found." << endl;
                } else {
                    cout << "Symbol not found." << endl;
                }
                break;
            case 3:
                symbolTable.display();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    } while (choice != 4);

    return 0;
}
