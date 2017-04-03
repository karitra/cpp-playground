//
// Note: use huge number of iterations
//
#include <atomic>
#include <iostream>
#include <chrono>
#include <cstdlib>

#include <boost/range/irange.hpp>

template<class Src, class Dst>
auto
test(const int iters, const int init) -> int 
{
    Dst summ{0};

    Src src{init};

    for(int i = 0; i < iters; ++i) {
        summ += src;
    }

    return summ;
}

template<class Src, class Dst>
void
run_test(const int iters, const int init, const std::string &logo) {
    auto ts = std::chrono::high_resolution_clock::now();
    test<Src,Dst>(iters, init);
    auto te = std::chrono::high_resolution_clock::now();

    std::cerr << logo << std::chrono::duration_cast<std::chrono::milliseconds>(te - ts).count() << " ms\n";
}

int main(int argc, char *argv[]) 
{
    if (argc < 2) {
        std::cerr << "usage:\n"
                << "\tatomic <number of iterations>\n";
        return EXIT_FAILURE;
    }

    const auto iters = atoi(argv[1]);

    std::cerr << "Running " << iters << " iterations\n";

    run_test<int,int>(iters, 1310, "<int,int> timing: ");
    run_test<std::atomic<int>,int>(iters, 1310, "<atomic,int> timing: ");
    run_test<int,std::atomic<int>>(iters, 1310, "<int,atomic> timing: ");
    run_test<std::atomic<int>,std::atomic<int>>(iters, 1310, "<atomic,atomic> timing: ");

    return EXIT_SUCCESS;
}

