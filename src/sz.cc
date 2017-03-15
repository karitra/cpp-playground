#include <iostream>
#include <cstdlib>

using namespace std;

template<class Z>
size_t 
foo(Z &&z) {
	return sizeof(z);
}


int
main(int argc, char *argv[])
{
	auto a1 = "some string ab";
	const auto a2 = "some string ab";
	auto &a3 = "some string ab";
	const auto &a4 = "some string ab";

	cout << "sizeof(a1): " << sizeof(a1) << '\n';
	cout << "sizeof(a2): " << sizeof(a2) << '\n';
	cout << "sizeof(a3): " << sizeof(a3) << '\n';
	cout << "sizeof(a4): " << sizeof(a4) << '\n';

	cout << "ret sizeof(a4): " << foo(a4) << '\n';
	cout << "ret sizeof(some str): " <<  foo("some string ab") << '\n';

	return EXIT_SUCCESS;
}

