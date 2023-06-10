#include <iostream>
#include <string>

#define PI 3.14;


using std::cout;
using std::cin;
using std::endl;
using std::string;

class Shape {
public:
	Shape(string color) : color(color) {}
	virtual double Square() = 0; // A pure virtual function

	virtual ~Shape() {
		cout << "Shape's destructor was called!" << endl;
	}

	void Print() {
		cout << "Color : " << color << endl;
		cout << "Square : " << Square() << endl;
	}
	
	string color;
	


	
};

class Triangle : public Shape {
public:
	Triangle(double base, double height, string color) : _base_(base), _height_(height), Shape(color){}
	double Square() override {
		return (_height_ * _base_) / 2;
	}
	~Triangle() override {
		cout << "Triangle's destructor was called!" << endl;
	}
	
private:
	double _base_;
	double _height_;

};
class Rectangle : public Shape {
public:
	Rectangle(double base, double height, string color) : _base_(base), _height_(height), Shape(color) {}
	double Square() override {
		return (_height_ * _base_);
	}
	~Rectangle() override {
		cout << "Rectangle's destructor was called!" << endl;
	}

private:
	double _base_;
	double _height_;
};

class Circle : public Shape {
public:
	Circle(double radius, string color) : _radius_(radius), Shape(color) {}
	double Square() override {
		return _radius_ * _radius_ * PI;
	}
	~Circle() override {
		cout << "Circle's destructor was called!" << endl;
	}

private:
	double _radius_;
};








int main() {
	Shape* shapes[3];

	shapes[0] = new Triangle(2, 4, "black");
	shapes[1] = new Circle(3.4, "white");
	shapes[2] = new Rectangle(4, 2, "yellow");

	for (int i = 0; i < 3; i++) {
		shapes[i]->Print();
		delete shapes[i];
	}

	return 0;
}