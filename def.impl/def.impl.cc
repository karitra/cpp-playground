#include <iostream>

#include "def.impl.h"
#include "def.impl.goo.h"

using namespace std;

struct BooZoo : Boo {
	using Boo::foo;

	void foo(int z) override {
		cerr << "BooZoo::foo(int)\n";
	};

	// void foo(double z) override {
	//	cerr << "BooZoo::foo(double)\n";
	// }
};

int main(int argc, char *argv[]) {
	BooZoo bz;
	GooBoo gb;

	bz.foo(100500);
	bz.foo(100.500);

	gb.foo(100.500);
}

