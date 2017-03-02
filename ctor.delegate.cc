#include <iostream>
#include <vector>

using namespace std;

struct A {

	/*
	A() : A(10) {
		cerr << "ctor A()\n";
	}
	*/

	A() = default;

	A(int x) : A(x, 0) {
		cerr << "ctor A(int)\n";
	}

	A(int x, double y) : x{x}, y{y} {
		cerr << "ctor A(int, double)\n";
	}

	int x;
	double y;
};

int main(int argc, char *argv[])
{
	A a;
	
	std::vector<A> v;
	v.emplace_back(100, 500.0);

	cerr << "x = " << a.x << ' ' 
	     << "y = " << a.y << '\n';
}

