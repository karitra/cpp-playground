#include <boost/mpl/vector.hpp>
#include <string>

namespace mpl = boost::mpl;

struct t1 {
	typedef mpl::vector<
		int,
		std::string
	> type;
};

struct Impl {
	
};

int main()
{
	t1::type z; 
}

