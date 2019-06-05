#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define COMMAND_SIZE 30
#define ADD 30
#define SUB 31
#define GOTO 40
#define LOAD 20
#define DIV 32
#define INPUT 10
#define OUTPUT 11
#define STORE 21
#define NEG_GOTO 41
#define ZERO_GOTO 42
#define HALT 43
#define help printf("help - помощь\nrun - выполнить\nclear - очистить экран\nexit - выйти из shell\n")
#define COMMAND_LENGTH 100

int *ram;
char line[COMMAND_SIZE];
int command;
int argument;
int result;
int acc = 0;
int i = 0, j = 0, i_start = 0, i_end = 1, i_menu = 0;

char button();
void intrpr(char*,int*, int*);
int alu(int,int,int*,int*,FILE **);
void computer();
void run();
void intrpr();
void logo();
void menu();
void output_menu();
int joy_menu(int *);
void display();
char button();
int alu(int command,int argument,int *acc, int *ram,FILE **prog)
{
				switch(command){
				case ADD:
					*acc += ram[argument];
				break;
				case GOTO:
					fseek(*prog,argument,SEEK_SET);
					break;
				case LOAD:
					*acc = ram[argument];
					break;
				case SUB:
					*acc -= ram[argument];
					break;
				case DIV:
					*acc /= ram[argument];
					break;
				case INPUT:
					scanf("%d", &ram[argument]);
					break;
				case OUTPUT:
					printf("%d\n",*acc);
					break;
				case STORE:
					ram[argument] = *acc;
					break;
				case NEG_GOTO:
					if(*acc < 0)
					fseek(*prog,argument,SEEK_SET);
					break;
				case ZERO_GOTO:
					if(*acc == 0)
					fseek(*prog,argument,SEEK_SET);
					break;
				case HALT:
					return 1;
					break;
				}
			return 0;
}
void computer(char *filename)
{ 
	 int *ram;
	 char line[COMMAND_SIZE];
	 int command;
	 int argument;
	 int result;
	 ram=(int*)calloc(100,sizeof(int));
	 int acc = 0;
	 FILE *prog;
	  if((prog = fopen(filename,"r")) == NULL){
	 printf("ERROR!\n");
	 }
	 while(fgets(line,COMMAND_SIZE,prog) != NULL){
		 
		 intrpr(line,&command,&argument);
		 result = alu(command,argument,&acc,ram,&prog);
		 if(result)
			break;
	 }
	 
}
void run()
{
	char ex[2][30] = {"exit", "help"};
	printf("shell:> ");
	char command[COMMAND_LENGTH];
    while(fgets(command,COMMAND_LENGTH,stdin) != NULL){
      	char *h=strchr(command,'\n');
      	*h = '\0';
		command[COMMAND_LENGTH-1] = '\0';
	   	if(!strncmp(command,"run ",4)) {
			computer(strchr(command,' ')+1);
			continue;
		} else if(strcmp(ex[0],command) == 0) {
			exit(1);
		} else if (strcmp(ex[1],command) == 0) {
			help;
		}
	  	printf("shell:> ");
      	system(command);
    }
}
void intrpr(char *line,int *command, int *argument)
{
			char comm[COMMAND_SIZE];
			char arg[COMMAND_SIZE];
			int i;
			for(i = 0; line[i] != ' ' && line[i] != '\n';i++)
				comm[i] = line[i];
			comm[i] = '\0';
			if(!strcmp(comm,"ADD"))
				*command = ADD;
			else if(!strcmp(comm,"SUB"))
				*command = SUB;
			else if(!strcmp(comm,"GOTO"))
				*command = GOTO;
			else if(!strcmp(comm,"LOAD"))
				*command = LOAD;
			else if(!strcmp(comm,"DIV"))
				*command = DIV;
			else if(!strcmp(comm,"INPUT"))
				*command = INPUT;
			else if(!strcmp(comm,"OUTPUT"))
				*command = OUTPUT;
			else if(!strcmp(comm,"STORE"))
				*command = STORE;
			else if(!strcmp(comm,"NEG_GOTO"))
				*command = NEG_GOTO;
			else if(!strcmp(comm,"ZERO_GOTO"))
				*command = ZERO_GOTO;
			else if(!strcmp(comm,"HALT"))
				*command = HALT;
			else
				*command = atoi(comm);
			for(; i != EOF && i != '\n';i++)
				arg[i] = line[i];
			*argument = atoi(arg);
}
void logo()
{
	display();
	printf("\t\tCOMPUTER\n\t\tMenu:\n");
}
void menu()
{
			int flag = 1;
			while (flag == 1) 
			{
				logo();
				output_menu(i_menu);
				joy_menu(&flag);
			}
			if (i_menu == 0) { 
				display();
				printf("Чтобы получить подсказку о командах, воспользуйтесь help\n");
				run();
			}
			if (i_menu == 2)
				exit(1);
}
void output_menu(int kursor)
{
	if (kursor == 0) 
		printf("\t\t[*] - Командная строка\n\t\t - Выход\n");
	if (kursor == 1) 
		printf("\t\t - Командная строка\n\t\t[*] - Выход\n");
}
int joy_menu(int *flag)
{
	char select;
	select = button();
	switch(select)
	{
		case 13:
		{
			display();
			*flag = 0;
			return i_menu;
		}
		case 56: // вверх
		{
			if (i_menu == i_start) {
				i_menu = i_end;
				//output_menu(i);
				display();
				return i_menu;
			} 
			if (i_menu > i_start) {
				i_menu--;
				//output_menu(i);
				display();
				return i_menu;
			}
		}
		case 50: // вниз
		{
			if (i_menu == i_end) {
				i_menu = i_start;
				//output_menu(i);
				display();
				return i_menu;
			} else {
				i_menu++;
				//output_menu(i);
				display();
				return i_menu;
			}
		}
		default: 
		{
			display();
		}
	}
}
void display()
{
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}
char button()
{
    char select;
    #if _WIN32
        select = getch();
    #else
        system("stty raw");
        select = getchar();
        system("stty cooked");
    #endif
    return select;
}
int main()
{
			ram=(int*)calloc(100,sizeof(int));
			menu();
			FILE *prog;
			if((prog = fopen("program.txt","r")) == NULL)
				return -1;
			while(fgets(line,COMMAND_SIZE,prog) != NULL){
				intrpr(line,&command,&argument);
				result = alu(command,argument,&acc,ram,&prog);
				if(result)
					break;
			}
			return 0;
}