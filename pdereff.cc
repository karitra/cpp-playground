#include <iostream>
#include <memory>

#include <string> 

using namespace std;

struct Foo {
	
	void inc(int to_add) { z += to_add; }
	
	int z;
};

struct A {

	A() { 
		some_data.uptr.reset(new Foo());
	}


	struct {
		unique_ptr<Foo> uptr;
	} some_data;
}; 

int main(int argc, char **argv)
{
	auto add = (argc > 1) ? stoi(argv[1]) : 1310;

	A a;
	auto i = long{};

	auto &ref = a.some_data.uptr;
	
	// test st
	i += 11;

	a.some_data.uptr->inc(add);
	ref->inc(add);
 
	std::cerr << "z = " <<  ref->z << '\n';
	std::cerr << "i = " <<  i << '\n';

	return 0;
}

