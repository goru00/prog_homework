#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<conio.h> 
using namespace std;
template <class T>
class Matrix
{
	T **matr;
	int rowCount, colCount;
public:
	Matrix()
	{
		rowCount = colCount = 0;
		matr = nullptr;
	}
	Matrix(int r, int c)
	{
		rowCount = r;
		colCount = c;
		AllocateMemory();
	}
	void AllocateMemory()
	{
		matr = new T*[rowCount];
		for (int i = 0; i < rowCount; i++)
		{
			matr[i] = new T[colCount];
		}
	}
	void FillRandom(int min, int max)
	{
		for (int i = 0; i < rowCount; i++)
		{
			for (int j = 0; j < colCount; j++)
			{
				matr[i][j] = rand() % (max - min + 1) + min;
			}
		}
	}
	void SetElement(int i, int j, T data)
	{
		matr[i][j] = data;
	}
	void Print()
	{
		for (int i = 0; i < rowCount; i++)
		{
			for (int j = 0; j < colCount; j++)
			{
				cout << matr[i][j] << "\t";
			}
			cout << endl;
		}
	}
Matrix<T> operator + (Matrix<T> m2)
	{
		Matrix<T> result;
		if (rowCount == m2.rowCount && colCount == m2.colCount)
		{
			result.rowCount = rowCount;
			result.colCount = colCount;
			result.AllocateMemory();
			for (int i = 0; i < result.rowCount; i++)
			{
				for (int j = 0; j < result.colCount; j++)
				{
					result.matr[i][j] = matr[i][j] + m2.matr[i][j];
				}
			}
			return result;
		}
		else
		{
			return result;
		}
	}
	Matrix<T> operator * (Matrix<T> m2)
	{
		Matrix<T> result;
		if (colCount == m2.rowCount)
		{
			result.rowCount = rowCount;
			result.colCount = m2.colCount;
			result.AllocateMemory();
			for (int i = 0; i < result.rowCount; i++)
			{
				for (int j = 0; j < result.colCount; j++)
				{
					result.matr[i][j] = 0;
					for (int k = 0; k < colCount; k++)
					{
						result.matr[i][j] += matr[i][k] * m2.matr[k][j];
					}
				}
			}
			return result;
		}
		else
		{
			return result;
		}
	}
};


int main()
{
	setlocale(LC_ALL, "Rus");
	Matrix<bool> matr(3, 4);
	matr.FillRandom(0, 1);
	cout << "Матрица 1" << endl;
	matr.Print();
	cout << endl;
	Matrix<bool> matr2(4, 4);
	matr2.FillRandom(0, 1);
	cout << "Матрица 2" << endl;
	matr2.Print();
	cout << endl;
	Matrix<bool> matr3(3, 4);
	matr2.FillRandom(0, 1);
	cout << "Матрица 3" << endl;
	matr2.Print();
	cout << endl;
	Matrix<bool> matrSum = matr + matr3;
	cout << "Сумма 1 и 3" << endl;
	matrSum.Print();
	cout << endl;
	Matrix<bool> matrUmnozenie = matr * matr2;
	cout << "Умножение 1 на 2" << endl;
	matrUmnozenie.Print();
	_getch();
	return 0;

}
