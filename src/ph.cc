#include <functional>
#include <iostream>

auto 
fun(int k, int x, int b) -> int
{
    return k * x + b;
}  

template<int I>
struct iph {};

namespace std {
    template<int I>
    struct is_placeholder<iph<I>> : public std::integral_constant<int,I> {};
}

template<int... S>
struct seq {
    template<typename F>
    static
    auto
    bind(F&& f) -> 
        decltype(std::bind(std::forward<F>(f), iph<S+1>()...)) {
        return std::bind(std::forward<F>(f), iph<S+1>()...);
    }
};

template<int N, int... S>
struct gens : gens<N-1, N-1, S...> {};

template<int ...S>
struct gens<0, S...> {
    using placeholders = seq<S...>;
};

int main()
{
    const auto fn = gens<3>::placeholders::bind(fun);

    const auto y = fn(3,2,1);

    std::cout << "result is " << y << '\n';
}

