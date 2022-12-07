#include <iostream>
#include <cstdlib>
#include "iter.hpp"

void check_leaks() {
	std::cout << std::endl;
	std::system("leaks -q iter");
}

void f_int(int &element) {
	element += 2;
}

void f_double(double &element) {
	element /= 2.0;
}

void print_int(int const &element) {
	std::cout << element << ", ";
}

void print_double(double const &element) {
	std::cout << element << ", ";
}

int main() {
	std::atexit(&check_leaks);

	{
		int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

		iter(arr, sizeof(arr) / sizeof(*arr), print_int);
		std::cout << std::endl;

		iter(arr, sizeof(arr) / sizeof(*arr), f_int);

		iter(arr, sizeof(arr) / sizeof(*arr), print_int);
		std::cout << std::endl;
	}

	std::cout << std::endl;

	{
		double arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

		iter(arr, sizeof(arr) / sizeof(*arr), print_double);
		std::cout << std::endl;

		iter(arr, sizeof(arr) / sizeof(*arr), f_double);

		iter(arr, sizeof(arr) / sizeof(*arr), print_double);
		std::cout << std::endl;
	}

	{
		const double arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

		iter(arr, sizeof(arr) / sizeof(*arr), print_double);
		std::cout << std::endl;

		// iter(arr, sizeof(arr) / sizeof(*arr), f_double);

		iter(arr, sizeof(arr) / sizeof(*arr), print_double);
		std::cout << std::endl;
	}

	return (0);
}
