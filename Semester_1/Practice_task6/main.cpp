
/*
Задача учебной практики 6
Изучите основные операции над вектором и продемонстрируйте их работу:
1.	push_back, erase, insert
2.	emplace_back
3.	resize, reserve, shrink_to_fit, capacity
4.	clear
5.	оператор присваивания и []
Узнайте размер вектора и будьте готовы объяснить, почему именно так.
*/
#include <iostream>
#include <vector>



int main() {
    // Память под вектор выделяется на стеке, но вектор хранит свои элементы в хипе
    std::vector<int> vector;

    // Метод reserve изменяет вместимость массива
    vector.reserve(16);

    // Метод resize изменяет количество элементов
    vector.resize(5);

    // Метод capacity возвращает вместимость массива

    std :: cout << "capacity: " << vector.capacity() << std :: endl;

    // Метод push_back добавляет элемент в конец
    for (size_t i = 2; i <= 5; i++) {
        vector.push_back(i);
    }

    // Метод insert добавляет элемент на определенную позицию, все следующие элементы перемещаются вперед на одну позицию

    vector.insert(vector.begin() + 5, 1);

    // Используем метод erase чтобы удалить диапазон элементов
    vector.erase(vector.begin(), vector.begin() + 5);

    // Идём по всем элементам
    for (size_t i = 0; i < vector.size(); i++) {
        // Используем оператор [] чтобы получить элемент по индексу i
        std::cout << vector[i] << std::endl;

        // Используем оператор присваивания чтобы изменить значение по индексу i
        vector[i] = -1;
    }

    // Метод shrink_to_fit изменяет вместимость под количество элементов
    vector.shrink_to_fit();

    // Выводим capacity после вызова метода shrink_to_fit
    std::cout << "capacity: " << vector.capacity() << std::endl;

    // Метод clear удаляет все элементы
    vector.clear();

    // Метод emplace_back делает тоже самое что и push_back,
    // Только в отличии от push_back, который добавляет копию объекта
    // emplace_back создает объект непосредственно в конце вектора, без лишнего копирования 

    vector.emplace_back(1);

    /// После удаления элементов, при попытке получить элемент получим исключение
    // std :: cout << vector[0] << std :: endl;
}