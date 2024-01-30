#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "random_array.h"

void insertSort(int* arr, int n) {
	int	i, j, temp;
	for (i = 1; i < n; i++) {
		temp = *(arr + i);
		j = i-1;
		while (j >= 0) {
            if (*(arr+j) > temp) {
                *(arr+j+1) = *(arr+j);
                j--;
            } 
			else {
				break;
            }
        }
		*(arr+j+1) = temp;
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

	insertSort(arr, n);

	printf("Sorted array: \n");
	printArray(arr, n);

	free(arr);

	return 0;
}
