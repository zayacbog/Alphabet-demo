#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

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