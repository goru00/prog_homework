#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
  printf("Нажмите кнопку\n"); 

  // Set terminal to raw mode 
  system("stty raw"); 

  // Wait for single character 
  char input = getchar(); 

  // Echo input
  while (input != 106)
  {
  	printf("OK!\n");
  }

  // Reset terminal to normal "cooked" mode 
  system("stty cooked"); 

  // And we're out of here 
  return 0; 
	return 0;
}