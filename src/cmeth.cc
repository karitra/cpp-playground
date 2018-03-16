#include <iostream>

struct Boo {
    auto foo() -> int {
        return z++;
    }

    int z;
};


auto main(int argc, char **argv) -> int {
    Boo boo;
    return boo.foo();
}
