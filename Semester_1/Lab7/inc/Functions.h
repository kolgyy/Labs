#pragma once
#include <iostream>
namespace killer {
	int min_array(int** arr, int rows, int cols);
	void fill_array(int** arr, int rows, int cols); // Функция чтения
	void show_array(int** arr, int rows, int cols);
	void kill_array(int** arr, int rows);
	int is_prime(int n);
	int is_the_program_ok_or_not_1(int** arr, int rows, int cols);
	int is_the_program_ok_or_not_2(int** arr, int rows, int cols);
	int product_of_numbers_in_the_rows(int** arr, int row, int cols);
	int swap_rows_part(int**& arr, int rows, int cols); // Функция записи
}