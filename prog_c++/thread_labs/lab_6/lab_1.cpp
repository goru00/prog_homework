#include <iostream> 
#include <stdio.h> 
#include <stdlib.h> 
#include <conio.h> 
#include <time.h> 
#include <math.h>
// Функция для алгоритма Гаусса-Зейделя
void ResultCalculation(double* pMatrix, int Size, double& Eps, int& Iterations) 
{
	double dm, dmax, temp;
	int i, j; // Переменные цикла
	Iterations = 0;
	do 
	{
		dmax = 0;
		for (i = 1; i < Size - 1; i++) for (j = 1; j < Size - 1; j++) 
		{
			temp = pMatrix[Size * i + j];
			pMatrix[Size * i + j] = 0.25 * (pMatrix[Size * i + j + 1] +
				                            pMatrix[Size * i + j - 1] + 
				                            pMatrix[Size * (i + 1) + j] + 
				                            pMatrix[Size * (i - 1) + j]);
			dm = fabs(pMatrix[Size * i + j] - temp); 
			if (dmax < dm) dmax = dm;
		}
		Iterations++;
	} 
	while (dmax > Eps);
}

// Функция завершения вычислительного процесса
void ProcessTermination(double* pMatrix) 
{
   delete[] pMatrix;
}
// Функция для форматированного вывода матрицы
void PrintMatrix(double* pMatrix, int RowCount, int ColCount) 
{
	int i, j; // Переменные цикла
	for (i = 0; i < RowCount; i++) 
	{
		for (j = 0; j < ColCount; j++)
			printf("%7.4f ", pMatrix[i * ColCount + j]); 
		printf("\n");
	}
}
// Функция для простой установки значений узлов сетки
void DummyDataInitialization(double* pMatrix, int Size) 
{
	int i, j; // Переменные цикла
	double h = 1.0 / (Size - 1);
	// Установка значений узлов сетки 
	for (i=0; i<Size; i++) 
	{
	for (j = 0; j < Size; j++)
		if ((i == 0) || (i == Size - 1) || (j == 0) || (j == Size - 1)) pMatrix[i * Size + j] = 100;
		else
			pMatrix[i * Size + j] = 0;
    }
}
// Функция для выделения памяти и инициализации узлов сетки
void ProcessInitialization(double*& pMatrix, int& Size, double& Eps) {
	// Установка размера сетки 
	do {
	printf("\nВведите размер сетки: "); 
	scanf_s("%d", &Size);
	printf("\nВыбранный размер сетки = %d", Size); 
	if (Size <= 2)
		printf("\nРазмер сетки должен быть больше 2!\n");
} while (Size <= 2);
// Установка требуемой точности 
do 
{
    printf("\nВведите требуемую точность: "); 
    scanf_s("%lf", &Eps);
    printf("\nВыбранная точность = %lf", Eps); 
    if (Eps <= 2)
    printf("\nТочность должна быть больше 0!\n");
}	
while (Eps <= 0);

// Распределение памяти
pMatrix = new double[Size * Size];

// Установка значений узлов сетки 
DummyDataInitialization(pMatrix, Size);
}

int main() 
{
	setlocale(LC_ALL, "Russian");
	double* pMatrix;	// Матрица узлов сетки 
	int	Size;	// Размерность матрицы
	double Eps;	// Требуемая точность 
	int	Iterations; // Число итераций
	printf("Последовательный алгоритм Гаусса - Зайделя\n");

	// Процесс инициализации
	ProcessInitialization(pMatrix, Size, Eps);
	// Матричный вывод
	printf("Исходная матрица: \n"); 
	PrintMatrix(pMatrix, Size, Size);

	// Метод Гаусса-Зейделя
	ResultCalculation(pMatrix, Size, Eps, Iterations);

	// Печать результата
	printf("\n Количество итераций: %d\n", Iterations); 
	printf("\n Матрица результатов: \n");
	PrintMatrix(pMatrix, Size, Size); 
	_getch();

	// Завершение вычислительного процесса 
	ProcessTermination(pMatrix);
}
