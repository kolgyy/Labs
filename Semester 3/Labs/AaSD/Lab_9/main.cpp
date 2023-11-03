#include <iostream>

using std::cout;
using std::cin;
using std::endl;



void Shell_sort(int arr[], int size) { 
	for (int step = size / 2; step > 0; step /= 2) { // �������� � �������� ����, ����� ��������� ���, ���� ������������ �� ��� ���, ���� gap ������ 0
		// �� ������ �������� �� ��������� gap � ��� ����.
		for (int i = step; i < size; i++) { // ��������� ���������� ���������
			for (int j = i - step; j >= 0 && arr[j] > arr[j + step]; j -= step) { // ���������� ��� ��������, ������� ��������� �� ���������� step
				int temp = arr[j];
				arr[j] = arr[j + step];
				arr[j + step] = temp;
			}
		}

	}
	
}
int main() {
	int arr[] = { 5, 9, 4, 3, 1, 2 }; // 
	int size = sizeof(arr) / sizeof(arr[0]); // ����� = ������ ����� ������� � ������ / ������ ������� �������� � ������

	Shell_sort(arr, size);

	cout << "Sorted array: " << endl;
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}



	return 0;
}