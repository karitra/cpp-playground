
#include <iostream>

using namespace std;


class A {
};


class B : public A {
public:
    auto get() -> int {
        return 100500;
    }

} z;


auto main() -> int {
   cerr << "z value: " <<  z.get() << '\n';
}
