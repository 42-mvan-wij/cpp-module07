#include <iostream>
#include "whatever.hpp"

__attribute__((destructor))
void check_leaks() {
	std::cout << std::endl;
	system("leaks -q whatever");
}

int main() {
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	assert(::min(a, b) == b);

	int e = 1;
	int f = 1;
	int &g = ::min(e, f);
	std::cout << "e: " << &e << std::endl;
	std::cout << "f: " << &f << std::endl;
	std::cout << "g: " << &g << std::endl;
	assert(&::min(e, f) == &f);
	assert(&::max(e, f) == &f);

	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;

	return (0);
}
