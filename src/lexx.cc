#include <iostream>
#include <cstdlib>

#include <boost/lexical_cast.hpp>

using namespace std;

auto main(int argc, char *argv[]) -> int {
    if (argc < 2) {
        return EXIT_FAILURE;    
    }

    cerr << "as a int: " << boost::lexical_cast<int>(argv[1]) << '\n';
}

