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

struct B 
{
	B(A a) : local(std::move(a)) {}
	A local;
};

int foo(A a) {
	cerr << "foo: a.z = " << a.z << '\n';
	return a.z;
}

B boo() {
	A a(100500);
	a.z++;

	// return B(std::move(a));
	return B(a);
}

int main()
{
	//A b(1310);
	//foo(A(100500));
	const auto b = boo();

	cerr << "b.z " << b.local.z << '\n';
}

