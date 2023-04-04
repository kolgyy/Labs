#include <iostream>

using std::cout;
using std::endl;
using std::cin;

class Complex {
private:
	double* real_number;
	double* imaginary_unit;
public:
	Complex() { // Basic constructor 
		real_number = imaginary_unit = nullptr;
	}
	Complex(double real_number, double imaginary_init) { // Constructor
		this->real_number = new double(real_number);
		this->imaginary_unit = new double(imaginary_init);
	}
	Complex(const Complex& other) { // Copy constructor
		this->real_number = new double(*other.real_number);
		this->imaginary_unit = new double(*other.imaginary_unit);


	}
	~Complex() {
		delete this->real_number;
		delete this->imaginary_unit;

	}
	Complex& operator= (const Complex& other) {
		if (this->real_number != nullptr)
			delete real_number;
		if (this->imaginary_unit != nullptr)
			delete imaginary_unit;
		this->real_number = new double(*other.real_number);
		this->imaginary_unit = new double(*other.imaginary_unit);
		return *this;

	}

	Complex operator+ (const Complex& other) {
		Complex number;
		double sum_real = *this->real_number + *other.real_number;
		double sum_imaginary = *this->imaginary_unit + *other.imaginary_unit;
		number.real_number = new double(sum_real);
		number.imaginary_unit = new double(sum_imaginary);

		return number;

	}
	Complex operator+= (const Complex& other) {
		Complex number;
		double sum_real = *this->real_number + *other.real_number;
		double sum_imaginary = *this->imaginary_unit + *other.imaginary_unit;
		number.real_number = new double(sum_real);
		number.imaginary_unit = new double(sum_imaginary);

		return number;

	}

	Complex operator* (const Complex& other) {
		Complex number; // (a1 * b1_i) * (a2 * b2_i) = (a1*a2 - b1*b2) + (a1*b2 + a2*b1)_i
		double multiply_real = ((*this->real_number) * (*other.real_number)) - ((*this->imaginary_unit) * (*other.imaginary_unit));
		double multiply_imaginary = ((*this->real_number) * (*other.imaginary_unit)) + ((*other.real_number) * (*this->imaginary_unit));

		number.real_number = new double(multiply_real);
		number.imaginary_unit = new double(multiply_imaginary);
		return number;
	}

	Complex operator*= (const Complex& other) {
		Complex number; // (a1 * b1_i) * (a2 * b2_i) = (a1*a2 - b1*b2) + (a1*b2 + a2*b1)_i
		double multiply_real = ((*this->real_number) * (*other.real_number)) - ((*this->imaginary_unit) * (*other.imaginary_unit));
		double multiply_imaginary = ((*this->real_number) * (*other.imaginary_unit)) + ((*other.real_number) * (*this->imaginary_unit));

		return number;
	}
	Complex& operator++() {  // Prefix increment
		*this->real_number += 1;
		return *this;
	}
	Complex& operator++(int) { // Postfix increment

		Complex temp(*this);

		++(*this->real_number);

		return temp;

	}

	friend std::ostream& operator <<(std::ostream& os, const Complex& number);
	friend std::istream& operator >>(std::istream& is,  Complex& number);
};

std::ostream& operator <<(std::ostream& os, const Complex& number) {
	os << *number.real_number;
	if (*number.imaginary_unit >= 0) {
		os << '+';
	}
	os << (*number.imaginary_unit) << 'i';
	return os;
}
std::istream& operator >>(std::istream& is, Complex& number) {
	double temp_1, temp_2;
	is >> temp_1;
	is >> temp_2;
	number.real_number = new double(temp_1);
	number.imaginary_unit = new double(temp_2);

	return is;
}

int main() {
	Complex number_1;
	Complex number_2;
	cout << "Enter a complex number" << endl;
	cin >> number_1;
	cout << endl << "The 1st_number: " << number_1 << endl;
	cout << "Enter a complex number" << endl;
	cin >> number_2;
	cout << endl << "The 2nd_number: " << number_2 << endl;

	cout << "The sum of numbers: " << (number_1 + number_2) << endl;
	cout << "The multiply of numbers: " << (number_1 * number_2) << endl;
	cout << "The 1s_number + 1: " << ++number_1 << endl;
	number_1 = number_2;
	cout << number_1 << endl;



	return 0;
}