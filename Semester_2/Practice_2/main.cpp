#include <iostream>
using std::endl;
using std::cout;
using std::cin;


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

int* ptr_mas_a = mas_a;
int* ptr_mas_b = mas_b;
int* ptr_end = ptr_mas_a + N;

for (; ptr_mas_a != ptr_end; ++ptr_mas_a, ++ptr_mas_b)
	*ptr_mas_b = *ptr_mas_a;

for (int i = 0; i < N; ++i) {
	cout << mas_b[i] << " ";
}


return 0;
}
