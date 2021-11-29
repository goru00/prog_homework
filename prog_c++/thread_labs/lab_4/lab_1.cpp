#include <iostream>
#include <cstdlib> 
#include <cstdio> 
#include <cstring> 
#include <ctime>
#include <algorithm>
using namespace std;
const double RandomDataMultiplier = 1000.0;
// Функция для простой установки начальных данных
void DummyDataInitialization(double*& pData, int& DataSize)
{
	for (int i = 0; i < DataSize; i++)
		pData[i] = DataSize - i;
}
// Функция выделения памяти и установки начальных значений
void ProcessInitialization(double*& pData, int& DataSize)
{
	do
	{
		printf("Введите размер данных для сортировки: ");
		scanf_s("%d", &DataSize);
		if (DataSize <= 0)
			printf("Размер данных должен быть больше нуля\n");
	} while (DataSize <= 0);
	printf("Сортировка %d элемента данных\n", DataSize);
	pData = new double[DataSize];
	// Simple setting the data 
	DummyDataInitialization(pData, DataSize);

	// Setting the data by the random generator
	//RandomDataInitialization(pData, DataSize);
}

// Функция для инициализации данных генератором случайных чисел 
void RandomDataInitialization(double*& pData, int& DataSize)
{
	srand((unsigned)time(0));
	for (int i = 0; i < DataSize; i++)
		pData[i] = double(rand()) / RAND_MAX * RandomDataMultiplier;
}

// Алгоритм последовательной пузырьковой сортировки
void SerialBubble(double* pData, int DataSize)
{
	double Tmp;
	for (int i = 1; i < DataSize; i++)
		for (int j = 0; j < DataSize - i; j++)
			if (pData[j] > pData[j + 1])
			{
				Tmp = pData[j];
				pData[j] = pData[j + 1];
				pData[j + 1] = Tmp;
			}
}

// Функция для вывода форматированных данных
void PrintData(double* pData, int DataSize)
{
	for (int i = 0; i < DataSize; i++)
		printf("%7.4f ", pData[i]);
	printf("\n");
}

// Сортировка по стандартному библиотечному алгоритму 

void SerialStdSort(double* pData, int DataSize)
{
	sort(pData, pData + DataSize);
}

// Функция завершения вычислительного процесса 
void ProcessTermination(double *pData) 
{
   delete[]pData;
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	double* pData = 0;
	int DataSize = 0;
	time_t start = 0;
	time_t finish = 0;;
	double duration = 0.0;
	printf("Программа последовательной сортировки пузырьков\n");
	// Процесс инициализации
	ProcessInitialization(pData, DataSize);
	printf("Данные перед сортировкой\n");
	PrintData(pData, DataSize);
	//Serial bubble sort start = clock();
	SerialBubble(pData, DataSize);
	finish = clock();
	printf("Данные после сортировки\n");
	PrintData(pData, DataSize);
	duration = (finish - start) / double(CLOCKS_PER_SEC);
	printf("Время выполнения: %f\n", duration);
	// Process termination ProcessTermination(pData);
	return 0;
}


