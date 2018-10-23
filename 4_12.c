#include<stdio.h>

int main()
{
  int i;
  for (i = 32; i<=124; i++)
    { 
      printf("%3d  %c ", i, i);
      if (i%6 == 0) printf("\n");
    }
  printf("\n");
  return 0;
}
