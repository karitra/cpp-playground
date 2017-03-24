#include <iostream>
#include <forward_list>
#include <map>
#include <vector>
	
#include <type_traits>

#include <boost/current_function.hpp>

using namespace std;

template<class T>
struct is_vector : std::false_type {};

template<class T, class Alloc>
struct is_vector<std::vector<T,Alloc>> : std::true_type {};

template<class Container>
using is_vector_void_type = typename std::enable_if<is_vector<Container>::value>::type;
template<class Container>
using is_not_vector_void_type = typename std::enable_if<!is_vector<Container>::value>::type;

//template<class Container>
//using typename boo_type = std::enable_if_t<!is_vector<Container>::value>;

template<typename Container>
auto proc(Container& c) -> is_vector_void_type<Container>
{
	cerr << "dealing with vector\n";
}

template<typename Container>
auto proc(Container& c) -> is_not_vector_void_type<Container>
{
	cerr << "some type\n";
}

int main()
{
	std::map<int,int> m;
	std::vector<int> v;
	std::forward_list<int> l;

	cerr << boolalpha;
	cerr << "is_vector<map> " << is_vector<decltype(m)>::value << '\n';  
	cerr << "is_vector<vector> " << is_vector<decltype(v)>::value << '\n';  
	cerr << "is_vector<list> " << is_vector<decltype(l)>::value << '\n';  

	proc(m);
	proc(v);
	proc(l);
}

