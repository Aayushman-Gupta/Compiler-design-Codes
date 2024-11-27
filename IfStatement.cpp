#include <iostream>
#include <string>
#include <sstream> 
#include <cstdlib> 
bool evaluateExpression(const std::string& expr) {
    int result;
    std::istringstream ss(expr);
    ss >> result;
    if (ss.fail()) {
        std::cerr << "Invalid expression." << std::endl;
        exit(1); 
    }
    return result != 0; 
}

int main() {
    std::string expr;
    std::cout << "Enter a statement (expression): ";
    std::getline(std::cin, expr);
    bool result = evaluateExpression(expr);
    if (result) {
        std::cout << "The statement is TRUE." << std::endl;
    } else {
        std::cout << "The statement is FALSE." << std::endl;
    }
    
    return 0;
}
