#include <cstdlib>
#include <memory>

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
	auto add = (argc > 1) ? atoi(argv[1]) : 1310;

	A a;

	auto &ref = a.some_data.uptr;

	a.some_data.uptr->inc(add);
	ref->inc(add);
 
	return a.some_data.uptr->z;
}

