#include <iostream>

using namespace std;

template<class Z>
auto foo() -> void {
    cout << "inside foo\n";
}

template<typename... Args>
auto
templ() -> void {
    using expander_type = int[];
    (void) expander_type{ 0, (foo<Args>(), 0)...};
}

int main() {
    templ<int, float, void>();
}

