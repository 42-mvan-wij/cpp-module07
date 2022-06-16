#include <iostream>
#include "iter.hpp"

__attribute__((destructor))
void check_leaks() {
	std::cout << std::endl;
	system("leaks -q iter");
}

void f_int(int &element) {
	element += 2;
}

void f_double(double &element) {
	element /= 2.0;
}

void print_int(int &element) {
	std::cout << element << ", ";
}

void print_double(double &element) {
	std::cout << element << ", ";
}

int main() {
	{
		int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

		iter(arr, sizeof(arr) / sizeof(arr[0]), print_int);
		std::cout << std::endl;

		iter(arr, sizeof(arr) / sizeof(arr[0]), f_int);

		iter(arr, sizeof(arr) / sizeof(arr[0]), print_int);
		std::cout << std::endl;
	}

	std::cout << std::endl;

	{
		double arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

		iter(arr, sizeof(arr) / sizeof(arr[0]), print_double);
		std::cout << std::endl;

		iter(arr, sizeof(arr) / sizeof(arr[0]), f_double);

		iter(arr, sizeof(arr) / sizeof(arr[0]), print_double);
		std::cout << std::endl;
	}

	return (0);
}
