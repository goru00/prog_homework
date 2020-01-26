#include<iostream>
using namespace std;
class Matrix
{
private:
	double **Matr;
	int n;
	int m;
public:
    Matrix(int m_n, int m_m) : n(m_n), m(m_m) { Create(); }
	~Matrix() { }
	void Delete()
	{
		for (int i = 0; i < m; i++)
		{
			delete[] Matr[i];
		}
		delete[] Matr;
	}
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
		Matrix temp(*this);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				temp.Matr[i][j] = Matr[i][j] * value;
			}
		}
		return *this;
	}
	Matrix pr(const Matrix &b)
	{
		Matrix temp(*this);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				temp.Matr[i][j] = Matr[i][j] * b.Matr[i][j];
			}
		}
		return *this;
	}
	Matrix sum(const Matrix &b)
	{
		Matrix temp(*this);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				temp.Matr[i][j] = Matr[i][j] + b.Matr[i][j];
			}
		}
		return *this;
	}
	Matrix substract(const Matrix &b)
	{
		Matrix temp(*this);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				temp.Matr[i][j] = Matr[i][j] - b.Matr[i][j];
			}
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, const Matrix& matr);
	friend bool operator==(const Matrix& matr1, const Matrix& matr2);
	friend bool operator!=(const Matrix& matr1, const Matrix& matr2);
};
bool operator==(const Matrix& matr1, const Matrix& matr2) {	return (matr1.n == matr2.n && matr1.m == matr2.m);}
bool operator!=(const Matrix& matr1, const Matrix& matr2) { return (matr1.n != matr2.m); }
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
	Matrix matr1(5, 4);
	Matrix matr2(5, 5);
	//matr1.display();
	cout << "Первая матрица:\n" << matr1 << endl << "Вторая матрица:\n" << matr2 << endl;
	if (matr1 == matr2) cout << "Сложение матриц:\n" << matr1.sum(matr2) << endl << "Вычитание матриц:\n" << matr1.substract(matr2) << endl;
	else cout << "Матрицы имеют не равные размерности!\n";
	/*if (!(matr1 != matr2)) cout << "Умножение матриц:\n" << matr1.pr(matr2);
	else cout << "Матрицы имеют не равные размерности!\n";*/
	cout << "Умножение матрицы 1 на число:\n" << matr1.prfornum(5) << endl;
	return 0;
}
