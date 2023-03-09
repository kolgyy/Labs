/*
������ ������� �������� 3. ������� 4.
� ��������� ����� input.txt ������� ������� �����.
����� � ������ �����, ���������� ��� ���������� ����� ������, �������� �� ���������� ������� � ������� ����� ������� ������ ����� � ������� ��������� �����.
���������� ����� �������� � ���� output.txt.
���� �����, ����� ��������� ����, ������ �������� ����������, ������� � ����� ����������.
*/

#include <iostream>
#include <fstream>
#include <vector>

// �������, ������� ��������� �������� �� ������ ������ � ������� ��������
bool isUpper(char c) {
	return c >= '�' && c <= '�';
}

// �������, ������� ��������� �������� �� ������ ������ � ������ ��������
bool isLower(char c) {
	return c >= '�' && c <= '�';
}

// �������, ������� ��������� ����� � ������� �������
char toUpper(char c) {
	if (isLower(c)) {
		return c - 32;
	}
	return c;
}

// �������, ������� ��������� ����� � ������ �������
char toLower(char c) {
	if (isUpper(c)) {
		return c + 32;
	}
	return c;
}

// �������, ������� ��������� �������� �� ������ ������
bool isLetter(char c) {
	return isUpper(c) || isLower(c);
}

// �������, ������� ���������� �����
void write(std::vector<char>& word, std::vector<char>& foundLetters, std::ofstream& outputFileStream) {
	if (word.size() > 0) {
		// ���������� �����
		for (size_t i = 0; i < word.size() - 1; i++) {
			char left = toLower(word[i]);
			char right = toLower(word[i + 1]);

			if (left == right) {
				word[i] = toUpper(left);
				word[i + 1] = toUpper(right);

				if (std::find(
					foundLetters.begin(),
					foundLetters.end(),
					left) == foundLetters.end()) {
					foundLetters.push_back(left);
				}
			}
		}

		for (size_t i = 0; i < word.size(); i++) {
			std::cout << word[i];
			outputFileStream << word[i];
		}
		word.clear();

		// ���������� � ������� ����� ����� ��� ��������� �����
		if (foundLetters.size() > 0) {
			std::cout << '(';
			outputFileStream << '(';

			for (size_t i = 0; i < foundLetters.size(); i++) {
				std::cout << foundLetters[i];
				outputFileStream << foundLetters[i];
			}

			std::cout << ')';
			outputFileStream << ')';

			foundLetters.clear();
		}
	}
}

int main() {
	setlocale(LC_ALL, "Russian");

	// ������� ����
	std::ifstream inputFileStream("input.txt");

	if (!inputFileStream.good()) {
		std::cout << "input.txt �� ������� �������";
		std::cin.get();
		return -1;
	}

	// �������� ����
	std::ofstream outputFileStream("output.txt", std::ios::trunc);

	// ��������� ������
	char c;

	// �����, ������� �����������
	std::vector<char> word;

	// ��������� ������ ������ ����� � �����
	std::vector<char> foundLetters;

	while (!inputFileStream.eof()) {
		inputFileStream.get(c);

		if (isLetter(c)) {
			word.push_back(c);
		}
		else {
			// ���������� ����� � ��������� �����
			write(word, foundLetters, outputFileStream);

			// ���������� ������
			std::cout << c;
			outputFileStream << c;
		}

		inputFileStream.peek();
	}

	// ���������� ��������� ����� � ��������� �����
	write(word, foundLetters, outputFileStream);
}