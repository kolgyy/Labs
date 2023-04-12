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
// void* - указатель на неопределенный тип данных, чтобы функция могла работать с блоками памяти разных типов данных
// size_t определяет размер области памяти

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

// Подход копирования правильный, но в случае с большими массивами скорость увеличится, хоть и линейно.
// Для улучшения можно использовать другие алгоритмы, например, memcpy().
// Она копирует один блок памяти в другой, она является внутренней функцией, поэтому код может быть быстро скомпилирован в машинный код.
// ↑ Напишем её ↑



memcpy(mas_b, mas_a, N);

for (int i = 0; i < N; ++i) {
	cout << mas_b[i] << " ";
}

return 0;
}
