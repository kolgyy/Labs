#include <iostream>
#include <fstream>
#include <unordered_map>

int main() {
    std::ifstream file("configuration/input.txt"); // �������� ����� ��� ������

    if (!file) {
        std::cerr << "������ �������� �����!" << std::endl;
        return 1;
    }

    std::unordered_map<std::string, int> hashtable;
    std::string word;
    while (file >> word) { // ������ �����
        // ������� ����� � ���-������� ��� ����������������� ��� ��������
        hashtable[word]++;
    }

    file.close(); // �������� �����

    std::ofstream output("output.txt"); // �������� ����� ��� ������

    if (!output) {
        std::cerr << "������ �������� �����!" << std::endl;
        return 1;
    }

    for (const auto& pair : hashtable) {
        output << pair.first << " " << pair.second << std::endl; // ������ ����� � ��� �������� � ����
    }

    output.close(); // �������� �����

    return 0;
}
