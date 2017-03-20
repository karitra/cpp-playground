// #include <cstdlib>
#include <initializer_list>
#include <string>
#include <array>

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

	static const std::array<std::string, 2> a{{ std::string{"abc"}, std::string{"def"} }};
	for(const auto &el : a) {
		// sum2 += strlen(el);	
		sum2 += el.size();
	}

	/*
	for(const auto &el : { std::string("abc"), std::string("def") }) {
		// sum2 += strlen(el);	
		sum2 += el.size();
	}
	*/

	return sum + sum2;
	// return EXIT_SUCCESS;
}
