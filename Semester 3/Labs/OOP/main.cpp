#include <iostream>
#include <cmath>
#include <functional>

using std::cout;
using std::endl;
using std::function;

class ICalcer { // Абстрактный класс
public:
    virtual double calculate_int() = 0;
};

class TrapeziumCalcer : public ICalcer {
private:
    function<double(double)> func; // Подынтегральная функция
    double a, b; // Нижний и верхний пределы интегрирования
    int num; // Количество точек

public:
    // Конструктор класса, принимающий подынтегральную функцию, пределы интегрирования и количество точек.
    TrapeziumCalcer(function<double(double)> func, double a, double b, int num) {
        this->func = func;
        this->a = a;
        this->b = b;
        this->num = num;
    }

    // Метод для вычисления интеграла методом трапеции
    double calculate_int() override {
        double h = (b - a) / num;
        double sum = 0.5 * (func(a) + func(b));

        for (int i = 1; i < num; i++) {
            double x = a + i * h;
            sum += func(x);
        }

        return h * sum;
    }
};
class SimpsonCalcer : public ICalcer { // Наследуем класс ICalcer
private:
    function<double(double)> func;
    double a, b;
    int num;

public:
    SimpsonCalcer(std::function<double(double)> func, double a, double b, int num) {
        this->func = func;
        this->a = a;
        this->b = b;
        this->num = num;
    }

    // Метод Симпсона для вычисления интеграла
    double calculate_int() override {
        double h = (b - a) / num;
        double sum = func(a) + func(b);

        for (int i = 1; i < num; i++) {
            double x = a + i * h;
            if (i % 2 == 0) {
                sum += 2 * func(x);
            }
            else {
                sum += 4 * func(x);
            }
        }

        return (h / 3) * sum;
    }
};
int main() {
    double a = 5.0; // Нижний предел
    double b = 10.0; // Верхний предел
    int num = 1000; // Кол-во точек
    function<double(double)> func = [](double x) {return pow(x, 5);}; // Интеграл

    TrapeziumCalcer trapezium(func, a, b, num); // Помещаем интеграл в методы
    double trapz = trapezium.calculate_int();

    SimpsonCalcer simpson(func, a, b, num);
    double simps = simpson.calculate_int();

    double exact_integral = pow(10, 6) / 6 - pow(5, 6) / 6; // Ф-ла Нюютона-Лейбница
    cout << "Exact value: " << exact_integral << endl;
    cout << "Trapezium: " << trapz << endl;
    cout << "Simpson: " << simps << endl;
    return 0;
}