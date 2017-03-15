#include <iostream>
#include <typeinfo>

using namespace std;


namespace a {
	namespace b {
		struct Boo {
			int z;
			void mem() {}
		};
	}	
}

int main()
{
	// a::b::Boo b;
	
	cout << "typeid: " <<  typeid(a::b::Boo).name() << '\n';
	return 0;
}

