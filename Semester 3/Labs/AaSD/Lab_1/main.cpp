#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

bool string_reading(string str) {
	for (int i = 0; i < str.length(); i++) {
		if (str[i] != '[' && str[i] != '{' && str[i] != '('
			&& str[i] != ']' && str[i] != '}' && str[i] != ')') {
			return false;
		}
	}
	return true;
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