#include <iostream>

using namespace std;


template<typename U, typename T>
struct trait;

template<typename U, typename T = void>
struct trait : std::false_type {};

template<typename> struct _void { typedef void type; };

template<typename U> 
struct trait<U, typename _void<decltype( U() + U() )>::type> : public std::true_type {};

struct Zoo {};

int main()
{
	// typedef Zoo foo_type;
	cerr << boolalpha;
	cerr << "is addable (int) " << trait<int>::value << '\n';
	cerr << "is addable (double) " << trait<double>::value << '\n';
	cerr << "is addable (void) " << trait<void>::value << '\n';
	cerr << "is addable (Zoo) " << trait<Zoo>::value << '\n';
}

