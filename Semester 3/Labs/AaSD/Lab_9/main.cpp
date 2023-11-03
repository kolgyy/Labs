#include <iostream>

using std::cout;
using std::cin;
using std::endl;



void Shell_sort(int arr[], int size) { 
	for (int step = size / 2; step > 0; step /= 2) { // Ќачинаем с большего шага, затем уменьшаем его, цикл продолжаетс€ до тех пор, пока gap больше 0
		// Ќа каждой итерации мы уменьшаем gap в два раза.
		for (int i = step; i < size; i++) { // ѕримен€ем сортировку вставками
			for (int j = i - step; j >= 0 && arr[j] > arr[j + step]; j -= step) { // —равниваем два элемента, которые наход€тс€ на рассто€нии step
				int temp = arr[j];
				arr[j] = arr[j + step];
				arr[j + step] = temp;
			}
		}

	}
	
}
int main() {
	int arr[] = { 5, 9, 4, 3, 1, 2 }; // 
	int size = sizeof(arr) / sizeof(arr[0]); // ƒлина = размер всего массива в байтах / размер первого элемента в байтах

	Shell_sort(arr, size);

	cout << "Sorted array: " << endl;
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}



	return 0;
}