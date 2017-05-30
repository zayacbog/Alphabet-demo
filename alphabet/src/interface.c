#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void mes(int a, int b) {
	setlocale(LC_ALL, "Rus");
	if (a == 1){
		if (b == 0)
			printf("\t\t---Welcome to program Alphabet--\n");
		if (b == 1)
			printf("Input name of file to take string from:");
		if (b == 2)
			printf("Error: file is incorrect.\n");
		if (b == 3)
			printf("Error: string is incorrect.\n");
		if (b == 4)
			printf("The original string is:");
		if (b == 5)
			printf("\nNumber of words is:");
		if (b == 6)
			printf("Output of words one by one:");
	}
	if (a == 2){
		if (b == 0)
			printf("\t\t---Добро пожаловать в программу Алфавит---\n");
		if (b == 1)
			printf("Введите название файла для взятия строки:");
		if (b == 2)
			printf("Ошибка: некорректный файл.\n");
		if (b == 3)
			printf("Ошибка: некорректная строка.\n");
		if (b == 4)
			printf("Исходная строка:");
		if (b == 5)
			printf("\nКоличество слов:");
		if (b == 6)
			printf("Вывод слов по одному:");		
	}
}

int interact (char *string, int a) {
	int j = 0, size = 0;
	char namein[260];
	mes(a, 0);
	mes(a, 1);
	getchar();
	do{
		if (j > 260)
			return j;
		scanf("%c", &namein[j]);
		j++;
	} while (namein[j - 1]!='\n');
	namein[j-1] = '\0';
	FILE *fp = fopen (namein, "r");
	if(fp == NULL){
		mes(a, 2);
		return -1;
		}
	fscanf (fp, "%c", &string[0]);
	if ((string[0] == '\n') || (string[0] == ' ')){
		mes(a, 3);
		return -1;
		}
	j = 1;
    do{
		if (j >= 260){
			mes(a, 3);
			return -1;
		}
		fscanf (fp, "%c", &string[j]);
		if (string[j] == ' ')
			size++;
		j++;
	} while ((string[j - 1] != '\n') && (j < 260));
	string[j - 1] = '\0';
	mes(a, 4);
	printf("%s", string);
	fclose(fp);	
	return size;
}

void out (char *ptr[], int size, int a) {
	setlocale(LC_ALL, "Rus");
	int j = 0;
	mes(a, 5);
	printf("%d\n", size);
	mes(a, 6);
	for (j = 0; j < size; j++)
		printf("\n%s", ptr[j]);
}

int in() {
	int a;
	printf("Choose your interface language:\nType 1 for English.\nType 2 for Russian.\n");
	scanf("%d", &a);
	if ((a != 1) && (a != 2)){
    		printf("Wrong language input.");
    		return -1;
   	}
	return a;
}