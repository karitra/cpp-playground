#include <iostream>

using namespace std;

struct A {
    virtual auto z() -> int = 0;
};

template<class Z>
struct B : public A {
    auto z() -> int override {
        cerr << "derived B::z\n";
        return 100500;
    }

    using type = Z;
};

int main()
{
    B<int> b;
    b.z();
}
