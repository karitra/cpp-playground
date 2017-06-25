#include <iostream>
#include <vector>

using namespace std;

template<class Z>
auto foo() -> int {
    cout << "inside foo\n";
    return 100500;
}

template<typename... Args>
auto
templ() -> std::vector<int> {
    using expander_type = int[];
    (void) expander_type{ 0, (foo<Args>(), 0)...};

    return std::vector<int>{foo<Args>()...};
}


int main() {
    const auto v = templ<int, float, void>();
}

