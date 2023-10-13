#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

void calculating_numbers(int x) {
	vector<int> numbers;
	for (int k = 0; k <= log(x) / log(3); k++) {
		for (int l = 0; l <= log(x) / log(5); l++) {
			for (int m = 0; m <= log(x) / log(7);) {
				int number = pow(3, k) * pow(5, l) * pow(7, m);
				if (number <= x) {
					numbers.push_back(number);
				}
			}
		}
	}
	for (int i = 0; i < numbers.size(); i++) {
		cout << numbers[i] << " ";
	}
}



int main() {
	setlocale(LC_ALL, "Russian");
	int x;
	cout << "¬ведите число: " << endl;
	cin >> x;
	cout << "„исла, удовлетвор€ющие условию: " << endl;
	
	calculating_numbers(x);

	return 0;
}