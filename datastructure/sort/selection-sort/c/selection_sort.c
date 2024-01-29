#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "random_array.h"

void selectionSort(int* arr, int n) {
	for(int i=0; i<n-1; ++i) {
		int min_idx = i;
		for(int j=i+1; j<n; ++j) {
			if(*(arr+j) < *(arr+min_idx)) {
				min_idx = j;
			}
		}

		int temp = *(arr+min_idx);
		*(arr+min_idx) = *(arr+i);
		*(arr+i) = temp;
	}
}

int main() {
	int n = 10;
	int range = 100;
	int* arr = (int*)malloc(n*sizeof(int));

	if(arr == NULL) {
		fprintf(stderr, "Memory allocation failed\n");
		return 1;
	}	

	fillRandom(arr, n , range);

	printf("Original array : \n");
	printArray(arr, n);

	selectionSort(arr, n);

	printf("Sorted array: \n");
	printArray(arr, n);

	free(arr);

	return 0;
}
