#include <iostream>

struct A {
    A() {
        std::cerr << "ctor A " << this << '\n';
    }

    ~A() {
        std::cerr << "dtor A " << this << '\n';
    }
};

auto main() -> int {

}
