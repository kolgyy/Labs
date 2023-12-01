#include <iostream>
#include <time.h>

using std::cin;
using std::cout;
using std::endl;

// Quick sort

void quickSort(int a[], int left, int right) {
	if (left > right) return; // Условие выхода из программы
	int pivot = a[(left + right) / 2];
	int i = left;
	int j = right;
	while (i <= j) {
		while (a[i] < pivot) i++;
		while (a[j] > pivot) j--;
		if (i <= j) {
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	}
	quickSort(a, left, j);
	quickSort(a, i, right);
}
int main() {

	setlocale(LC_ALL, "Russian");
	srand(time(0));
	const int N = 10;
	int a[N];
	cout << "Исходный массив: " << endl;
	for (int i = 0; i < N; i++) {
		a[i] = rand() % 16; // Числа будут от 0 до 15 включительно.
		cout << a[i] << "\t";
	}
	cout << endl;
	quickSort(a, 0, N - 1);
	cout << "Отсортированный массив: " << endl;
	for (int i = 0; i < N; i++) {
		cout << a[i] << "\t";
	}
	cout << endl;

	system("pause");
	return 0;
}

