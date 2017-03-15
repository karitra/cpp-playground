#include <iostream>
#include <tuple>
#include <typeinfo>

using namespace std;

int main() {

	auto t = make_tuple(1, "hello");
	auto &[i, s] = t;
	const auto &sss = std::string("world");

	std::cerr << i << ' ' << s << '\n';
	std::cerr << "type name: " << typeid(t).name() << '\n';
	std::cerr << "type name: " << typeid(s).name() << '\n';
	std::cerr << "type name: " << typeid(sss).name() << '\n';
}

