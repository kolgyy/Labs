#include "Functions.h"
namespace killer {
    int min_array(int** arr, int rows, int cols) {
        int min = INT16_MAX;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (arr[i][j] < min) {
                    min = arr[i][j];
                }
            }
        }
        return min;
    }
    void fill_array(int** arr, int rows, int cols) { // ������� ������
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                std::cout << "Enter a quantity: " << std::endl;
                std::cin >> arr[i][j];
            }
        }
    }
    void show_array(int** arr, int rows, int cols) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                std::cout << arr[i][j] << "  ";
            }
            std::cout << "\n";
        }
    }
    void kill_array(int** arr, int rows) {
        for (int i = 0; i < rows; i++) {
            delete[] arr[i];
        }
        delete[] arr;
    }

    int is_prime(int n) {
        if (n == 0 || n == 1) {
            return false;
        }
        int d = 2;
        while (d * d <= n) {
            if (n % d == 0) {
                return false;
            }
            d++;
        }
        return true;
    }

    int is_the_program_ok_or_not_1(int** arr, int rows, int cols) { // ���������, ���� �� ��� ���� �������, ������ ������������ �������� �������.
        int k = 0; // ������� ���-�� ����������� ���������
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (arr[i][j] == min_array(arr, rows, cols)) {
                    k++;
                    if (k == 2) {
                        return true; // ���� ����� ���� �� ��� ����������� ��������, �� ������.
                    }
                }
            }
        }
        return false; // ����� ����.

    }

    int is_the_program_ok_or_not_2(int** arr, int rows, int cols) {
        int k = 0; // ������� ���-�� ���������, ��� ���������� ��������, - ������� �����.
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (is_prime(abs(arr[i][j]))) {
                    k++;
                    if (k >= 2) {
                        return true; // ���� ����� ���� �� ���, �� ������.
                    }
                }
            }
        }
        return false; // ����� ����.

    }
    int product_of_numbers_in_the_rows(int** arr, int row, int cols) {
        int product = 1; // ��������� ������������ ��������� � ������

        for (int j = 0; j < cols; j++) {
            product = product * arr[row][j];
        }
        return product;
    }


    int swap_rows_part(int**& arr, int rows, int cols) { // ������� ������
        for (int i = 0; i < rows - 1; i++) {
            for (int j = i + 1; j < rows; j++) {
                if ((product_of_numbers_in_the_rows(arr, i, cols)) < product_of_numbers_in_the_rows(arr, j, cols)) {
                    std::swap(arr[i], arr[j]);
                }
            }
        }
        return 0;
    }
}