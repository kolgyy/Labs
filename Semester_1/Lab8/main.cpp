/*Вариант 4.
Дано целое число типа unsigned short, выведите на экран содержимое каждого из его байтов, используя знания по указателям.Дайте обоснование полученному результату.*/

#include <iostream>
using std::cout;
using std::endl;

int main() {
		unsigned short value = USHRT_MAX;

		unsigned char* ptr  = (unsigned char*)&value; // // Приводим адрес переменной к типу unsigned char*


		for (int i = 0; i < 2; i ++) { // Выводим содержимое каждого байта, два раза, так как unsigned short занимает 2 байта.

			ptr += i; //  Перемещаем адрес вперед 

			std::cout << +(*ptr) << std::endl; //Выводим
	}

}
