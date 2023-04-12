#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

class FibonacciCipher {
public:
    FibonacciCipher() {}

    void SetKey(const std::vector<int>& key) {
        key_ = key;
    }

    std::vector<int> GetKey() const {
        return key_;
    }

    std::string Encode(const std::string& message) const {
        std::vector<std::string> words = SplitMessageIntoWords(message);
        std::vector<int> word_numbers = ConvertWordsToNumbers(words);
        std::vector<int> encoded_word_numbers = EncodeNumbers(word_numbers);
        std::vector<std::string> encoded_words = ConvertNumbersToWords(encoded_word_numbers);
        return JoinWordsIntoMessage(encoded_words);
    }

    std::string Decode(const std::string& message) const {
        std::vector<std::string> words = SplitMessageIntoWords(message);
        std::vector<int> word_numbers = ConvertWordsToNumbers(words);
        std::vector<int> decoded_word_numbers = DecodeNumbers(word_numbers);
        std::vector<std::string> decoded_words = ConvertNumbersToWords(decoded_word_numbers);
        return JoinWordsIntoMessage(decoded_words);
    }

private:
    std::vector<int> key_;

    std::vector<std::string> SplitMessageIntoWords(const std::string& message) const {
        std::vector<std::string> words;
        std::stringstream ss(message);
        std::string word;
        while (ss >> word) {
            words.push_back(word);
        }
        return words;
    }

    std::vector<int> ConvertWordsToNumbers(const std::vector<std::string>& words) const {
        std::vector<int> numbers;
        for (const auto& word : words) {
            int number = 0;
            for (const auto& c : word) {
                number = number * 256 + c;
            }
            numbers.push_back(number);
        }
        return numbers;
    }

    std::vector<std::string> ConvertNumbersToWords(const std::vector<int>& numbers) const {
        std::vector<std::string> words;
        for (const auto& number : numbers) {
            std::string word;
            int temp_number = number;
            while (temp_number > 0) {
                word.push_back(temp_number % 256);
                temp_number /= 256;
            }
            std::reverse(word.begin(), word.end());
            words.push_back(word);
        }
        return words;
    }

    std::vector<int> EncodeNumbers(const std::vector<int>& numbers) const {
        std::vector<int> encoded_numbers;
        for (const auto& index : key_) {
            if (index - 1 < numbers.size()) {
                encoded_numbers.push_back(numbers[index - 1]);
            }
        }
        return encoded_numbers;
    }

    std::vector<int> DecodeNumbers(const std::vector<int>& numbers) const {
        std::vector<int> decoded_numbers(numbers.size(), 0);
        int i = 0;
        for (const auto& index : key_) {
            if (i < numbers.size()) {
                decoded_numbers[index - 1] = numbers[i];
            }
            i++;
        }
        return decoded_numbers;
    }

    std::string JoinWordsIntoMessage(const std::vector<std::string>& words) const {
        std::string message;
        for (const auto& word : words) {
            message += word;
            message.push_back(' ');
        }
        if (!message.empty()) {
            message.pop_back();
        }
        return message;
    }
};

int main() {
    FibonacciCipher cipher;
    std::vector<int> key = { 2, 8, 5, 1, 3 };
    cipher.SetKey(key);

    std::string message = "Hello, my name is Ivan.";
    std::string encoded_message = cipher.Encode(message);
    std::string decoded_message = cipher.Decode(encoded_message);

    std::cout << "Original message: " << message << std::endl;
    std::cout << "Encoded message: " << encoded_message << std::endl;
    std::cout << "Decoded message: " << decoded_message << std::endl;

    return 0;
}
