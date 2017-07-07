#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

#include <boost/algorithm/string/join.hpp>
#include <boost/range/adaptor/sliced.hpp>
//#include <boost/range.hpp>

constexpr auto TAKE_THAT = size_t{2}; 

auto main() -> int 
{
    using namespace boost::adaptors;

    // std::vector<int> v_num{1,2,3,4,5,6,7,8,9};
    std::vector<std::string> v_str{ "one", "two", "three", "four", "five"};

    const auto joined = boost::join( v_str | sliced(0, std::min( TAKE_THAT, v_str.size())), "\n");

    std::cerr << joined << '\n';
}

