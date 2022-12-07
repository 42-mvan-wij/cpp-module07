#include <iostream>
#include <cstdlib>
#include <cassert>
#include "whatever.hpp"

void check_leaks() {
	std::cout << std::endl;
	std::system("leaks -q whatever");
}

int main() {
	std::atexit(&check_leaks);

	int a = 2;
	int b = 3;

	std::cout << "a = " << a << ", b = " << b << std::endl;
	::swap( a, b );
	std::cout << "swap( a, b ) -> a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::cout << "&a = " << &a << std::endl;
	std::cout << "&b = " << &b << std::endl;
	std::cout << "&min( a, b ) = " << &::min( a, b ) << std::endl;
	std::cout << "&max( a, b ) = " << &::max( a, b ) << std::endl;
	assert(&::min(a, b) == &b);
	assert(&::max(a, b) == &a);

	int e = 1;
	int f = 1;
	std::cout << "e: " << e << std::endl;
	std::cout << "f: " << f << std::endl;
	std::cout << "&g = min(e, f)" << std::endl;
	int &g = ::min(e, f);
	std::cout << "&e: " << &e << std::endl;
	std::cout << "&f: " << &f << std::endl;
	std::cout << "&g: " << &g << std::endl;
	assert(&::min(e, f) == &f);
	assert(&::max(e, f) == &f);

	std::string c = "hello1";
	std::string d = "hello2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;

	return (0);
}
