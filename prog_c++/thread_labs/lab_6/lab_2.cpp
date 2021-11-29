
#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 
#include <conio.h> 
#include <time.h> 
#include <math.h> 
#include <mpi.h> 
#include <algorithm>
using namespace std;
static int ProcNum = 0;	// Количество доступных процессов 
static int ProcRank = -1; // Рейтинг текущего процесса
// Функция для распределения строк сетки между процессами
void DataDistribution(double* pMatrix, double* pProcRows, int RowNum,int Size) 
{
   int* pSendNum; // Количество элементов, отправленных в процесс
   int* pSendInd; // Индекс первого элемента данных, отправленного в процесс 
   int RestRows=Size;
   // Выделение памяти для временных объектов 
   pSendInd = new int [ProcNum]; 
   pSendNum = new int [ProcNum];
   // Определение расположения строк матрицы для текущего процесса 
   RowNum = (Size-2)/ProcNum+2;
   pSendNum[0] = RowNum * Size; 
   pSendInd[0] = 0;
   for (int i = 1; i < ProcNum; i++) 
   {
	  RestRows = RestRows - RowNum + 2; 
	  RowNum = (RestRows - 2) / (ProcNum - i) + 2; 
	  pSendNum[i] = (RowNum)*Size;
	  pSendInd[i] = pSendInd[i - 1] + pSendNum[i - 1] - Size;
   }
  // Разброс рядов
  MPI_Scatterv(pMatrix, pSendNum, pSendInd, MPI_DOUBLE, pProcRows, pSendNum[ProcRank], MPI_DOUBLE, 0, MPI_COMM_WORLD);
  delete[] pSendInd; 
  delete[] pSendNum;
}
// Функция завершения вычислительного процесса
void ProcessTermination(double* pMatrix, double* pProcRows) 
{
	if (ProcRank == 0)
	delete[] pMatrix; 
	delete[] pProcRows;
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
// Функция для выполнения итерации метода Гаусса-Зейделя 
double IterationCalculation(double* pProcRows, int Size, int RowNum) 
{
  int i, j; // Переменные цикла 
  double dm, dmax,temp;
  dmax = 0;
  for (i = 1; i < RowNum - 1; i++) 
	for (j = 1; j < Size - 1; j++) 
	{
	   temp = pProcRows[Size * i + j];
	   pProcRows[Size * i + j] = 0.25 * (pProcRows[Size * i + j + 1] +
		                                 pProcRows[Size * i + j - 1] + 
		                                 pProcRows[Size * (i + 1) + j] + 
		                                 pProcRows[Size * (i - 1) + j]);
	  dm = fabs(pProcRows[Size * i + j] - temp); 
	  if (dmax < dm) dmax = dm;
    }
       return dmax;
}

// Функция для тестирования распределения данных
void TestDistribution(double* pMatrix, double* pProcRows, int Size, int RowNum) 
{
	if (ProcRank == 0) 
	{
		printf("Initial Matrix: \n"); 
		PrintMatrix(pMatrix, Size, Size);
	}
	MPI_Barrier(MPI_COMM_WORLD); 
	for (int i = 0; i < ProcNum; i++) 
	{
		if (ProcRank == i) 
		{
			printf("\nProcRank = %d \n", ProcRank);
			//		fprintf(" Matrix Stripe:\n"); 
			PrintMatrix(pProcRows, RowNum, Size);
		}
		MPI_Barrier(MPI_COMM_WORLD);
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
		if ((i == 0) || (i == Size - 1) || (j == 0) || (j == Size - 1)) 
			pMatrix[i * Size + j] = 100;
		else
			pMatrix[i * Size + j] = 0;
    }
}

// Функция для распределения памяти и инициализации узлов сетки
void ProcessInitialization(double*& pMatrix, double*& pProcRows, int& Size, int& RowNum, double& Eps) 
{
	int RestRows; // Количество строк, которые еще не были распределены
	// Установка размера сетки 
	if (ProcRank == 0) 
	{
	  do 
	  {
		printf("\nВведите размер сетки: "); 
		scanf_s("%d", &Size);
		if (Size <= 2) 
		{
			printf("\n Размер сетки должен быть больше, чем 2! \n");
		}
		if (Size < ProcNum) 
		{
			printf("Размер сетки должен быть больше, чем" "количество процессов! \n ");
		}
	  } 
	  while ((Size <= 2) || (Size < ProcNum));
	  // Установка требуемой точности 
	  do 
	  {
	    printf("\nВведите требуемую точность: "); 
	    scanf_s("%lf", &Eps);
	    printf("\nВыбранная точность = %lf", Eps); 
	    if (Eps <= 0)
		printf("\nТочность должна быть больше, чем 0!\n");
      }
     while (Eps <= 0);
    }
  MPI_Bcast(&Size, 1, MPI_INT, 0, MPI_COMM_WORLD);
  MPI_Bcast(&Eps, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
  // Определение количества строк матрицы, хранящихся в каждом процессе 
  RestRows = Size;
  for (int i = 0; i < ProcRank; i++)
  RestRows = RestRows - RestRows / (ProcNum - i); 
  RowNum = (RestRows - 2) / (ProcNum - ProcRank) + 2;
	// Распределение памяти
	pProcRows = new double[RowNum * Size];
    // Определите значения элементов исходных объектов 
    if (ProcRank == 0) 
	{
     // Начальная матрица существует только на поворотном процессе 
     pMatrix = new double [Size*Size];
     // Значения элементов определяются только на поворотном процессе 
	 DummyDataInitialization(pMatrix, Size);
    }
}
// Функция для обмена граничными рядами полос процесса 
void ExchangeData(double* pProcRows, int Size, int RowNum) 
{
  MPI_Status status;
  int NextProcNum = (ProcRank == ProcNum - 1) ? MPI_PROC_NULL : ProcRank + 1; 
  int PrevProcNum = (ProcRank == 0) ? MPI_PROC_NULL : ProcRank - 1;
  // Отправить в NextProcNum и получить из PrevProcNum 
  MPI_Sendrecv(pProcRows + Size * (RowNum - 2),Size, MPI_DOUBLE,NextProcNum, 4, pProcRows, Size, MPI_DOUBLE, PrevProcNum, 4, MPI_COMM_WORLD, & status);
  // Отправить в PrevProcNum и получить из NextProcNum 
  MPI_Sendrecv(pProcRows + Size, Size, MPI_DOUBLE, PrevProcNum, 5, pProcRows + (RowNum - 1) * Size, Size, MPI_DOUBLE, NextProcNum, 5, MPI_COMM_WORLD, & status);
}

// Функция для параллельного метода Гаусса - Зейделя
void ParallelResultCalculation(double* pProcRows, int Size, int RowNum, double Eps, int& Iterations) 
{
	double ProcDelta, Delta; 
	Iterations = 0;
	do 
	{
		Iterations++;
		// Обмен граничными строками технологической полосы 
		ExchangeData(pProcRows, Size,RowNum);
		// Итерация метода Гаусса-Зейделя
		ProcDelta = IterationCalculation(pProcRows, Size, RowNum);
		// Вычисление максимального значения отклонения 
		MPI_Allreduce(&ProcDelta, &Delta, 1,MPI_DOUBLE, MPI_MAX, MPI_COMM_WORLD);
	} 
	while (Delta > Eps);
}
// Функция для сбора вектора результатов
void ResultCollection(double* pProcRows, double* pMatrix, int Size, int RowNum)
{
	int* pReceiveNum; // Количество элементов, которые отправляет текущий процесс 
	int *pReceiveInd; // Индекс первого элемента полученного блока 
	int RestRows = Size;
	int i;	// Переменные цикла

	// Выделение памяти для временных объектов
	pReceiveNum = new int [ProcNum]; 
	pReceiveInd = new int [ProcNum];

	// Определите расположение блока вектора результатов текущего процессора 
	pReceiveInd[0] = 0;
	RowNum = (Size - 2) / ProcNum + 2; 
	pReceiveNum[0] = RowNum * Size; 
	for (i = 1; i < ProcNum; i++) 
	{
		RestRows = RestRows - RowNum + 1; 
		RowNum = (RestRows - 2) / (ProcNum - i) + 2; 
		pReceiveNum[i] = RowNum * Size;
		pReceiveInd[i] = pReceiveInd[i - 1] + pReceiveNum[i - 1] - Size;
	}
	// Соберите весь вектор результатов на каждом процессоре 
	MPI_Allgatherv(pProcRows, pReceiveNum[ProcRank], MPI_DOUBLE, pMatrix, pReceiveNum, pReceiveInd, MPI_DOUBLE, MPI_COMM_WORLD);
	// Освобождаем память
	delete [] pReceiveNum; 
	delete [] pReceiveInd;
}

// Функция для последовательного метода Гаусса - Зейделя
void SerialResultCalculation(double* pMatrixCopy, int Size, double Eps, int& Iter) 
{
	int i, j; // Переменные цикла
	double dm, dmax,temp;
	Iter = 0; do 
	{
		dmax = 0;
		for (i = 1; i < Size - 1; i++) 
			for (j = 1; j < Size - 1; j++) 
			{
			 temp = pMatrixCopy[Size * i + j];
			 pMatrixCopy[Size * i + j] = 0.25 * (pMatrixCopy[Size * i + j + 1] +
				                                 pMatrixCopy[Size * i + j - 1] + 
				                                 pMatrixCopy[Size * (i + 1) + j] + 
				                                 pMatrixCopy[Size * (i - 1) + j]);
			 dm = fabs(pMatrixCopy[Size * i + j] - temp); 
			 if (dmax < dm) dmax = dm;
		    }
		Iter++;
	} 
	while (dmax > Eps);
}
// Функция копирования исходных данных
void CopyData(double* pMatrix, int Size, double* pSerialMatrix) 
{
	copy(pMatrix, pMatrix + Size, pSerialMatrix);
}

// Функция для проверки результата вычислений

void TestResult(double* pMatrix, double* pSerialMatrix, int Size, double Eps) 
{
	int equal = 0; // =1, если матрицы не равны 
	int Iter;
	if (ProcRank == 0) 
	{
		SerialResultCalculation(pSerialMatrix, Size, Eps, Iter); 
		for (int i = 0; i < Size * Size; i++) 
		{
			if (fabs(pSerialMatrix[i] - pMatrix[i]) >= Eps) 
				equal = 1; 
			break;
		}
		if (equal == 1)
			printf("Результаты последовательного и параллельного алгоритмов" "НЕ идентичны. Проверьте свой код.");
		else
			printf("Результаты последовательного и параллельного алгоритмов" "идентичны.");
	}
}

// Функция для установки значений узлов сетки с помощью генератора случайных чисел 
void RandowmDataInitialization (double* pMatrix, int Size) 
{
 int i, j; // Переменные цикла
 srand(unsigned(clock()));
 // Установка значений узлов сетки 
 for (i=0; i<Size; i++) 
 {
  for (j = 0; j < Size; j++)
	if ((i == 0) || (i == Size - 1) || (j == 0) || (j == Size - 1)) 
		pMatrix[i * Size + j] = 100;
	else
		pMatrix[i * Size + j] = rand() / double(1000);
 }
}

int main(int argc, char* argv[]) 
{
	setlocale(LC_ALL, "Russian");
	double* pMatrix;	// Матрица узлов сетки
	double* pProcRows;	// Полоса матрицы на текущем процессе 
	double* pSerialMatrix; // Результат последовательного метода
	int	Size;	// Размер матрицы
	int	RowNum;	// Количество строк в полосе матрицы 
	double Eps;	// Требуемая точность
	int	Iterations;	// Число итераций 
	double currDelta, delta;
	setvbuf(stdout, 0, _IONBF, 0); 
	MPI_Init(&argc, &argv); 
	MPI_Comm_size(MPI_COMM_WORLD, &ProcNum); 
	MPI_Comm_rank(MPI_COMM_WORLD, &ProcRank);
	if (ProcRank == 0) 
	{
		printf("Параллельный алгоритм Гаусса - Зайделя \n"); 
		fflush(stdout);
	}
	// Инициализация процесса
	ProcessInitialization(pMatrix, pProcRows, Size, RowNum, Eps);
	// Создание копии исходных данных 
	if (ProcRank == 0) 
	{
	pSerialMatrix = new double[Size * Size]; 
	CopyData(pMatrix, Size, pSerialMatrix);
    }
   // Распределение данных между процессами 
   DataDistribution(pMatrix, pProcRows, Size,RowNum);
   // Параллельный метод Гаусса-Зейделя 
   ParallelResultCalculation(pProcRows, Size,RowNum,Eps, Iterations);
   //TestDistribution(pMatrix, pProcRows, Size,RowNum);
   // Сбор результатов расчета 
   ResultCollection(pProcRows, pMatrix, Size, RowNum); 
   TestDistribution(pMatrix, pProcRows, Size,RowNum);
   // Печать результата
   printf("\n Итерации %d \n", Iterations); 
   printf("\nМатрица результатов: \n");
  if (ProcRank == 0) 
  {
	//TestResult(pMatrix,Size,pMatrixCopy,Eps); 
	PrintMatrix(pMatrix,Size,Size);
  }
  // Завершение процесса
 if (ProcRank == 0) 
 //delete []pSerialMatrix; 
 ProcessTermination(pMatrix, pProcRows); 
 MPI_Finalize();
}
