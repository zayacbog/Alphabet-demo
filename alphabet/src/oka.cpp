#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void exchange (char *ptr[], int j) {
	char *chtmp;
	char *chtmp2;
	chtmp2 = ptr[j + 1];
	chtmp = ptr[j];
	ptr[j + 1] = chtmp;
	ptr[j] = chtmp2;			
}

int schr(char str[],char ch) {
	int i;
	int idx = -1;
	for(i = 0;(str[i] != '\0') && (str[i] != ch);i++);
		if(str[i] == ch)
		idx = i;
	return idx;
}

int stok(char str[], char *ptr[]) {
	char *suf = str;
	ptr[0] = str; 
	int i, j = 1; 
	char delim = ' ';
	while((i = schr(suf, delim)) >= 0){
		suf[i] = '\0';
		suf = suf + i + 1;
		ptr[j] =  suf;
		j++;
	}
	return j;
}

void crop(char string[], char *fstring) {
	int j = 0, i = 0;
	while (string[j] != '\0'){
		if ((string[j] >= 'А' && string[j] <= 'Б') || (string[j] >= 'а' && string[j] <= 'п') || (string[j] >= 'р' && string[j] <= 'я') || string[j]==' '){
			fstring[i] = string[j];
			i++;
		}
		if ((string[j] >= 'A' && string[j] <= 'Z') || (string[j] >= 'a' && string[j] <= 'z')){
			fstring[i] = string[j];
			i++;
		}
		j++;
	}
	fstring[i] = '\0';
}

void sort(char *ptr[], int size) {
	char *mstmp;
	char *mstmp2;
	char A[] = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
	char a[] = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
	char B[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ       ";
	char b[] = "abcdefghijklmnopqrstuvwxyz       ";
	int i = 0, j = 0, k = 0;
	int x = -1, y = -1;
	for (i = 0; i < (size - 1); ++i){
		for(j = 0; j < (size - 1); ++j){
			mstmp = ptr[j];
			mstmp2 = ptr[j + 1];
			
			for(k = 0; k < 33; k++){
				if ((mstmp[0] == A[k]) || (mstmp[0] == a[k]))
					x = k;
				if ((mstmp2[0] == A[k]) || (mstmp2[0] == a[k]))
					y = k;	
				if ((mstmp[0] == B[k]) || (mstmp[0] == b[k]))
					x = k;
				if ((mstmp2[0] == B[k]) || (mstmp2[0] == b[k]))
					y = k;
			}
				if (y < x)
					exchange(ptr, j);		
		}
	}
}

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

}
}

int main() {	
    int b = 0, a = 0;
    char string[260];
    char fstring[260];
    a = in();
    if (a == -1)
    	return -1;
    b = interact(string, a) + 1;
	if (b == 0)
		return 0;
	char *ptr[b];
	crop(string, fstring);
	stok(fstring, ptr);
	sort(ptr, b);
	out(ptr, b, a);
	getchar();
	getchar();
    return 0;
}
