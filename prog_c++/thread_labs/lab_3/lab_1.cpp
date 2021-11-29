#include <stdio.h> 
#include <stdlib.h> 
#include <conio.h> 
#include <time.h> 
#include <math.h>

int* pSerialPivotPos;	// The Number of pivot rows selected at the iterations
int* pSerialPivotIter; // The Iterations, at which the rows were pivots

// Function for simple initialization of the matrix and the vector elements 
void DummyDataInitialization(double* pMatrix, double* pVector, int Size) {
	int i, j; // Loop variables

	for (i = 0; i < Size; i++) {
		pVector[i] = i + 1;
		for (j = 0; j < Size; j++) {
			if (j <= i)
				pMatrix[i * Size + j] = 1; else
				pMatrix[i * Size + j] = 0;
		}
	}
}

// Function for random initialization of the matrix and the vector elements 
void RandomDataInitialization(double* pMatrix, double* pVector, int Size)
{
	int i, j; // Loop variables 
	srand(unsigned(clock()));
	for (i = 0; i < Size; i++)
	{
		pVector[i] = rand() / double(1000); for (j = 0; j < Size; j++) {
			if (j <= i)
				pMatrix[i * Size + j] = rand() / double(1000); else
				pMatrix[i * Size + j] = 0;
		}
	}
}

// Function for memory allocation and definition of the objects elements 
void ProcessInitialization(double*& pMatrix, double*& pVector, double*& pResult, int& Size) {
	// Setting the size of the matrix and the vector 
	do {
		printf("\nEnter size of the matrix and the vector: ");
		scanf_s("%d", &Size);
		printf("\nChosen size = %d \n", Size);

		if (Size <= 0)
			printf("\nSize of objects must be greater than 0!\n");
	} while (Size <= 0);

	// Memory allocation
	pMatrix = new double[Size * Size]; pVector = new double[Size]; pResult = new double[Size];

	// Initialization of the matrix and the vector elements

	DummyDataInitialization(pMatrix, pVector, Size);
	//RandomDataInitialization(pMatrix, pVector, Size);
}

// Function for formatted matrix output
void PrintMatrix(double* pMatrix, int RowCount, int ColCount) {
	int i, j; // Loop variables
	for (i = 0; i < RowCount; i++) {
		for (j = 0; j < ColCount; j++)
			printf("%7.4f ", pMatrix[i * RowCount + j]); printf("\n");
	}
}

// Function for formatted vector output
void PrintVector(double* pVector, int Size) {
	int i;
	for (i = 0; i < Size; i++) printf("%7.4f ", pVector[i]);
}

// Finding the pivot row
int FindPivotRow(double* pMatrix, int Size, int Iter) {
	int PivotRow = -1; // The index of the pivot row
	int MaxValue = 0; // The value of the pivot element 
	int i;	// Loop variable

	// Choose the row, that stores the maximum element 
	for (i = 0; i < Size; i++) {
		if ((pSerialPivotIter[i] == -1) && (fabs(pMatrix[i * Size + Iter]) > MaxValue)) {
			PivotRow = i;
			MaxValue = fabs(pMatrix[i * Size + Iter]);
		}
	}
	return PivotRow;
}

// Column elimination
void SerialColumnElimination(double* pMatrix, double* pVector, int Pivot, int Iter, int Size) {
	double PivotValue, PivotFactor; PivotValue = pMatrix[Pivot * Size + Iter]; for (int i = 0; i < Size; i++) {
		if (pSerialPivotIter[i] == -1) {
			PivotFactor = pMatrix[i * Size + Iter] / PivotValue; for (int j = Iter; j < Size; j++) {
				pMatrix[i * Size + j] -= PivotFactor * pMatrix[Pivot * Size + j];
			}
			pVector[i] -= PivotFactor * pVector[Pivot];
		}
	}
}

// Gaussian elimination
void SerialGaussianElimination(double* pMatrix, double* pVector, int Size) {
	int Iter;	// The number of the iteration of the gaussian
// elimination
	int PivotRow;	// The number of the current pivot row 
	for (Iter = 0; Iter < Size; Iter++) {
		// Finding the pivot row
		PivotRow = FindPivotRow(pMatrix, Size, Iter); pSerialPivotPos[Iter] = PivotRow;

		pSerialPivotIter[PivotRow] = Iter; SerialColumnElimination(pMatrix, pVector, PivotRow, Iter, Size);
	}
}

// Back substution
void SerialBackSubstitution(double* pMatrix, double* pVector, double* pResult, int Size) {
	int RowIndex, Row;
	for (int i = Size - 1; i >= 0; i--) {
		RowIndex = pSerialPivotPos[i];
		pResult[i] = pVector[RowIndex] / pMatrix[Size * RowIndex + i]; for (int j = 0; j < i; j++) {
			Row = pSerialPivotPos[j];
			pVector[j] -= pMatrix[Row * Size + i] * pResult[i]; pMatrix[Row * Size + i] = 0;
		}
	}
}



// Function for the execution of Gauss algorithm
void SerialResultCalculation(double* pMatrix, double* pVector, double* pResult, int Size) {

	// Memory allocation 
	pSerialPivotPos = new int[Size];
	pSerialPivotIter = new int[Size];
	for (int i = 0; i < Size; i++)
	{
		pSerialPivotIter[i] = -1;
	}
	// Gaussian elimination
	SerialGaussianElimination(pMatrix, pVector, Size);
	// Back substitution
	SerialBackSubstitution(pMatrix, pVector, pResult, Size);

	// Memory deallocation 
	delete[] pSerialPivotPos;
	delete[] pSerialPivotIter;
}

// Function for computational process termination
void ProcessTermination(double* pMatrix, double* pVector, double* pResult)
{
	delete[] pMatrix; delete[] pVector; delete[] pResult;
}


void main() {
	double* pMatrix; // The matrix of the linear system 
	double* pVector; // The right parts of the linear system 
	double* pResult; // The result vector
	int Size;	// The sizes of the initial matrix and the vector 
	time_t start, finish;
	double duration;

	printf("Serial Gauss algorithm for solving linear systems\n");
	// Memory allocation and definition of objects' elements 
	ProcessInitialization(pMatrix, pVector, pResult, Size);
	/*
	// The matrix and the vector output 
	printf("Initial Matrix \n");
	PrintMatrix(pMatrix, Size, Size);
	printf("Initial Vector \n");
	PrintVector(pVector, Size);
	*/
	// Execution of Gauss algorithm 
	start = clock();
	SerialResultCalculation(pMatrix, pVector, pResult, Size);
	finish = clock();
	duration = (finish - start) / double(CLOCKS_PER_SEC);
	/*
	// Printing the result vector 
	printf("\n Result Vector: \n");
	PrintVector(pResult, Size);
	*/
	// Printing the execution time of Gauss method 
	printf("\n Time of execution: %f\n", duration);

	// Computational process termination 
	ProcessTermination(pMatrix, pVector, pResult);
	_getch();
}



