#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

template <typename T>
class List {
public:
	List();
	~List();

	void pop_front();
	void pop_back();
	void clear();
	void insert(T value, int index);
	void removeAt(int index);
	void push_front(T data);
	void push_back(T data);
	int GetSize() { return Size; }

	T& operator[] (const int index);
private:


	template <typename T>
	class Node { // Node - узел.
	public:
		Node* pNext; // Pointer to the next node.
		T data;
		Node(T data = T(), Node *pNext = nullptr) { // Default parameters.
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size; // Length of the list.
	Node<T> *head; // The beginning of the list. It's a pointer 'cause we work with a dynamic memory.
};


template <typename T>
List<T>::List() {
	Size = 0;
	head = nullptr; // The list is empty when it's created.

}

template <typename T>
List<T>::~List() {
	clear();

}

template<typename T>
void List<T>::pop_front()
{
	Node<T> *temp = head; // Equating pointers
	head = head->pNext;
	delete temp;

	Size--;
}

template<typename T>
void List<T>::pop_back()
{
	removeAt(Size - 1);
}

template<typename T>
void List<T>::clear()
{
	while (Size) { // Iterated 'till size isn't zero.
		pop_front();

	}
}

template<typename T>
void List<T>::insert(T value, int index)
{
	if (index == 0) {
		push_front(value);
	}
	Node<T>* previous = this->head;
	for (int i = 0; i < index - 1; ++i) {
		previous = previous->pNext;
	}

	Node<T>* newNode = new Node<T>(value, previous->pNext);
	previous->pNext = newNode;

	Size++;
}

template<typename T>
void List<T>::removeAt(int index)
{
	if (index == 0) {
		pop_front();
	}
	else 
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; ++i) {
			previous = previous->pNext;
		}

		Node<T>* toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		delete toDelete;
		Size--;

	}
}

template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	Size++;

}


template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr) {

		head = new Node<T>(data);

	}
	else {
		Node<T>* current = this->head;
		while (current->pNext != nullptr) { // Seaching for the last node;

			current = current->pNext; // Setting a position of iteration
		}
		current->pNext = new Node<T>(data);

	}
	Size++;
}

template<typename T>
T& List<T>::operator[](const int index) // Operator []
{
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr) {
		if (counter == index) {
			return current->data;
		}
		current = current->pNext;
		counter++;
	}

	
}

int main() {
	List<int> lst;

	lst.push_back(55);
	lst.push_back(11);
	lst.push_back(2);

	cout << endl << "A number of elements in the list : " << lst.GetSize() << endl << "Executing removeAt method " << endl << endl;
	lst.removeAt(1);

	for (int i = 0; i < lst.GetSize(); ++i) {
		cout << lst[i] << endl;
	}

	cout << endl << "A number of elements in the list : " << lst.GetSize() << endl;

	return 0;
}