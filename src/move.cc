#include <iostream>
#include <map>

using namespace std;

struct A {
	A(int zz) : z(zz) {
		cerr << "A ctor: " << zz << '\n';
	}

	A(const A &other) {
		cerr << "A copy\n"; 
	}

	A(A &&other) {
		cerr << "A move\n";
	}
	
    A(const A &&other) {
		cerr << "A const move\n";
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

    std::map<int, A> am = {
        {1, {100}},
        {2, {200}},
        {3, {300}}
    };

    cerr << "move iterators:\n";
    std::map<int, A> am1;
    
    for(auto it = std::begin(am); it != std::end(am); ++it) {
        am1.emplace(std::move(*it));
    }

    cerr << "clear am\n";
    am.clear();
    cerr << "clear am: done\n";
}

