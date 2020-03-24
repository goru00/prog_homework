#include <iostream>
#include <ctime>
using namespace std;
void merge(int[], int, int[], int, int[], int);
void mergeSort(int mass[], int length)
{
    int middle = length / 2;
    int temp = length - middle;
    int* firsttemp = new int[length];
    int* endtemp = new int[middle];
    for (int i = 0; i < length; i++)
    {
        if (i < middle)
            firsttemp[i] = mass[i];
        else endtemp[i - middle] = mass[i];
    }
    mergeSort(firsttemp, middle);
    mergeSort(endtemp, temp);
    merge(mass, length, firsttemp, middle, endtemp, temp);
}

void merge(int mass[], int length, int firsttemp[], int middle, int endtemp[], int temp)
{
    int i = 0, j = 0;
    while (i < length || j < length)
    {
        if (i < length && j < length)
        {
            if (firsttemp[i] <= endtemp[j]) {
                mass[i + j] = firsttemp[i];
                i++;
            }
            else {
                mass[i + j] = endtemp[j];
                j++;
            }
        }
        else if (i < length) {
            mass[i + j] = firsttemp[i];
            i++;
        }
        else if (j < length) {
            mass[i + j] = endtemp[j];
            j++;
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
    mergeSort(mass, length);
    output(mass, length);
    return 0;
}
