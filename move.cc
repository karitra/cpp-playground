#include<iostream>

using namespace std;

struct A {
	A(int zz) : z(zz) {
		cerr << "A ctor\n";
	}

	A(const A &other) {
		cerr << "A copy\n"; 
	}

	A(A &&other) {
		cerr << "A move\n";
	}

	virtual ~A() {
		cerr << "A dtor\n";
	}

	int z;
};


void foo(A a) {
	cerr << "foo: a.z = " << a.z << '\n';
}

int main()
{
	//A b(1310);
	foo(A(100500));
	//foo(move(b));
}

