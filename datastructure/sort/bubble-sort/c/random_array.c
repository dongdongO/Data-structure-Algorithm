#include "random_array.h"
#include <stdio.h>

void fillRandom(int* arr, int size, int range) {
	srand((unsigned int)time(NULL));

	for(int i=0; i<size; ++i) {
		*(arr+i) = rand()%range;
	}
}

void printArray(const int* arr, int size) {
	for(int i=0; i<size; ++i) {
		printf("%d ", *(arr+i));
	}
	printf("\n");
}
