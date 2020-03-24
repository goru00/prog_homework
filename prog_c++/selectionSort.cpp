// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <ctime>
using namespace std;
void bubbleSort(int mass[], int length)
{
    int min, temp;
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = length - 1; j > i; j--)
        {
            if (mass[j - 1] > mass[j])
            {
                temp = mass[j - 1];
                mass[j - 1] = mass[j];
                mass[j] = temp;
            }
        }
    }
}

void pushMass(int mass[], int length)
{

    for (int i = 0; i < length; i++)
    {
        mass[i] = rand() % 100;
    }
}
void output(int mass[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << "\t" << mass[i];
    }
    cout << endl;
}
int main()
{
    srand(time(NULL));
    int length = 9;
    int mass[9];
    pushMass(mass, length);
    output(mass, length);
    selectionSort(mass, length);
    output(mass, length);
    return 0;
}

