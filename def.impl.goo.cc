#include "def.impl.goo.h"

void GooBoo::foo(double) {
	Boo::foo(100.500);
	std::cerr << "GooMoo::foo(double)\n";
}

