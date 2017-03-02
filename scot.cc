#include <iostream>
#include <chrono>
#include <thread>

#include <boost/thread/scoped_thread.hpp>

using namespace std;



int foo(int times) {
	auto z = int{};

	for(auto i = int{0}; i < times; ++i) {
		cerr << "i = " << (i + 1) << '\n';
		std::this_thread::sleep_for(std::chrono::seconds(1));
		++z;
	}

	std::cerr << "exiting foo\n";
	return z; 
}

int main() try {
	boost::strict_scoped_thread<boost::join_if_joinable> thr([] () { foo(5); });
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cerr << "exiting main\n";
} catch(...) {
	std::cerr << "exception!\n";
	throw; 
}

