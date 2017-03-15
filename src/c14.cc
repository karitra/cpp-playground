#include <iostream>
#include <algorithm>

#include <boost/assign.hpp>

using namespace std;
using namespace boost::assign;

int main() {
	
	std::vector<int> a;
        a += 1,2,3,4;

	for_each(begin(a), end(a), [] (const auto &z) -> void {
		std::cerr << z << '\n';
	});
}

