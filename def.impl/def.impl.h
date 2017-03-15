#pragma once

#include <stdexcept>

struct Boo {
	virtual void foo(int a) = 0;
	virtual void foo(double z);
	
	//virtual void foo(double z) {
	//	std::cerr << "Boo::foo(double)\n";
 	//}
};

void
Boo::foo(double z) {
	std::cerr << "Boo::foo(double)\n";
	// throw std::runtime_error("not implemented");
}


