#include <iostream>
#include <string>
#include <math.h>
#include "Functions.h"

// Вариант-4.
//Дана целочисленная матрица {Aij}i=1...n;j=1..n , n<=100.
// Если в матрице есть еще один элемент, равный ее минимальному элементу, и не менее 2-х элементов,
// абсолютные величины которых - простые числа,
// упорядочить строки матрицы по невозрастанию произведений элементов.

// Например, если возьмем матрицу
// 1 5 6
// 7 8 1
// 3 2 2 // Мы видим здесь два минимальных числа - 1, а так же есть два простых - 5 и 7, значит, алгоритм должен сработать
/////////////////////////////
// Получаем:
// 7 8 1
// 1 5 6
// 3 2 2

int main() {
    int rows, cols;
    std::cout << "Enter numbers of rows: " << std::endl;
    std::cin >> rows;
    std::cout << std::endl;
    std::cout << "Enter numbers of columns: " << std::endl;
    std::cin >> cols;
    std::cout << std::endl;

    int** arr = new int* [rows];

    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }
    ///////////////////////////////////////////////
    // Заполнение массива //

    killer::fill_array(arr, rows, cols);

    ///////////////////////////////////////////////
    // Обработка массива //

    if ((killer::is_the_program_ok_or_not_1(arr, rows, cols)) && (killer::is_the_program_ok_or_not_2(arr, rows, cols))) {
        killer::swap_rows_part(arr, rows, cols);
    }

    // Вывод массива //

    killer::show_array(arr, rows, cols);

    ///////////////////////////////////////////////
    //  Очищение массивов. //

    killer::kill_array(arr, rows);
}