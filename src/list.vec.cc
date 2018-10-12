#include <array>

#include <cstdint>
#include <chrono>
#include <iostream>
#include <iomanip>
#include <vector>
#include <list>


struct foo {
    uint8_t a;
    uint16_t b;
    uint32_t c;
    uint64_t d;
    uint64_t e;
};


template<typename Container>
auto construct(size_t size) -> Container {
    Container c;
    while(size--) {
        c.push_back(foo{1,2,3});  
    }

    return c;
}

template<typename Container>
auto iterate(Container &c) -> std::uint64_t {
    auto result = std::uint64_t{0};

    for(const auto &r : c) {
        result += r.a + r.b + r.c + r.d + r.e;
    }
    
    return result;
}


template<typename T>
struct container_type {
    static auto label() -> const char *;
};

template<typename T, typename Alloc>
struct container_type<std::vector<T, Alloc>> {
    static auto label() -> const char * {
        return "vector";
    }
};

template<typename T, typename Alloc>
struct container_type<std::list<T, Alloc>> {
    static auto label() -> const char * {
        return "  list";
    }
};



template<typename Container>
auto measure(std::ostream &os, const size_t size) -> void {
    using Clock = std::chrono::steady_clock;
    //using ms = std::chrono::milliseconds;
    using u = std::chrono::microseconds;

    auto start = Clock::now();
    auto c = construct<Container>(size);
    auto construct_time = Clock::now() - start;

    start = Clock::now();
    auto r = iterate<>(c);
    auto iterate_time = Clock::now() - start;
    auto total = construct_time + iterate_time;

    os 
        << '[' << std::setw(8) << size << "] " 
        << container_type<Container>::label() 
        << " total: " << std::setw(10) << std::chrono::duration_cast<u>(total).count() 
        << " result: " << std::setw(10) << r
        << " construct time: " << std::setw(10) << std::chrono::duration_cast<u>(construct_time).count()
        << " iterate time: " << std::setw(10) << std::chrono::duration_cast<u>(iterate_time).count() << '\n';
}

auto main(int argc, char *argv[]) -> int {

    std::array<size_t, 5> limits = {100, 1000, 10000, 100000, 1000000};

    for(const auto &lim: limits) {
        measure<std::list<foo>>(std::cout, lim);
        measure<std::vector<foo>>(std::cout, lim);
    }
}

