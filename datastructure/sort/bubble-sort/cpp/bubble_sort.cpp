#include "random_array.hpp"
#include <iostream>
#include <vector>

void bubbleSort(std::vector<int>& arr) {
	for(size_t i=0; i<arr.size()-1; ++i) {
		for(size_t j=arr.size()-1; j>i; --j) {
			if(*(arr.data()+j) < *(arr.data()+j-1)) {
				std::swap(*(arr.data()+j), *(arr.data()+j-1));
			}
		}
	}
}

int main() {
	int n = 10;
	int range = 100;
	std::vector<int> arr(n);

	fillRandom(arr, range);

	std::cout << "Original array : \n";
	printArray(arr);

	bubbleSort(arr);

	std::cout << "Sorted array: \n";
	printArray(arr);

	return 0;
}
