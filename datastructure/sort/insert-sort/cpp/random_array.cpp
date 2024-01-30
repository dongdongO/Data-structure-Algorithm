#include "random_array.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

void fillRandom(std::vector<int>& arr, int range) {
	srand(static_cast<unsigned int>(time(nullptr)));
	for(auto& element : arr) {
		element = rand()%range;
	}
}

void printArray(const std::vector<int>& arr) {
	for(const auto& element : arr) {
		std::cout << element << " ";
	}
	std::cout << std::endl;
}
