/* Реализовать пузырьковую сортировку с использованием указателей */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 10
int main()
{
  int array[SIZE];
  srand(time(NULL));
  for (int i = 0; i < SIZE; i++)
  {
    array[i] = (rand() % 100) + 1;
    printf("Create: a[%d] = %d\n", i, array[i]);
  }
  printf("\n");
  bubble_sort(array);
  for (int i = 0; i < SIZE; i++)
    printf("Sort: a[%d] = %d\n", i, array[i]);
  return 0;
}
void bubble_sort(int *a)
{
  int i = 0, buf, swap = 0;
  while (i < SIZE) // метод пузырька
  {
    if (i + 1 != SIZE && a[i] > a[i + 1])  
    {
      buf = a[i];
      a[i] = a[i + 1];
      a[i + 1] = buf;
      swap = 1;
    }  
    i++;
    if (i == SIZE && swap == 1)
    {
      swap = 0;
      i = 0;
    }
  }
}
