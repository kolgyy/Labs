#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

template <typename T>

class Stack {
public:
	Stack(size_t size){
		if (size == 0) {
			throw std::bad_alloc();
		}
		current_index = -1;
		_size_ = size;
		arr = new T[size];
	}
	~Stack() {
		delete[] arr;
	}
	size_t size() {
		return _size_;
	}
	bool empty() {
		return (current_index == -1);
	}
	void push(const T& element) {
		if (++current_index == _size_) {
			throw std::overflow_error("Stack is full");
		}
		arr[current_index] = element;
	}
	T pop() {
		if (empty()) {
			throw std::out_of_range("Out of range");
		}
		return arr[current_index--];
	}
	T& top() {
		if (empty()) {
			throw std::logic_error("Stack is empty");
		}
		return arr[current_index];
	}
private:
	T* arr;
	size_t _size_;
	int current_index;

};



int main() {
	try{

	Stack<int> stack(3);
	//Stack<string> stack_2(0);

	stack.push(1);
	stack.push(5);
	stack.push(7);
	//stack.push(8);

	cout << stack.top() << endl;

	stack.pop();

	cout << stack.top() << endl;

	stack.pop();
	stack.pop();
	//stack.pop();

	cout << stack.top() << endl;
	}

	catch (const std::exception& ex) {
		cout << ex.what() << endl;
	}
	catch (...) {
		cout << "Something went wrong" << endl;
	}
	


	return 0;
}