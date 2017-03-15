#include <iostream>

#include <boost/current_function.hpp>

struct A {
	void boo() {
		std::cerr << "I'm here -> " << BOOST_CURRENT_FUNCTION << '\n';
	}
};

int main()
{
	A a;
	a.boo();
}

