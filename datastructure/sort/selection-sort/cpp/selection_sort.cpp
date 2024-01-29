#include "random_array.hpp"
#include <iostream>
#include <vector>


void selectionSort(std::vector<int>& arr) {
	for(size_t i=0; i<arr.size()-1; ++i) {
		size_t min_idx = i;
		for(size_t j=i+1; j<arr.size(); ++j) {
			if(*(arr.data()+j) < *(arr.data()+min_idx)) 
				min_idx = j;
		}
		std::swap(*(arr.data()+i), *(arr.data()+min_idx));
	}
}

int main() {
	int n = 10;
	int range = 100;
	std::vector<int> arr(n);

	fillRandom(arr, range);

	std::cout << "Original array : \n";
	printArray(arr);

	selectionSort(arr);

	std::cout << "Sorted array: \n";
	printArray(arr);

	return 0;
}
