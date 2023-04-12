#include <iostream>
using std::endl;
using std::cout;
using std::cin;

void* memcpy(void* destination, const void* source, size_t num) {

	int* dest = (int*)destination;
	int* src = (int*)source;
	for (size_t i = 0; i < num; ++i) {
		dest[i] = src[i];
	}
	return destination;
}

// void* - ��������� �� �������������� ��� ������, ����� ������� ����� �������� � ������� ������ ������ ����� ������
// size_t ���������� ������ ������� ������

int main() {

const int N = 1000;
int mas_a[N] = { 1,2,3,4,5 };
int mas_b[N] = { 0 };

// for (int i = 0; i < N; ++i)
//     mas_b[i] = mas_a[i];

for (int i = 0; i < N; ++i) {
	cout << mas_b[i] << " ";
}
cout << endl << endl;

// ������ ����������� ����������, �� � ������ � �������� ��������� �������� ����������, ���� � �������.
// ��� ��������� ����� ������������ ������ ���������, ��������, memcpy().
// ��� �������� ���� ���� ������ � ������, ��� �������� ���������� ��������, ������� ��� ����� ���� ������ ������������� � �������� ���.
// ������� �



memcpy(mas_b, mas_a, N);

for (int i = 0; i < N; ++i) {
	cout << mas_b[i] << " ";
}

return 0;
}
