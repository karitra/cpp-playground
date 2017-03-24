#include <iostream>
#include <map>

using namespace std;

struct Boo {
	enum Selector { Key, Value };
};

int
main() 
{
	map<int,string> m = { {1, "hello"}, {2, "bye-bye"} };
	enum Selector { Key, Value };
	
	for(const auto &kv : m) {
		int k;
		std::string v;
	
		tie(k,v) = kv;

		cerr
			<< " k: " << std::get<Selector::Key>(kv) 
			<< " v: " << std::get<Selector::Value>(kv) << '\n';
	}

	cerr << endl;
}

