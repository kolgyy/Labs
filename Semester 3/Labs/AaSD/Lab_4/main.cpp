#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// Bubblesort //


void Bubblesort(int* arr, int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - 1 - i; j++) {
			if (arr[j] > arr[j+1]){

				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;

			}
		}
	}
}


int main() {

	setlocale(LC_ALL, "Russian");
	int size;
	cout << "Введите размер массива: " << endl;
	cin >> size;
	
	int* arr = new int [size];
	
	cout << "Введите элементы массива: " << endl;
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}

	Bubblesort(arr, size);

	cout << "Отсортированный массив: " << endl;
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}

	delete[] arr; // Не забываем отчистить память!

	return 0;
}
