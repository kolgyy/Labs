#include <iostream>
#include <stack>
#include <string>
#include <cctype>

bool isOperator(char c) { // Является ли символ оператором (+, -, *, /).
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool string_reading(const std::string& str) { // Проверка на корректность
    std::stack<char> stack; // Создаём стек
    for (char symbol : str) {
        if (symbol == '(' || symbol == '{' || symbol == '[') { // Если символ - открывающая скобка, то добавляем её в стек
            stack.push(symbol);
        }
        else if (symbol == ')' || symbol == '}' || symbol == ']') { // Если символ - закрывающая скобка, то проверяем, есть ли соответствующая скобка в стеке
            if (stack.empty()) { // Если стек пустой, то и проверять нечего!
                return false;
            }

            char top = stack.top(); // Берем верхний элемент стека
            // Проверяем, что верхний элемент стека является открывающей скобкой для закрывающей скобки:
            if ((symbol == ')' && top == '(') || (symbol == '}' && top == '{') || (symbol == ']' && top == '[')) {
                stack.pop(); // Если это так, то удаляем верхний элемент
            }
            else { // Если нет, то выводим ложь
                return false;
            }

        }

    }
    return stack.empty(); // Если стек пустой, значит все скобки нашли свою пару ♥
}


int getPrecedence(char op) { // Возвращает приоритет оператора.
    if (op == '+' || op == '-') {
        return 1;
    }
    else if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

void applyOperator(std::stack<int>& numbers, char op) { // Применяет оператор к двум верхним элементам стека чисел.
    int b = numbers.top();
    numbers.pop();
    int a = numbers.top();
    numbers.pop();
    switch (op) {
    case '+':
        numbers.push(a + b);
        break;
    case '-':
        numbers.push(a - b);
        break;
    case '*':
        numbers.push(a * b);
        break;
    case '/':
        if (b == 0) {
            throw std::runtime_error("Division by zero error");
        }
        numbers.push(a / b);
        break;
    }
}

int evaluateExpression(const std::string& expression) { // Вычисляет значение математического выражения, переданного в виде строки.
    if (string_reading(expression) == false)
        throw std::runtime_error("Unbalanced parentheses error");
    std::stack<int> numbers; // Создаются два стека: один для чисел и один для операторов.
    std::stack<char> ops;
    
    for (size_t i = 0; i < expression.length(); i++) { //  Происходит итерация по каждому символу в строке выражения.
        if (expression[i] == ' ') { //  Если символ - это пробел, он игнорируется.
            continue;
        }
        else if (isdigit(expression[i]) || (expression[i] == '-' && (i == 0 || !isdigit(expression[i - 1]) && expression[i - 1] != ')'))) { 
            //  Если символ - это цифра или знак минус (если он первый или идет после открывающей скобки), то число извлекается из строки и помещается в стек чисел.
            int num = 0;
            int sign = 1;
            if (expression[i] == '-') {
                sign = -1;
                i++;
            }
            while (i < expression.length() && isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            i--;
            numbers.push(num * sign);
        }
        else if (expression[i] == '(') {
            // Если символ - это открывающая скобка, она помещается в стек операторов.
            ops.push(expression[i]);
        }
        else if (expression[i] == ')') {
         //Если символ - это закрывающая скобка, все операторы из стека операторов применяются к числам из стека чисел до тех пор, пока не встретится открывающая скобка.
            while (!ops.empty() && ops.top() != '(') {
                applyOperator(numbers, ops.top());
                ops.pop();
            }
            ops.pop();
        }
        else if (isOperator(expression[i])) { 
        // Если символ - это оператор (+, -, *, /), то все операторы с более высоким или равным приоритетом из стека операторов применяются к числам из стека чисел,
            // а затем текущий оператор помещается в стек операторов.
            while (!ops.empty() && getPrecedence(ops.top()) >= getPrecedence(expression[i])) {
                applyOperator(numbers, ops.top());
                ops.pop();
            }
            ops.push(expression[i]);
        }
        else if (expression[i] == '=') { 
            // Если символ - это знак равенства, все оставшиеся операторы применяются к числам из стека чисел.
            while (!ops.empty()) {
                applyOperator(numbers, ops.top());
                ops.pop();
            }
        }
    }
    return numbers.top();
}

int main() {
    std::string equation_1 = "(1+2*(3+4*(3-2*(4-2))))=";
    std::string equation_2 = "((-28+34*2*5)*5*(-10)-1)="; // Деление на ноль.
    std::string equation_3 = "(8-5*(4/(2-2)))=";
    std::string equation_4 = "1+(9*((4*7/(-2))*(-1)))=";
    std::string equation_5 = "(5+3))="; // Некорректные скобки.

    try {
        int result = evaluateExpression(equation_2);
        std::cout << "Result: " << result << std::endl;
    }
    catch (const std::runtime_error& er) {
        std::cout << "Error: " << er.what() << std::endl;
    }

    return 0;
}




