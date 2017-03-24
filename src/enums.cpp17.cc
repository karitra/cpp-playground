#include <iostream>
#include <vector>

using namespace std;

int
main()
{
	enum Boo {
		SOME_FLD
	};

	enum class Zoo : unsigned char {
		OTHER_FLD
	}; 

	const auto b = Boo{Boo::SOME_FLD};
	const auto z = Zoo{Zoo::OTHER_FLD};

	std::vector<Zoo> zv;
	std::vector<Boo> bv;

	cerr << zv.size() << '\n';
	cerr << bv.size() << '\n';

	cerr << "sizeof(Zoo) " << sizeof(Zoo) << '\n';
	cerr << "sizeof(Boo) " << sizeof(Boo) << '\n';

    //cerr << "b = " << b << '\n';
	//cerr << "z = " << z << '\n';
}
