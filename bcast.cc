#include <iostream>
#include <string>

#include <boost/lexical_cast.hpp>

using namespace std;

struct Boo {
	friend ostream &operator<<(ostream &o, const Boo &b) {
		return o << b.to_string();
	}

	string to_string() const { return "boo"; }
};

int main()
{
	Boo b;
	cerr << "Boo is: " << boost::lexical_cast<string, Boo>(b) << '\n';
	return 0;
}

