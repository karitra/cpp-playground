// #include <cstdlib>
#include <initializer_list>
#include <string>

#include <cstdint>
#include <cstdlib>
#include <cstring>

int main()
{
	auto sum = int{};
	for(const auto &el : {1,2,3,4,1310}) {
		sum += el;
	}

	auto sum2 = size_t{};

	for(const auto &el : { std::string("abc"), std::string("def") }) {
		// sum2 += strlen(el);	
		sum2 += el.size();
	}

	return sum + sum2;
	// return EXIT_SUCCESS;
}
