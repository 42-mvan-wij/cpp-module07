#include <iostream>
#include <cstdlib>
#include "Array.hpp"

void check_leaks() {
	std::cout << std::endl;
	std::system("leaks -q array");
}


#define MAX_VAL 750
int main(int, char**)
{
	std::atexit(&check_leaks);

	srand(time(NULL));

	Array<int> numbers(MAX_VAL);
	std::cout << "numbers.size(): " << numbers.size() << std::endl;
	int* mirror = new int[MAX_VAL];

	std::cout << "filling numbers and mirror with random values (the same for both)" << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}

	std::cout << std::endl;

	{
		Array<int> assign_copy = numbers;
		Array<int> constructor_copy(assign_copy);

		std::cout << "assign_copy[3] += 314" << std::endl;
		assign_copy[3] += 314;
		std::cout << "numbers[3]: " << numbers[3] << std::endl;
		std::cout << "assign_copy[3]: " << assign_copy[3] << std::endl;
		std::cout << "constructor_copy[3]: " << constructor_copy[3] << std::endl;

		std::cout << std::endl;

		std::cout << "constructor_copy[9] -= 314" << std::endl;
		constructor_copy[9] -= 314;
		std::cout << "numbers[9]: " << numbers[9] << std::endl;
		std::cout << "assign_copy[9]: " << assign_copy[9] << std::endl;
		std::cout << "constructor_copy[9]: " << constructor_copy[9] << std::endl;

		std::cout << std::endl;

		Array<int> no_constructor_arg;
		std::cout << "no_constructor_arg.size(): " << no_constructor_arg.size() << std::endl;
	}

	std::cout << std::endl;

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	std::cout << "numbers and mirror are the same" << std::endl;

	try
	{
		std::cout << "trying: numbers[-2] = 0" << std::endl;
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Caught exception: " << e.what() << '\n';
	}

	std::cout << std::endl;

	try
	{
		std::cout << "trying: numbers[MAX_VAL] = 0" << std::endl;
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Caught exception: " << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}

	delete[] mirror;
	return 0;
}
