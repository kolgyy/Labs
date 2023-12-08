#include <iostream>
#include <fstream>
#include <unordered_map>

int main() {
    std::ifstream file("configuration/input.txt"); // открытие файла для чтения

    if (!file) {
        std::cerr << "Ошибка открытия файла!" << std::endl;
        return 1;
    }

    std::unordered_map<std::string, int> hashtable;
    std::string word;
    while (file >> word) { // чтение слова
        // Вставка слова в хеш-таблицу или инкрементирование его значения
        hashtable[word]++;
    }

    file.close(); // закрытие файла

    std::ofstream output("output.txt"); // открытие файла для записи

    if (!output) {
        std::cerr << "Ошибка открытия файла!" << std::endl;
        return 1;
    }

    for (const auto& pair : hashtable) {
        output << pair.first << " " << pair.second << std::endl; // запись слова и его значения в файл
    }

    output.close(); // закрытие файла

    return 0;
}
