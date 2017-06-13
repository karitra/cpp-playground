#include <functional>
#include <iostream>

#include <boost/mpl/list.hpp>

template<int N>
struct rec {
    enum { value = N * rec<N-1>::value };
};

template<> 
struct rec<0> {
    enum { value = 1 };
};

auto foo(int a, int b, int c) -> int {
    std::cerr << "\ta = " << a << '\n';
    std::cerr << "\tb = " << b << '\n';
    std::cerr << "\tc = " << c << '\n';

    return a + b + c;
}


template<typename Int = int>
struct list {
    using type = boost::mpl::list<
        std::integral_constant<Int, 2>,
        std::integral_constant<Int, 1>,
        std::integral_constant<Int, 3>
    >;
};

template<typename... Args>
auto par(Args&&... args) -> void {
    foo(std::forward<Args>(args)...);
}

template<typename F, typename... Args>
auto binder(F&& fn, Args&&... args) -> 
    decltype(std::bind(std::forward<F>(fn), std::forward<Args>(args)...)) {
    return std::bind(std::forward<F>(fn), std::forward<Args>(args)...);
}


int main(int argc, char *argv[])
{
    namespace ph = std::placeholders;

    const auto fn = std::bind(foo, ph::_1, ph::_2, ph::_3);
    const auto r = fn(1, 2, 3, 4, 5);
 
    const auto v = rec<4>::value;
  
    std::cerr << "sum: " << r << '\n';
    std::cerr << "fac: " << v << '\n';

    auto zfunc = binder(foo, ph::_1, ph::_2, ph::_3);

    std::cerr << "sum2: " << zfunc(1,2,3) << '\n';
}

