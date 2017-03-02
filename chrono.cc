#include <iostream>
#include <chrono>

using namespace std;

int main() {
	const std::chrono::steady_clock::time_point ts = std::chrono::steady_clock::now();

	cerr << "time_point size " << sizeof(ts) << '\n';
}

