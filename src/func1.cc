#include <iostream>
#include <functional>

using namespace std;

auto boo(std::function<int()> f) -> int {
    return f();
}

struct Boo {
    auto operator()() -> int {
        return 42;
    }

};

auto main() -> int {

    cout << "ans = " << boo(Boo{}) << '\n';
}
