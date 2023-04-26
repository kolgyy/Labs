#include <iostream>
#include <vector>
#include <string>
#include <sstream> // We need this to split up a string into parts
#include <algorithm>
#include <unordered_map>


using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::endl;
using std::stringstream;
using std::sort;
using std::unordered_map;



bool is_fibonacci_sequence(const string& key_string) {
	vector<int> numbers;
	stringstream ss(key_string);
	int temp;
	while (ss >> temp)
		numbers.push_back(temp);
	sort(numbers.begin(), numbers.end());
	for (int i = 2; i < numbers.size(); i++) {
		if (numbers[i] != (numbers[i - 1] + numbers[i - 2]))
			return false;
	}
	return true;
}


class Fibonacci_Cipher {
public:
	Fibonacci_Cipher() {

	}
	void set_key(const string& key_string) {

		if (split_message(key_string).size() > 30 || split_message(key_string).size() < 3)
			throw std::invalid_argument("The key size was exceeded!");

		else if (is_fibonacci_sequence(key_string)) {
			stringstream ss(key_string);
			int fib_num = 0;
			while (ss >> fib_num)
				key.push_back(fib_num);
		}
		else {
			throw std::invalid_argument("The key is incorrect!");
		}
	}
	vector<int> get_key() {
		return key;
	}
	void print_key() {
		for (int i = 0; i < key.size(); i++)
			cout << key[i] << " ";
	}
	string encode(const string& message) {
		vector<string> encoded_words = split_message(message);
		if (encoded_words.size() > 30 || encoded_words.size() < 3 || encoded_words.size() != key.size())
			throw std::invalid_argument("The message size was exceeded!");
		vector<int> original_key = key;
		sort(key.begin(), key.end());
		unordered_map<int, string> map;
		for (int i = 0; i < key.size(); i++) 
			map[key[i]] = encoded_words[i];
		this->map = map;
		string cipher;
		for (int i = 0; i < key.size(); i++) {
			cipher += map[original_key[i]];
				if (i < key.size() - 1)
					cipher += " ";
		}

		return cipher;
	}
	string decode(const string& key) {
		vector<int> sorted_key;
		stringstream ss(key);
		int temp;
		while (ss >> temp)
			sorted_key.push_back(temp);
		if (sorted_key.size() > 30 || sorted_key.size() < 3)
			throw std::invalid_argument("The key size was exceeded!");
		string decoded_message;
		for (int i = 0; i < sorted_key.size(); i++){
			decoded_message += map[sorted_key[i]];
			if (i < sorted_key.size() - 1)
				decoded_message += " ";
		}
		
		return decoded_message;
	}






private:
	vector<int> key;
	unordered_map <int, string> map;

	vector<string> split_message(const string& message) {
		vector<string> words;
		stringstream ss(message); // Split the message up into words
		string word;
		while (ss >> word)
			words.push_back(word);
		return words;
	}
};

int main()
{

	Fibonacci_Cipher message;
	message.set_key("2 8 5 1 3");
	// message.set_key("2 8 5 1 3 5");  // It's gonna be an ERROR!
	message.print_key();
	cout << endl;
	string expression = "Hello, my name is Ivan.";
	// string expression = "Hello, my name is Ivan Ivanovich."; It's gonna be an ERROR!
	cout << message.encode(expression) << endl;
	cout << message.decode("1 2 3 5 8");

	return 0;
}