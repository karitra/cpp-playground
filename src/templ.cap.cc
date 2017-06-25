#include <iostream>

using namespace std;

template<typename Z>
auto foo() -> void;

template<>
auto foo<int>() -> void {
    cout << "foo<int>\n";
}

template<>
auto foo<double>() -> void {
    cout << "foo<double>\n";
}

template<class Z>
auto
run() -> void {
    auto f = [] {
        foo<Z>();
    };

    f();
}

template<class... Args>
auto zoo(Args&&... args) -> void {
    cout << "ZZZooo with args count " << sizeof...(args) << '\n';
}

template<class... Args>
auto
proc(Args&&... args) {
    auto f = [&args...] {
        zoo(std::forward<Args>(args)...);
    };

    f();
} 

int main()
{
    run<int>();
    run<double>();

    proc(1,2,3);
}

