#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
class Matrix
{
private:
	double** matrix;
	int n, m;
public:
	Matrix()
	{
		matrix = 0;
		n = 0;
		m = 0;
	}
	Matrix(int _n, int _m) : n(_n), m(_m) 
	{
		matrix = new double* [n];
		for (int i = 0; i < n; i++) {
			matrix[i] = new double[m];
			for (int j = 0; j < m; j++) {
				matrix[i][j] = (rand() % 100 + 1) + (rand() % 100 + 1) * 0.1;
			}
		}
	}
	~Matrix() { }
	int get_n() { return n; }
	int get_m() { return m; }
	bool error(int, int);
	Matrix multiplies_value(int);
	Matrix degree(int);
	double* operator[] (int);
	Matrix operator+(const Matrix&);
	Matrix operator-(const Matrix&);
	Matrix operator*(const Matrix&);
	Matrix operator=(const Matrix&);
	friend ostream& operator<<(ostream&, const Matrix&);
};
bool Matrix::error(int matr_n, int matr_m)
{
	if (matr_n == n && matr_m == m) return true;
	return false;
}
Matrix Matrix::multiplies_value(int value)
{
	Matrix temp(n, m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			temp.matrix[i][j] = matrix[i][j] * value;
		}
	}
	return temp;
}
Matrix Matrix::degree(int value)
{
	Matrix temp = Matrix(n, m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < value; k++) {
				temp.matrix[i][j] += matrix[i][k] * matrix[k][j];
			}
		}
	}
	return temp;
}
double* Matrix::operator[] (int i)
{
	return matrix[i];
}
Matrix Matrix::operator+(const Matrix& matr)
{
	if (error(matr.n, matr.m)) {
		Matrix temp(matr.n, matr.m);
		for (int i = 0; i < matr.n; i++) {
			for (int j = 0; j < matr.m; j++) {
				temp.matrix[i][j] = matrix[i][j] + matr.matrix[i][j];
			}
		}
		return temp;
	}
	else cout << "Невозможно!\n";
}
Matrix Matrix::operator-(const Matrix& matr)
{
	if (error(matr.n, matr.m)) {
		Matrix temp(matr.n, matr.m);
		for (int i = 0; i < matr.n; i++) {
			for (int j = 0; j < matr.m; j++) {
				temp.matrix[i][j] = matrix[i][j] - matr.matrix[i][j];
			}
		}
		return temp;
	} else cout << "Невозможно!\n";
}
Matrix Matrix::operator*(const Matrix& matr)
{
	if (m == matr.n) {
		Matrix temp = Matrix(n, matr.m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < matr.m; j++) {
				for (int k = 0; k < m; k++) {
					temp.matrix[i][j] += matrix[i][j] * matr.matrix[i][j];
				}
			}
		}
		return temp;
	} else cout << "Невозможно!\n";
}
Matrix Matrix::operator=(const Matrix& matr)
{
	Matrix temp(matr.n, matr.m);
	for (int i = 0; i < matr.n; i++) {
		for (int j = 0; j < matr.m; j++) {
			temp.matrix[i][j] = matr.matrix[i][j];
		}
	}
	return temp;
}
ostream& operator<<(ostream& out, const Matrix& matr)
{
	out << endl;
	for (int i = 0; i < matr.n; i++) {
		for (int j = 0; j < matr.m; j++) {
			cout.width(10); 
			out << matr.matrix[i][j];
		}
		out << endl;
	}
	return out;
}
int main()
{
	setlocale(0, "");
	srand(time(NULL));
	Matrix matr1(4, 5), matr2(5, 5), sum, substract, multiplies;
	cout << "Первая матрица: " << matr1 << "\nВторая матрица: \n" << matr2 << endl;
	cout << "Сумма матриц: " << (sum = matr1 + matr2) << endl; 
	cout << "Разность матриц: " << (substract = matr1 - matr2) << endl;
	cout << "Умножаем матрицу 1 на число " << 5 << " : " << matr1.multiplies_value(5) << endl;
	cout << "Перемножаем матрицы друг на друга: " << (multiplies = matr1 * matr2) << endl;
	cout << "Возведение матрицы в степень 4" << ": " << matr1.degree(5) << endl;
	return 0;
}