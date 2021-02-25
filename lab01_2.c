#include "stdio.h"
#include "locale.h"

int a[10000] = {0};

int rec_eratos(int i, int size){
	if (i*i < size){
		for (int n = i*i; n<size; n += i){
			a[n] = 1;
		}
		return rec_eratos(i+1, size);
	} 
	else {
		return 0;
	}
}

int main(int argc, char** argv){
	setlocale(LC_ALL, "russian");
	int size;
	int n = 2;
	printf("Введите число, до которого нужно найти простые числа: ");
	scanf("%d", &size);
	if (size < 2){
		printf("Простых чисел нет");
		return 0;
	}
	rec_eratos(n, size);
	printf("Простые числа: ");
	for (int i = n; i<size; i++){
		if (a[i] == 0){
			printf("%d ", i);    
		}
	}
	return 0;
}
