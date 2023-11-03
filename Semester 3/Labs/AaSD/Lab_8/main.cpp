#include <iostream>
using namespace std;

// Функция для получения максимального элемента в массиве
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Функция для сортировки массива по указанному разряду
void countSort(int arr[], int n, int exp) {
    const int radix = 10; // основание системы исчисления
    int output[n]; // создаем временный массив для хранения отсортированных данных
    int count[radix] = { 0 }; // создаем массив подсчета

    // Считаем количество элементов соответствующего разряда и сохраняем в массиве подсчета
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % radix]++;
    }

    // Изменяем массив подсчета, чтобы он содержал информацию о позициях элементов
    for (int i = 1; i < radix; i++) {
        count[i] += count[i - 1];
    }

    // Строим выходной массив
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % radix] - 1] = arr[i];
        count[(arr[i] / exp) % radix]--;
    }

    // Копируем отсортированный массив обратно в исходный массив
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Функция для поразрядной сортировки
void radixSort(int arr[], int n) {
    // Получаем максимальный элемент, чтобы узнать наибольшее количество разрядов
    int max = getMax(arr, n);

    // Сортируем массив для каждого разряда, начиная с младшего до старшего
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSort(arr, n, exp);
    }
}

int main() {
    int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
    int n = sizeof(arr) / sizeof(arr[0]);

    radixSort(arr, n);

    cout << "Отсортированный массив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}