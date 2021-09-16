#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

// Функция для простого определения элементов матрицы и вектора
void DummyDataInitialization(double* pMatrix, double* pVector, int Size){
int i, j;

for (i = 0; i < Size; i++) {
	pVector[i] = 1;
	for (j = 0; j < Size; j++)
		pMatrix[i * Size + j] = i;
  }
}
// Функция для произвольного определения элементов матрицы и вектора
void RandomDataInitialization(double* pMatrix, double *pVector, int Size) {
	int i, j;
	srand(unsigned(clock()));
	for (i = 0; i < Size; i++) {
		pVector[i] = rand() / double(1000);
		for (j = 0; j < Size; j++)
			pMatrix[i * Size + j] = rand() / double(1000);
	}

}
// Функция для выделения памяти и определения элементов объекта 
void ProcessInitialization(double* &pMatrix, double* &pVector, double* &pResult, int &Size) {
	do {
		printf("\nEnter size of initial objects:");
		scanf_s("%d", &Size);
		printf("\nChosen objects size = %d\n", Size);
		if (Size <= 0)
		printf("\nChosen objects must be greater than 0!\n");
	} 
	while (Size <= 0);
		pMatrix = new double[Size * Size];
		pVector = new double[Size];
		pResult = new double[Size];
		DummyDataInitialization(pMatrix, pVector, Size);
	}

// Функция для форматированного вывода матрицы
void PrintMatrix(double* pMatrix, int RowCount, int ColCount) {
	int i, j;
	for (i = 0; i < RowCount; i++) {
		for (j = 0; j < ColCount; j++)
			printf("%7.4f", pMatrix[i * RowCount + j]);
		printf("\n");
	}
}
// Функция для форматированного вывода вектора
void PrintVector(double* pVector, int Size) {
	int i;
	for (i = 0; i < Size; i++)
		printf("%7.4f", pVector[i]);
}
// Функция для матрично-векторного умножения
void ResultCalculation(double* pMatrix, double* pVector, double* pResult, int Size) {
	int i, j;
	for (i = 0; i < Size; i++) {
		pResult[i] = 0;
		for (j = 0; j < Size; j++)
			pResult[i] += pMatrix[i * Size + j] * pVector[j];
	}
}
// Функция завершения вычислительного процесса
void ProcessTermination(double* pMatrix, double* pVector, double* pResult) {
	delete[] pMatrix;  
	delete[] pVector; 
	delete[] pResult; 
}

void main() {
	double* pMatrix; // Первый аргумент - начальная матрица 
	double* pVector; // Второй аргумент - начальный вектор
	double* pResult; // Вектор результата для матрично-векторного умножения
	int Size; // Размеры исходной матрицы и вектора
	time_t start, finish;
	double duration;

	printf("Serial matrix-vector multiplication program\n");
        // Распределение памяти и определение элементов объектов 
	ProcessInitialization(pMatrix, pVector, pResult, Size);
	/*
        // Вывод матриц и векторов 
	printf("Initial Matrix \n");
	PrintMatrix(pMatrix, Size, Size);
	printf("Initial Vector \n");
	PrintVector(pVector, Size);
	*/
        // Матрично-векторное умножение 
	start = clock();
	ResultCalculation(pMatrix, pVector, pResult, Size);
	finish = clock();
	duration = (finish - start) / double(CLOCKS_PER_SEC);
	/*
        // Печать вектора результатов 
	printf("\n Result Vector: \n");
	PrintVector(pResult, Size);
	*/
        // Вывод времени, затраченного на матрично-векторное умножение 
	printf("\n Time of execution: %f\n", duration);
        // Завершение вычислительного процесса 
	ProcessTermination(pMatrix, pVector, pResult);
}