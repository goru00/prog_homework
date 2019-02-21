#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 10
void sort();
void mass();
void bubble();
void asc();
void desc();
void bubble(int *sort_m, int pointer)
{
  if (pointer == 1)
    printf("Выбрано направление сортировки По возрастанию.\n");
  else printf("Выбрано направление сортировки По убыванию.\n");
}
void asc(int *sort_m, int pointer)
{
  int i = 0, buf, swap = 0;
  while (i < SIZE) // метод пузырька по возрастанию
  {
    if (i + 1 != SIZE && *(sort_m+i) > *(sort_m+i+1))  
    {
      buf = *(sort_m+i);
      *(sort_m+i) = *(sort_m+i+1);
      *(sort_m+i+1) = buf;
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
void desc(int *sort_m, int pointer)
{
  int i = 0, buf, swap = 0;
  while (i < SIZE) // метод пузырька по убыванию
  {
    if (i + 1 != SIZE && *(sort_m+i) < *(sort_m+i+1))  
    {
      buf = *(sort_m+i);
      *(sort_m+i) = *(sort_m+i + 1);
      *(sort_m+i + 1) = buf;
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
void mass(int *arr)
{
  for (int i = 0; i < SIZE; i++)
  {
    arr[i] = (rand() % 100) + 1;
    printf("Create: a[%d] = %d\n", i, arr[i]);
  }
}
void sort(int *arr)
{
  for (int i = 0; i < SIZE; i++)
    printf("Sort: a[%d] = %d\n", i, arr[i]);
}
int main()
{
  int array[SIZE];
  mass(array);
  int (*a[2])(int *) = {asc, desc};
  int d;
  printf("Выберете направление сортировки: 1 - По возрастанию. 2 - По убыванию : "); scanf("%d", &d);
  bubble((*a[d - 1])(array), d);
  sort(array);
  return 0;
}
