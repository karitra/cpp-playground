#include <iostream>
#include <cstdlib>

auto main(int argc, const char **argv) -> int {
    auto flag = bool{};
    auto val = int{100};

    flag = val > 10;

    std::cerr << "flag is: " << std::boolalpha << flag << std::endl;
    
    return EXIT_FAILURE;
}

