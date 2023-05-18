#include <iostream>

using std::cout;
using std::cin;
using std::endl;

template <typename T, unsigned int N, unsigned int M>

class Matrix {
public:
	Matrix(){}
	Matrix(const Matrix& other) { // Copy constructor
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				data[i][j] = other.data[i][j];
			}
		}

	}
	Matrix& operator= (const Matrix& other) { // Operator = 
		if (this != &other) { // Two arrays
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					data[i][j] = other.data[i][j];
				}
			}
		}
		return *this;
	} 
	friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) { // Output
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				os << matrix.data[i][j] << " ";
			}
			os << endl;
		}
		return os;
	}
	friend std::istream& operator>>(std::istream& is, Matrix& matrix) { // Input
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				is >> matrix.data[i][j];
			}
		}
		return is;
	}
	Matrix operator+(const Matrix& other) {
		Matrix result;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				result.data[i][j] = data[i][j] + other.data[i][j];
			}
		}
		return result;
	}
	Matrix& operator+=(const Matrix& other) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				data[i][j] += other.data[i][j];
			}
		}
		return *this;
	}
	Matrix operator*(const Matrix& other) {
		Matrix result;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				result.data[i][j] = 0;
				for (int k = 0; k < M; ++k) {
					result.data[i][j] += data[i][k] * other.data[k][j];
				}
			}
		}
		return result;
	}
	Matrix& operator*=(const Matrix& other) {
		*this = *this * other;
		return *this;
	}
	Matrix& operator++() {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				++data[i][j];
			}
		}
		return *this;
	}
	T determinant() {
		static_assert(N == M, "Matrix must be square");
		if (N == 1) {
			return data[0][0];
		}
		else if (N == 2) {
			return data[0][0] * data[1][1] - data[0][1] * data[1][0];
		}
		else if (N == 3) {
			return data[0][0] * data[1][1] * data[2][2]
				+ data[0][1] * data[1][2] * data[2][0]
				+ data[0][2] * data[1][0] * data[2][1]
				- data[0][2] * data[1][1] * data[2][0]
				- data[0][1] * data[1][0] * data[2][2]
				- data[0][0] * data[1][2] * data[2][1];
		}
	}

	T& operator()(int i, int j) {
		return data[i][j];
	}

private:
	T data[N][M];
};







int main() {
	Matrix <int, 3, 2> A;
	cin >> A;
	cout << A;
	Matrix <int, 3, 2> B;
	cin >> B;
	cout << B;
	Matrix<int, 3, 2> C = A + B;
	cout << "A + B : " << endl;
	cout << C;
	cout << "A += B :" << endl;
	A += B;
	cout << A;
	
	Matrix<int, 2, 2> D;
	cin >> D;
	cout << D;
	cout << "Determinant D : " << D.determinant() << endl;

	Matrix<int, 2, 2> E;
	cout << "D * D : " << endl;
	E = D * D;
	cout << E;
	cout << "E ++ : " << endl;
	cout << ++E << endl;

	return 0;
}