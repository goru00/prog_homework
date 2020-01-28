#include<iostream>
using namespace std;
class Matrix
{
private:
	double** Matr;
	int n;
	int m;
public:
	Matrix() { Matr = 0; n = 0; m = 0; } // краткое пояснение. при создании матрицы без каких-либо значений, конструктор по умолчанию заполняет 0
	Matrix(int m_n, int m_m) : n(m_n), m(m_m) { Create(); }
	~Matrix() { }
	void Create()
	{
		Matr = new double* [n];
		for (int i = 0; i < n; i++) {
			Matr[i] = new double[m];
			for (int j = 0; j < m; j++) {
				Matr[i][j] = (i + j) * 0.1;
			}
		}
	}
	Matrix prfornum(int value)
	{
		Matrix temp = Matrix(n, m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				temp[i][j] = Matr[i][j] * value;
			}
		}
		return temp;
	}
	Matrix pr(const Matrix& b)
	{
		Matrix temp = Matrix(n, b.m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < b.m; j++) {
				for (int k = 0; k < m; k++)
					temp[i][j] += Matr[i][k] * b.Matr[k][j];
			}
		}
		return temp;
	}
	Matrix sum(const Matrix& b)
	{
		Matrix temp = Matrix(n, b.m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < b.m; j++) {
				temp[i][j] = Matr[i][j] + b.Matr[i][j];
			}
		}
		return temp;
	}
	Matrix substract(const Matrix& b)
	{
		Matrix temp = Matrix(n, b.m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < b.m; j++) {
				temp[i][j] = Matr[i][j] - b.Matr[i][j];
			}
		}
		return temp;
	}/*
	Matrix degree(int value)
	{
		double Q;
		Matrix temp = Matrix(n, m);
		for (int g = 0; g < value; g++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					for (int k = 0; k < m; k++)
						Q += temp[i][k] * temp[k][j];
					temp[i][j] += Q;
				}
			}
			
		}
		return temp;
	}*/
	double* operator [] (int index)
	{
		return getRow(index);
	}
	double* getRow(int index)
	{
		if (index >= 0 && index < n)
			return Matr[index];
		return 0;
	}
	friend ostream& operator<<(ostream& out, const Matrix& matr);
	friend bool operator==(const Matrix& matr1, const Matrix& matr2);
};
bool operator==(const Matrix& matr1, const Matrix& matr2)
{
	if (matr1.n != matr2.n || matr1.m != matr2.m)
		return false;
}
ostream& operator<<(ostream& out, const Matrix& matr)
{
	for (int i = 0; i < matr.n; i++) {
		for (int j = 0; j < matr.m; j++) {
			out << "\t" << matr.Matr[i][j];
		}
		cout << endl; // делаю костыли без смс и регистрации
	}
	return out;
}
int main()
{
	setlocale(0, "");
	Matrix matr1(5, 5);
	Matrix matr2(5, 5);
	cout << "Первая матрица:\n" << matr1 << endl << "Вторая матрица:\n" << matr2 << endl;
	if (matr1 == matr2) {
		cout << "Сложение матриц:\n" << matr1.sum(matr2) << endl;
		cout << "Разность матриц:\n" << matr1.substract(matr2) << endl;
		cout << "Умножение матриц:\n" << matr1.pr(matr2);
	}
	cout << "Умножение матрицы 1 на число:\n" << matr1.prfornum(5) << endl;
	//cout << "Возведение матрицы в степень:\n" << matr1.degree(3) << endl;
	return 0;
}