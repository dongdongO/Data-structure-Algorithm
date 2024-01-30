#include "random_array.hpp"
#include <iostream>
#include <vector>

void insertSort(std::vector<int>& arr) {
	for(size_t i=1; i<arr.size(); ++i) {
		int temp = *(arr.data()+i);
		int j = i-1;

		while(j>=0) {
			if(*(arr.data()+j)>temp) {
				*(arr.data()+j+1) = *(arr.data()+j);
				j--;
			}
			else {
				break;
			}
		}
		*(arr.data()+j+1) = temp;
	}
}

int main() {
	int n = 10;
	int range = 100;
	std::vector<int> arr(n);

	fillRandom(arr, range);

	std::cout << "Original array : \n";
	printArray(arr);

	insertSort(arr);

	std::cout << "Sorted array: \n";
	printArray(arr);

	return 0;
}
