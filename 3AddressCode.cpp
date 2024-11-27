#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void generateThreeAddressCode(const string &expression) {
    stack<string> operands;
    stack<char> operators;
    int tempCount = 1;

    for (size_t i = 0; i < expression.length(); ++i) {
        char ch = expression[i];

        if (isspace(ch)) continue;

        if (isalnum(ch)) {
            string operand(1, ch);
            while (i + 1 < expression.length() && isalnum(expression[i + 1])) {
                operand += expression[++i];
            }
            operands.push(operand);
        } 
        else if (isOperator(ch)) {
            while (!operators.empty() && precedence(operators.top()) >= precedence(ch)) {
                string op2 = operands.top();
                operands.pop();
                string op1 = operands.top();
                operands.pop();
                char op = operators.top();
                operators.pop();

                string temp = "t" + to_string(tempCount++);
                cout << temp << " = " << op1 << " " << op << " " << op2 << endl;
                operands.push(temp);
            }
            operators.push(ch);
        }
    }

    while (!operators.empty()) {
        string op2 = operands.top();
        operands.pop();
        string op1 = operands.top();
        operands.pop();
        char op = operators.top();
        operators.pop();

        string temp = "t" + to_string(tempCount++);
        cout << temp << " = " << op1 << " " << op << " " << op2 << endl;
        operands.push(temp);
    }
}

int main() {
    string expression;
    cout << "Enter an arithmetic expression: ";
    getline(cin, expression);

    cout << "\nThree-address code:\n";
    generateThreeAddressCode(expression);

    return 0;
}
