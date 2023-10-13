
#include <iostream> 
#include <stack> 
#include <string> 
#include <cmath> 
/// Reverse Polish Notation, RPN /// 
using std::cout;
using std::endl;
using std::cin;
using std::stack;
using std::string;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int getPriority(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    else if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

double calculate(double a, double b, char op) {
    switch (op) {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        if (b != 0) {
            return a / b;
        }
        else {
            throw "Division by zero!";
        }
    default:
        throw "Invalid operator!";
    }
}

double evaluateExpression(const string& expression) {
    stack<double> operands;
    stack<char> operators;

    for (int i = 0; i < expression.length(); i++) {
        if (isdigit(expression[i])) {
            string operand;
            while (i < expression.length() && (isdigit(expression[i]) || expression[i] == '.')) {
                operand += expression[i];
                i++;
            }
            i--;

            operands.push(stod(operand));
        }
        else if (expression[i] == '(' && expression[i+1] == '-') {
            operators.push(expression[i]);
            operators.push(expression[i + 1]);
        }
        else if (expression[i] == '(') {
            operators.push(expression[i]);
        }
        else if (expression[i] == ')') {
            while (!operators.empty() && operators.top() != '(') {
                double b = operands.top();
                operands.pop();
                double a = operands.top();
                operands.pop();
                char op = operators.top();
                operators.pop();

                double result = calculate(a, b, op);
                operands.push(result);
            }
            operators.pop();
        }
        else if (isOperator(expression[i])) {
            while (!operators.empty() && getPriority(operators.top()) >= getPriority(expression[i])) {
                double b = operands.top();
                operands.pop();
                double a = operands.top();
                operands.pop();
                char op = operators.top();
                operators.pop();

                double result = calculate(a, b, op);
                operands.push(result);
            }
            operators.push(expression[i]);
        }
    }

    while (!operators.empty()) {
        double b = operands.top();
        operands.pop();
        double a = operands.top();
        operands.pop();
        char op = operators.top();
        operators.pop();

        double result = calculate(a, b, op);
        operands.push(result);
    }

    return operands.top();
}

int main() {
    string equation_1 = "(1+2*(3+4*(3-2*(4-2))))=";
    string equation_2 = "((-28+34*2*5)*5*(-10)-1)=";
    string equation_3 = "(8-5*(4/2))=";
    string equation_4 = "1+(9*((4*7/(-2))*(-1)))=";
    string expression;
    // cout << "Enter the mathematical expression: "; 
    // cin >> expression; 

    try {
        double result = evaluateExpression(equation_4);
        cout << "Result: " << result << endl;
    }
    catch (const char* error) {
        cout << "Error: " << error << endl;
    }

    return 0;
}