#include <algorithm>
#include <forward_list>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <memory>
#include <iterator>

using namespace std;

struct Pod1 {

	Pod1(int a, int b) : a{a}, b{b} {
		cerr << "Pod1::ctor " << a << ", " << b << "\n"; 
	}

	~Pod1() { cerr << "Pod1::dtor\n"; }
	
	int a;
	int b;
};

int
main()
{	
	std::list<std::shared_ptr<Pod1>> li;
	std::map<int, decltype(li)::iterator> m;

	for(const auto &el : {1,2,3,4,5,6,7,8,9}) {
		li.emplace_back(std::make_shared<Pod1>(el, el*el));
	}

	auto it = std::begin(li);

	while(it != std::end(li)) {
		m[ (*it)->a ] = it;
		++it;
	}

	cerr << "li clear start\n";
	li.clear();
	cerr << "li clear done\n";
}

