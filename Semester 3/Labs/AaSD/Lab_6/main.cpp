#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// Selection sort // 
// Сложность O(n^2) //

void Selection_sort(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) { // Начинаем проходить с первого элемента до предпоследнего, тот элемент, относительно которого ищем минимальный
		int min_index = i;
		for (int j = i + 1; j < size; j++) { // Находим индекс минимального элемента
			if (arr[j] < arr[min_index]) {
				min_index = j;
			}
		}
		if (i != min_index) { // Если указатели i и минимального элемента не равны, то меняем их местами
			int temp = arr[min_index];
			arr[min_index] = arr[i];
			arr[i] = temp;
		}
	}
}
int main() {
	int arr[] = { 0, 8, 3, 1, 2 };
	int size = sizeof(arr) / sizeof(arr[0]); // Длина = размер всего массива в байтах / размер первого элемента в байтах

	Selection_sort(arr, size);

	cout << "Sorted array: " << endl;
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}





	return 0;
}
