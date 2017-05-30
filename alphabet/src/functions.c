#include <stdio.h>
#include <stdlib.h>

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
		if ((string[j] >= 'À' && string[j] <= 'ß') || (string[j] >= 'à' && string[j] <= 'ï') || (string[j] >= 'ð' && string[j] <= 'ÿ') || string[j]==' '){
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
	char A[] = "ÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖ×ØÙÚÛÜÝÞß";
	char a[] = "àáâãäå¸æçèéêëìíîïðñòóôõö÷øùúûüýþÿ";
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
