#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// Insertion sort //


void Insertion_sort(int* arr, int size) {
	// �� ������� ����� �� ��������� �� ����������������� ����� �������
	int i, j, key; //
	for (i = 1; i < size; i++) { // �������� ��������� �� 2 ��������, ��� ��� ������ ��������� � ���������������� �������
		key = arr[i]; // ��� ��� �������, ������� �� ����� ��������� �������� � ��������������� ����� �������
		j = i - 1; // ���� ����� �� ������������� ��������� i �� ��������� ������� � ��������������� �����.
		// ���� while �������� �������� ����� � �������� ����� ���������� ����� � ��������������� �����.
		while (j >= 0 && arr[j] > key) { // j >= 0 ��� ����, ����� ��������� j �� ���� �� ������ ����� (� ������������� �����).
			// arr[j] > key - �� ���������� �������, �� ������� ��������� j � ��� ���������, ������� �� ����� ��������� �������������.
			arr[j + 1] = arr[j]; // ���� ������� j ������, �� �� ��������� ��� ������.
			arr[j] = key; // � �� ������� ����� ������ ��� �������, �������� ���� �����.
			j--; // ����� ��������� j, ����� ����� �� ����� while � ��� ������, ����� ������ ����� ������ ���������������.

		}
	}
}


int main() {

	setlocale(LC_ALL, "Russian");
	int size;
	cout << "������� ������ �������: " << endl;
	cin >> size;
	
	int* arr = new int [size];
	
	cout << "������� �������� �������: " << endl;
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}

	Insertion_sort(arr, size);

	cout << "��������������� ������: " << endl;
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}

	delete[] arr; // �� �������� ��������� ������!

	return 0;
}