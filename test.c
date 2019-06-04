#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#ifdef _WIN32
    #include<conio.h>
    #include<windows.h>
#endif
void display()
{
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}
int main()
{
    char user[100] = "Admin", pass[100], log_pass[100];
    FILE *auth = fopen("auth.txt", "r+");
    while(!feof(auth)) fscanf(auth, "%s\n", pass);
	fclose(auth);
    if (pass[0] == '\n') { 
        printf("ERROR\n");
        sleep(2);
        return 0;
    }
    int flag = 1;
    printf("%s\n", pass);
    while (flag)
    {
        display();
        printf("\t\tЗдравствуйте, %s\n\t\tВведите свой пароль и для подтверждения нажмите [ENTER]: \n", user);
        scanf("%s", log_pass);
        if (strcmp(log_pass, pass) == 0) {
            printf("Вы успешно авторизовались!\n");
            sleep(2);
            flag = 0;
        }
    }
    return 0;
}
