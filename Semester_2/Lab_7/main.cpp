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

private:
	double _radius_;
};








int main() {
	Triangle triangle(2, 4, "black");
	Circle circle(3.4, "white");
	Rectangle rectangle(4, 2, "yellow");

	triangle.Print();
	circle.Print();
	rectangle.Print();

	return 0;
}