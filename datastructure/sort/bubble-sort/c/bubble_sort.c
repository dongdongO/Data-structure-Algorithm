#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "random_array.h"

void bubbleSort(int* arr, int n) {
    for(int i=0; i<n; ++i) {
        for(int j=n-1; j>i; --j) {
            if(*(arr+j) < *(arr+j-1)) {
                int temp = *(arr+j);
                *(arr+j) = *(arr+j-1);
                *(arr+j-1) = temp;
            }
        }
    }
}

int main() {
    int n = 10;
    int range = 100;
    int* arr = (int*)malloc(n*sizeof(int));

    if(arr==NULL) {
        fprintf(stderr, "Memmory allocation failed\n");
        return 1;
    }

    fillRandom(arr, n, range);

    printf("Original array : \n");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    free(arr);

    return 0;
}