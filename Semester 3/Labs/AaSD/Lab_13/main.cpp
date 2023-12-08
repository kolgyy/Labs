#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int TABLE_SIZE = 10; // Размер хеш-таблицы
const string OUTPUT_FILE = "output.txt"; // Имя результирующего файла

// Хеш-функция для строки
int hashFunction(const string& key) {
    int hash = 0;
    for (char c : key) {
        hash += c;
    }
    return hash % TABLE_SIZE;
}

// Структура для хранения элемента в хеш-таблице
struct HashNode {
    string key;
    HashNode* next;

    HashNode(const string& k) : key(k), next(nullptr) {}
};

// Класс для хеш-таблицы
class HashTable {
private:
    HashNode* table[TABLE_SIZE];

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = nullptr;
        }
    }

    // Метод для добавления элемента в хеш-таблицу
    void insert(const string& key) {
        int index = hashFunction(key);

        HashNode* newNode = new HashNode(key);
        if (table[index] == nullptr) {
            table[index] = newNode;
        }
        else {
            HashNode* curr = table[index];
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = newNode;
        }
    }

    // Метод для вывода хеш-таблицы в файл
    void printToFile(const string& filename) {
        ofstream outputFile(filename);
        if (outputFile.is_open()) {
            for (int i = 0; i < TABLE_SIZE; i++) {
                HashNode* curr = table[i];
                if (curr != nullptr) { // Проверка наличия значений
                    outputFile << i << " ";
                    while (curr != nullptr) {
                        outputFile << curr->key << " ";
                        curr = curr->next;
                    }
                    outputFile << endl;
                }
            }
            outputFile.close();
        }
        else {
            cout << "Ошибка при открытии файла!" << endl;
        }
    }
};

int main() {
    HashTable hashtable;
    ifstream inputFile("configuration/input.txt");
    if (inputFile.is_open()) {
        string name;
        while (inputFile >> name) {
            hashtable.insert(name);
        }
        inputFile.close();
        hashtable.printToFile(OUTPUT_FILE);
    }
    else {
        cout << "Ошибка при открытии файла!" << endl;
    }

    return 0;
}