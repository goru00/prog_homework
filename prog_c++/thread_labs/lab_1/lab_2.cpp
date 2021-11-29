#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <mpi.h>


int ProcNum = 0; //Число доступных процессов
int ProcRank = 0; //Число текущих процессов

// функция для простого определения элементов матрицы и вектора
void DummyDataInitialization(double* pMatrix, double* pVector, int Size) {
	int i, j; //Переменные цикла
	for (i = 0; i < Size; i++) {
		pVector[i] = 1;
		for (j = 0; j < Size; j++)
			pMatrix[i * Size + j] = i;
	}
}

//Функция для произвольного определения элементов матрицы и вектора
void RandomDataInitialization(double* pMatrix, double* pVector, int Size) {
	int i, j;
	srand(unsigned(clock()));
	for (i = 0; i < Size; i++) {
		pVector[i] = rand() / double(1000);
		for (j = 0; j < Size; j++)
			pMatrix[i * Size + j] = rand() / double(1000);
	}
}

//Функция для выделения памяти и инициализации данных
void ProcessInitialization(double*& pMatrix, double*& pVector, double*& pResult, double*& pProcRows, double*& pProcResult, int& Size, int& RowNum) {
	int RestRows; //Количество строк, которые еще не были распределены
	int i; //Переменная цикла
	if (ProcRank == 0) {
		do {
			printf("\nEnter size of the initial objects:");
			scanf_s("%d", &Size);
			if (Size < ProcNum) {
				printf("Size of the objects must be greater than number of processes! \n");
			}
		} while (Size < ProcNum);
	}
	MPI_Bcast(&Size, 1, MPI_INT, 0, MPI_COMM_WORLD);

	RestRows = Size;
	for (i = 0; i < ProcRank; i++)
		RestRows = RestRows - RestRows / (ProcNum - i);
	RowNum = RestRows / (ProcNum - ProcRank);

	pVector = new double[Size];
	pResult = new double[Size];
	pProcRows = new double[RowNum * Size];
	pProcResult = new double[RowNum];

	if (ProcRank == 0) {
		pMatrix = new double[Size * Size];
		RandomDataInitialization(pMatrix, pVector, Size);
	}
}

//Распределение данных между процессами
void DataDistribution(double* pMatrix, double* pProcRows, double* pVector, int Size, int RowNum) {
	int* pSendNum; // количество элементов, отправленных в процесс
	int* pSendInd; // индекс первого элемента данных, отправленного процессу 
	int RestRows = Size; // Количество строк, которые еще не были распределены

	MPI_Bcast(pVector, Size, MPI_DOUBLE, 0, MPI_COMM_WORLD);

	// Выделяем память для временных объектов 
	pSendInd = new int[ProcNum];
	pSendNum = new int[ProcNum];

	// Определите расположение строк матрицы для текущего процесса 
	RowNum = (Size / ProcNum);
	pSendNum[0] = RowNum * Size;
	pSendInd[0] = 0;
	for (int i = 1; i < ProcNum; i++) {
		RestRows -= RowNum;
		pSendNum[i] = RowNum * Size;
		pSendInd[i] = pSendInd[i - 1] + pSendNum[i - 1];
	}

	// Разбрасываем ряды
	MPI_Scatterv(pMatrix, pSendNum, pSendInd, MPI_DOUBLE, pProcRows, pSendNum[ProcRank], MPI_DOUBLE, 0, MPI_COMM_WORLD);
	//Освобождаем память
	delete[] pSendNum;
	delete[] pSendInd;
}

// Функция для сбора вектора результатов
void ResultReplication(double* pProcResult, double* pResult, int Size, int RowNum) {
	int i; //Переменная цикла
	int* pReceiveNum; // Количество элементов, которые отправляет текущий процесс 
	int* pReceiveInd; /* Индекс первого элемента из текущего процесса
в векторе результатов */
	int RestRows = Size; // Количество строк, которые еще не были распределены
	// Аллоцировать память для временных объектов
	pReceiveNum = new int[ProcNum];
	pReceiveInd = new int[ProcNum];
	//Определить расположение блока вектора результатов текущего процессора 
	pReceiveInd[0] = 0;
	pReceiveNum[0] = Size / ProcNum;
	for (i = 1; i < ProcNum; i++) {
		RestRows -= pReceiveNum[i - 1];
		pReceiveNum[i] = RestRows / (ProcNum - i);
		pReceiveInd[i] = pReceiveInd[i - 1] + pReceiveNum[i - 1];
	}
	//Собираем весь вектор результатов на каждом процессоре 
	MPI_Allgatherv(pProcResult, pReceiveNum[ProcRank], MPI_DOUBLE, pResult, pReceiveNum, pReceiveInd, MPI_DOUBLE, MPI_COMM_WORLD);
	//Освобождаем память
	delete[] pReceiveNum;
	delete[] pReceiveInd;
}

