//
// Conclusion: complete elision of pointer dereferencing at GCC -O2 level 
//
#include <cstdlib>
#include <memory>

using namespace std;

struct Foo {
	
	void inc(int to_add) { z += to_add; }
	
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

	A a;

	auto &ref = a.some_data.uptr;

	//
	// Resulting assambler for following code:
	// 
   	//  4:	bb 1e 05 00 00       	mov    ebx,0x51e
	// ...
	// 1d:	8d 5c 5b 7d          	lea    ebx,[rbx+rbx*2+0x7d]
	//
	a.some_data.uptr->inc(add);
	a.some_data.uptr->inc(add);
	
	ref->inc(add);
 
	return a.some_data.uptr->z;
}

