#include "stdio.h"
#include "locale.h"

int a[10000] = {0};

void set_ones(int i, int size, int n){
	if (n < size){
		a[n] = 1;
		set_ones(i, size, n+i);
	}
}

void rec_eratos(int i, int size){
	if (i*i < size){
		set_ones(i, size, i*i);
		rec_eratos(i+1, size);
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
