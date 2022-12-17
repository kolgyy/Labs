#include <iostream>
#include <string>
using namespace std;

int main() {
    string A;
    string B;
    int value;
    int sum, r = 0; // r - остаток от сложения по разрядам.
    cout << "Enter A: " << endl;
    cin >> A;
    cout << endl;
    cout << "Enter B: " << endl;
    cin >> B;
    cout << endl;
    cout << "If you want to plus them, press '1'" << endl;
    cout << "If you want to multiple them, press '2'" << endl;
    cin >> value;
    cout << endl;

    if (value == 1) {


    while (A.length() != B.length()) { // Мы делаем так, чтобы у нас получились равные по длине цифры, ведь для того, чтобы их сложить, нужно чтобы они были равные.
        if (A.length() < B.length()) {
            A = "0" + A;
        }
        else {
            B = "0" + B;
        }
    }

    A = "0" + A; // Мы прибавляем в начале нули, так как разряд может увеличиться.
    B = "0" + B;
    string c;
    for (int i = A.length()-1; i > -1; i --) { // Запускаем цикл с последней цифры.
        sum = A[i] - '0' + B[i] - '0' + r; // Складываем цифры и число десятков с прошлого разряда. Делаем перевод в строчку.
        r = sum / 10; // Находим число десятков суммы текущих цифр.
        c = char (sum % 10 + '0') + c; // В текущий разряд суммы чисел ставим количество единиц текущей суммы.
    }
    if (c[0] == '0') { // Проверяем, есть ли незначащий ноль.
        c.erase(0,1); // Если есть, то удаляем
    }
    cout << c << endl;

    }








}
