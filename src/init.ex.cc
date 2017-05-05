#include <iostream>
#include <stdexcept>

class foo_t {
public:
    foo_t() {
        std::cout << "foo_t()" << std::endl;
    }

    ~foo_t() {
        std::cout << "~foo_t()" << std::endl;
    }
};

auto make() -> foo_t {
    return foo_t();
}

auto make_throw() -> foo_t {
    throw std::runtime_error("fuck GCC");
}

struct combine_t {
    foo_t foo;
    foo_t bar;
};

auto execute(combine_t) -> void {}

int main() {
    try {
        execute({make(), make_throw()});
    } catch (const std::exception&) {
        std::cerr << "Boom\n";  
    }

    return 0;
}