// Функция для последовательного матрично-векторного умножения
void SerialResultCalculation(double* pMatrix, double* pVector, double* pResult, int Size) {
	int i, j;
	for (i = 0; i < Size; i++) {
		pResult[i] = 0;
		for (j = 0; j < Size; j++)
			pResult[i] += pMatrix[i * Size + j] * pVector[j];
	}
}

// Функция для вычисления частичного матрично-векторного умножения
void ParallelResultCalculation(double* pProcRows, double* pVector, double* pProcResult, int Size, int RowNum) {
	int i, j;
	for (i = 0; i < RowNum; i++) {
		pProcResult[i] = 0;
		for (j = 0; j < Size; j++)
			pProcResult[i] += pProcRows[i * Size + j] * pVector[j];
	}
}

// Функция для форматированного вывода матрицы
void PrintMatrix(double* pMatrix, int RowCount, int ColCount) {
	int i, j;
	for (i = 0; i < RowCount; i++) {
		for (j = 0; j < ColCount; j++)
			printf("%7.4f", pMatrix[i * ColCount + j]);
	}
}

// Функция для форматированного вывода вектора
void PrintVector(double* pVector, int Size) {
	int i;
	for (i = 0; i < Size; i++)
		printf("%7.4f", pVector[i]);
}

void TestDistribution(double* pMatrix, double* pVector, double* pProcRows, int Size, int RowNum) {
	if (ProcRank == 0) {
		printf("Initial Matrix: \n");
		PrintMatrix(pMatrix, Size, Size);
		printf("Initial Vector: \n");
		PrintVector(pVector, Size);
	}
	MPI_Barrier(MPI_COMM_WORLD);
	for (int i = 0; i < ProcNum; i++) {
		if (ProcRank == i) {
			printf("\nProcRank = %d \n", ProcRank);
			printf(" Matrix Stripe:\n");
			PrintMatrix(pProcRows, RowNum, Size);
			printf("Vector: \n");
			PrintVector(pVector, Size);
		}
		MPI_Barrier(MPI_COMM_WORLD);
	}
}

void TestPartialResults(double* pProcResult, int RowNum) {
	int i;
	for (i = 0; i < ProcNum; i++) {
		if (ProcRank == i) {
			printf("\nProcRank = %d \n Part of result vector: \n", ProcRank);
			PrintVector(pProcResult, RowNum);
		}
		MPI_Barrier(MPI_COMM_WORLD);
	}
}

void TestResult(double* pMatrix, double* pVector, double* pResult, int Size) {
	// Буфер для хранения результата последовательного матрично-векторного умножения 
	double* pSerialResult;
	// Флаг, который показывает, идентичны ли векторы или нет 
	int equal = 0;
	int i; //Переменная цикла
	if (ProcRank == 0) {
		pSerialResult = new double[Size];
		SerialResultCalculation(pMatrix, pVector, pSerialResult, Size);
		for (i = 0; i < Size; i++) {
			if (pResult[i] != pSerialResult[i])
				equal = 1;
		}
		if (equal == 1)
			printf("The results of serial and parallel algorithms "
				"are NOT identical. Check your code.");
		else
			printf("The results of serial and parallel algorithms "
				"are identical. Check your code.");
	}
}

// Функция завершения вычислительного процесса
void ProcessTermaination(double* pMatrix, double* pVector, double* pResult, double* pProcRows, double* pProcResult) {
	if (ProcRank == 0)
		delete[] pMatrix;
	delete[] pVector;
	delete[] pResult;
	delete[] pProcRows;
	delete[] pProcResult;
}

void main(int argc, char* argv[]) {
	double* pMatrix; // Первый аргумент - начальная матрица 
	double* pVector; // Второй аргумент - начальный вектор
	double* pResult; // Вектор результата для матрично-векторного умножения 
	int Size; // Размеры исходной матрицы и вектора
	double* pProcRows;
	double* pProcResult;
	int RowNum;
	double Start, Finish, Duration;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &ProcNum);
	MPI_Comm_rank(MPI_COMM_WORLD, &ProcRank);

	ProcessInitialization(pMatrix, pVector, pResult, pProcRows, pProcResult, Size, RowNum);
	Start = MPI_Wtime();
	DataDistribution(pMatrix, pProcRows, pVector, Size, RowNum);
	ParallelResultCalculation(pProcRows, pVector, pProcResult, Size, RowNum);
	ResultReplication(pProcResult, pResult, Size, RowNum);
	Finish = MPI_Wtime();
	Duration = Finish - Start;

	TestResult(pMatrix, pVector, pResult, Size);
	if (ProcRank == 0) {
		printf("Time of execution = %f\n", Duration);
	}

	ProcessTermaination(pMatrix, pVector, pResult, pProcRows, pProcResult);
	MPI_Finalize();
}

