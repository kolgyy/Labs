#include <iostream>
#include <chrono>
using std::endl;
using std::cout;
using std::cin;

int main(){

	const int N = 10000;
	int mas_a[N] = { 1, 2, 4, 5, 7 };
	int mas_b[N] = { 0 };

	auto begin = std::chrono::steady_clock::now();
	for (int i = 0; i < N; ++i) {
		mas_b[i] = mas_a[i];
	}
	auto end = std::chrono::steady_clock::now();
	auto elapsed_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
	cout << "The first algorithm took : " << elapsed_ms.count() << endl;
	////////////////////////////////////////////////

	int num_1[N] = { 1, 2, 4, 5, 7 };
	int num_2[N] = { 0 };

	auto begin1 = std::chrono::steady_clock::now();

	const long long* ptr1 = (const long long*)num_1; // Берём указатель на массив, указатель занимает теперь в памяти 8 байт вместо 4.

	long long* ptr2 = (long long*)num_2;

	int number_of_iterations = (sizeof(int) * N) / sizeof(long long); // Кол-во лонг лонгов, помещающихся в объем памяти, занимаемый интовым массивом

	for (int i = 0; i < number_of_iterations; ++i) {
		*(ptr2++) = *(ptr1++); // Получаем в два раза прирост копирования, так как копируем по 8 байт вместо 4
	}

	const char* other_types_ptr1 = (char*)ptr1; 

	char* other_types_ptr2 = (char*)ptr2;

	int other_iterations = (sizeof(int) * N) % sizeof(long long);

	for (int i = 0; i < other_iterations; ++i) { // Копируем остатки
		*(other_types_ptr2++) = *(other_types_ptr1++);
	}
	auto end1 = std::chrono::steady_clock::now();

	auto elapsed_ms1 = std::chrono::duration_cast<std::chrono::microseconds>(end1 - begin1); // В среднем второй алгоритм получается в два раза эффективнее.
	cout << "The second algorithm took : " << elapsed_ms1.count() << endl;
	//////////

	/*std::string str1 = "Hello, world!";
	std::string str2(str1.size(), ' ');

	const long long* ptr1 = (const long long*)str1.data();
	long long* ptr2 = (long long*)str2.data();

	int number_of_iterations = (sizeof(char) * str1.size()) / sizeof(long long);

	for (int i = 0; i < number_of_iterations; ++i) {
		*(ptr2++) = *(ptr1++);
	}

	const char* other_types_ptr1 = (char*)ptr1;
	char* other_types_ptr2 = (char*)ptr2;

	int other_iterations = (sizeof(char) * str1.size()) % sizeof(long long);

	for (int i = 0; i < other_iterations; ++i) {
		*(other_types_ptr2++) = *(other_types_ptr1++);
	}
	cout << str2 << endl;
	*/


return 0;
}
