#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// Selection sort // 
// ��������� O(n^2) //

void Selection_sort(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) { // �������� ��������� � ������� �������� �� ��������������, ��� �������, ������������ �������� ���� �����������
		int min_index = i;
		for (int j = i + 1; j < size; j++) { // ������� ������ ������������ ��������
			if (arr[j] < arr[min_index]) {
				min_index = j;
			}
		}
		if (i != min_index) { // ���� ��������� i � ������������ �������� �� �����, �� ������ �� �������
			int temp = arr[min_index];
			arr[min_index] = arr[i];
			arr[i] = temp;
		}
	}
}
int main() {
	int arr[] = { 0, 8, 3, 1, 2 };
	int size = sizeof(arr) / sizeof(arr[0]); // ����� = ������ ����� ������� � ������ / ������ ������� �������� � ������

	Selection_sort(arr, size);

	cout << "Sorted array: " << endl;
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}





	return 0;
}