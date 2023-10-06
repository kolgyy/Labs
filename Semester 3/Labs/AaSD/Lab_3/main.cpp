#include <iostream>
#include <string>
#include <vector>
#include <complex>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;
using std::complex;

vector<complex<int>> findOperands(int x) {
    vector<complex<int>> operands;

    for (int k = 0; k <= x; k++) {
        for (int l = 0; l <= x; l++) {
            for (int m = 0; m <= x; m++) {
                complex<int> operand(pow(3, k) * pow(5, l) * pow(7, m), 0);
                if (abs(operand) == x) {
                    operands.push_back(operand);
                }
            }
        }
    }

    return operands;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int x;
    cout << "¬ведите число x: ";
    cin >> x;

    vector<complex<int>> operands = findOperands(x);

    cout << "„исла, удовлетвор€ющие условию: ";
    for (complex<int> operand : operands) {
        cout << operand << " ";
    }

    return 0;
}
