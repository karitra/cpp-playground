#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>

struct alignas(16) boo_t {
    char payload;

    friend auto operator<<(std::ostream& o, const boo_t& b) -> std::ostream& {
        return o << static_cast<char>(b.payload + '0');
    }

    auto operator++() -> boo_t& {
        ++this->payload;
        return *this;
    }
}; 

struct foo_t {
    char payload;
    int zoo;
};

struct z_t {
    char b : 1;
};
 
auto main(int argc, char *argv[]) -> int {
    std::vector<boo_t> v(7);
    std::iota(std::begin(v), std::end(v), boo_t{1});

    auto b = boo_t{};
    ++b;
    std::cout << "b is " << ++b << '\n';
    std::copy(std::begin(v), std::end(v), std::ostream_iterator<boo_t>(std::cout, "\n"));

    std::cout << "sizeof boo_t: " << sizeof(boo_t) << '\n';
    std::cout << "sizeof foo_t: " << sizeof(foo_t) << '\n';
    std::cout << "sizeof z_t: " << sizeof(z_t) << '\n';
    std::cout << "sizeof int: " << sizeof(boo_t) << '\n';
  
    std::cout << "data size in v: " << (&v[10] - &v[0]) << '\n';
}

