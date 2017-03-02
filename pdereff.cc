//
// Conclusion: complete elision of pointer dereferencing at GCC -O2 level 
//
#include <cstdlib>
#include <memory>

using namespace std;

struct Foo {

	void inc(int to_add) { z += to_add; }
	void inc(const double f) { x += f; }
	
	double x = 0.123;
	int z = 125;
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

	A a, b;

	auto &a_ref = a.some_data.uptr;
	auto &b_ref = b.some_data.uptr;

	//
	// Resulting assambler for following two C lines:
	// 
   	//  4:	bb 1e 05 00 00       	mov    ebx,0x51e
	// ...
	// 1d:	8d 5c 5b 7d          	lea    ebx,[rbx+rbx*2+0x7d]
	//
	a.some_data.uptr->inc(add);
	a.some_data.uptr->inc(add);
	a_ref->inc(add);

	b.some_data.uptr->inc(add + 1.0 * add);	
 	b_ref->inc(add - 2.0 * add);
 
	return a.some_data.uptr->z + b_ref->x;
}

