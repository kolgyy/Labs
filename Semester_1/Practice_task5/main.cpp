
/*
Задача учебной практики 5
Вам предлагается создать класс, который опишет умный динамический массив из целых чисел. Количество чисел заранее неизвестно. Ограничением служит размер доступной оперативной памяти компьютера, но использовать память все же надо рационально.
Что он должен уметь:
1.	Добавлять элемент в конец.
2.	Выдавать текущее количество элементов.
3.	Выдавать элемент по индексу.
4.	Изменять элемент по индексу.
5.	Удалять элемент по индексу.
6.	Вставлять элемент по индексу.
*/

#include <iostream>

class IntVector {
private:
    int* m_arr; // Указатель на динамически выделенную память
    size_t m_size; // Количество добавленных в массив элементов
    size_t m_capacity; // Вместимость массива

    // Метод, который выбрасывает исключение если индекс больше или равен количеству добавленных в массив элементов
    void checkIndex(size_t index) {
        if (index >= m_size) {
            throw std::runtime_error("index is out of range");
        }
    }

     // Метод, который увеличивает вместимость массива, перевыделяет память и копирует все элементы в новый массив
    void realloc() {
        m_capacity *= 2;

        int* newArr = new int[m_capacity];

        for (size_t i = 0; i < m_size; i++) {
            newArr[i] = m_arr[i];
        }

        delete[] m_arr;

        m_arr = newArr;
    }
public:
    // Конструктор, принимающий вместимость, по умолчанию 8
    IntVector(size_t capacity = 8) : m_arr(new int[capacity]), m_size(0), m_capacity(capacity) {
        if (capacity == 0) {
            throw std::runtime_error("initial capacity cannot be zero");
        }
    }

    // Деструктор, который освобождает память
    ~IntVector() {
        delete[] m_arr;
    }

    // Метод, который добавляет элемент в конец
    void add(int value) {
        if (m_size >= m_capacity) {
            realloc();
        }
        m_arr[m_size++] = value;
    }

     // Метод, который возвращает элемент по индексу
    int get(size_t index) {
        checkIndex(index);
        return m_arr[index];
    }

    // Метод, который вставляет элемент по индексу
    void insert(size_t index, int value) {
        checkIndex(index);

        m_size++;

        if (m_size >= m_capacity) {
            realloc();
        }

        for (size_t i = m_size - 1; i > index; i--) {
            m_arr[i] = m_arr[i - 1];
        }

        m_arr[index] = value;
    }

    // Метод, который заменяет элемент по индексу
    void replace(size_t index, int value) {
        checkIndex(index);
        m_arr[index] = value;
    }

    // Метод, который удаляет элемент по индексу
    void remove(size_t index) {
        checkIndex(index);

        for (size_t i = index; i < m_size - 1; i++) {
            m_arr[i] = m_arr[i + 1];
        }

        m_size -= 1;
    }

    // Метод, который возвращает количество элементов добавленных в массив
    size_t size() {
        return m_size;
    }

    // Метод, который возвращает вместимость массива
    size_t capacity() {
        return m_capacity;
    }

    // Метод, который перебирает и выводит в консоль все добавленные в массив элементы
    void print() {
        for (size_t i = 0; i < m_size; i++) {
            std::cout << i << ": \t" << m_arr[i] << std::endl;
        }
    }
};

int main() {
    IntVector intVector(1);
    intVector.add(1);
    intVector.add(3);
    intVector.add(-1);
    intVector.add(5);

    intVector.insert(1, 2);
    intVector.remove(intVector.size() - 2);
    intVector.insert(intVector.size() - 1, 4);

    intVector.print();
}