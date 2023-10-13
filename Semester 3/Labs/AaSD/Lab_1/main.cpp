#include <iostream>
#include <string>
#include <stack>


using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::stack;

bool string_reading(const string& str) {
	stack<char> stack; // Создаём стек
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


int main() {

	setlocale(LC_ALL, "Russian");
	cout << "Введите строку: " << endl;
	string str;
	cin >> str;

	if (string_reading(str)) {
		cout << "Строка существует." << endl;
	}
	else {
		cout << "Строка НЕ существует." << endl;
	}
	



	return 0;

}