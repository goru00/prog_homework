#include <stdio.h> 
#include <stdlib.h> 
#include <conio.h> 
#include <time.h>

// Function for simple initialization of matrix elements
void DummyDataInitialization(double* pAMatrix, double* pBMatrix, int Size)
{
	int i, j; // Loop variables
	for (i = 0; i < Size; i++)
		for (j = 0; j < Size; j++) {
			pAMatrix[i * Size + j] = 1;
			pBMatrix[i * Size + j] = 1;
		}
}

// Function for random initialization of matrix elements
void RandomDataInitialization(double* pAMatrix, double* pBMatrix, int Size)
{
	int i, j; // Loop variables 
	srand(unsigned(clock()));
	for (i = 0; i < Size; i++)
		for (j = 0; j < Size; j++) {
			pAMatrix[i * Size + j] = rand() / double(1000);
			pBMatrix[i * Size + j] = rand() / double(1000);
		}
}

// Function for memory allocation and initialization of matrix elements 
void ProcessInitialization(double*& pAMatrix, double*& pBMatrix, double*& pCMatrix, int& Size)
{
	// Setting the size of matricies 
	do
	{

		printf("\nEnter size of matricies: "); scanf_s("%d", &Size);
		printf("\nChosen matricies' size = %d\n", Size); if (Size <= 0)
			printf("\nSize of objects must be greater than 0!\n");
	} while (Size <= 0);

	// Memory allocation
	pAMatrix = new double[Size * Size];
	pBMatrix = new double[Size * Size];
	pCMatrix = new double[Size * Size];

	// Initialization of matrix elements 
	DummyDataInitialization(pAMatrix, pBMatrix, Size);
	for (int i = 0; i < Size * Size; i++)
	{
		pCMatrix[i] = 0;
	}
}

// Function for formatted matrix output
void PrintMatrix(double* pMatrix, int RowCount, int ColCount) {
	int i, j; // Loop variables
	for (i = 0; i < RowCount; i++)
	{
		for (j = 0; j < ColCount; j++)
			printf("%7.4f ", pMatrix[i * RowCount + j]);
		printf("\n");
	}
}

// Function for matrix multiplication
void SerialResultCalculation(double* pAMatrix, double* pBMatrix, double* pCMatrix, int Size) {
	int i, j, k; // Loop variables 
	for (i = 0; i < Size; i++)
	{
		for (j = 0; j < Size; j++) for (k = 0; k < Size; k++)
			pCMatrix[i * Size + j] += pAMatrix[i * Size + k] * pBMatrix[k * Size + j];
	}
}

// Function for computational process termination
void ProcessTermination(double* pAMatrix, double* pBMatrix, double* pCMatrix)
{
	delete[] pAMatrix; delete[] pBMatrix; delete[] pCMatrix;
}

void main() {
	double* pAMatrix; // The first argument of matrix multiplication 
	double* pBMatrix; // The second argument of matrix multiplication 
	double* pCMatrix; // The result matrix
	int Size;	// Size of matricies 
	time_t start, finish;
	double duration;

	printf("Serial matrix multiplication program\n");
	// Memory allocation and initialization of matrix elements 
	ProcessInitialization(pAMatrix, pBMatrix, pCMatrix, Size);
	/*
	// Matrix output
	printf("Initial A Matrix \n");
	PrintMatrix(pAMatrix, Size, Size);
	printf("Initial B Matrix \n");
	PrintMatrix(pBMatrix, Size, Size);
	*/
	// Matrix multiplication 
	start = clock();
	SerialResultCalculation(pAMatrix, pBMatrix, pCMatrix, Size); finish = clock();
	duration = (finish - start) / double(CLOCKS_PER_SEC);
	/*
	// Printing the result matrix 
	printf("\n Result Matrix: \n"); PrintMatrix(pCMatrix, Size, Size);
	*/
	// Printing the time spent by matrix multiplication 
	printf("\n Time of execution: %f\n", duration);

	// Computational process termination 
	ProcessTermination(pAMatrix, pBMatrix, pCMatrix);
}

