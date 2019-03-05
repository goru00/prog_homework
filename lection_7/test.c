#include<stdio.h>


void visual(int[][13]);
void sort(int[][13]);
void multisort(int[][13], int);
int main()
{
  int arr[4][13];
  int i, j, k=1;
  for(i=0;i<4;i++)
    for(j=0;j<13;j++)
      arr[i][j]=k++;
  visual(arr);
  printf("\n----------------------------------------------\n");
  multisort(arr,100);
  visual(arr);
  return 0;
}

void visual(int arr[4][13])
{
  int i,j,k;
  for(k=1; k<53; k++)
  for(i = 0; i<4; i++)
    for(j = 0; j< 13; j++)
      if(arr[i][j]==k){
	if(i==0) printf("Черви ");
	if(i==1) printf("Бубны ");
	if(i==2) printf("Трефы ");
	if(i==3) printf("Пики ");
	if(j==0) printf("Туз \n");
	if(j==1) printf("Двойка \n");
	if(j==2) printf("Тройка \n");
	if(j==3) printf("Четверка  \n");
	if(j==4) printf("Пятерка \n");
	if(j==5) printf("Шестерка \n");
	if(j==6) printf("Семерка \n");
	if(j==7) printf("Восьмерка \n");
	if(j==8) printf("Девятка \n");
	if(j==9) printf("Десятка \n");
	if(j==10) printf("Валет \n");
	if(j==11) printf("Дама \n");
	if(j==12) printf("Король \n");
	break;
      }
}
void sort(int arr[4][13]) {
  int i,j,k,m,g;
  for (i=0; i<4; i++)
    for(j=0; j<13; j++) {
      k=rand()%4;
      m=rand()%13;
      g=arr[i][j];
      arr[i][j]=arr[k][m];
      arr[k][m]=g;
    }
}
void multisort(int arr[4][13], int N) {
  srand(time(NULL));
  int i;
  for(i=1; i<=N; i++) {
    sort(arr);
  }
}
