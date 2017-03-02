#include <chrono>
#include <iostream>
#include <iterator>
#include <functional>
#include <map>
#include <random>
#include <stdexcept>
#include <set>
#include <vector>
#include <utility>

#include <cstdlib>

// #include <boost/range/adaptor/transformed.hpp>
#include <boost/range/algorithm/transform.hpp>
#include <boost/range/algorithm/copy.hpp>
#include <boost/range/irange.hpp>

using namespace std;

struct payload_t {
        double a[4];
};

typedef std::map<double, payload_t> mapping_t;
typedef mapping_t::value_type pair_t;

struct pair_comparator_t {
    bool operator()(const pair_t &a, const pair_t &b) {
        return a.first < b.first;
    }
};

typedef std::set<pair_t, pair_comparator_t> setting_t;
typedef std::vector<pair_t> heap_t;

struct direct_order_updater_t {
    template<typename Container>
    void operator()(Container &c, const double val, const size_t limit) const {
        c.emplace(val, payload_t{val, val} );
        if (c.size() > limit) {
            c.erase(c.begin());
        }
    }
};

struct reverse_order_updater_t {
    template<typename Container>
    void operator()(Container &c, const double val, const size_t limit) const {
        if (c.size() >= limit) {
            c.erase(c.begin());
        }

        c.emplace(val, payload_t{val, val} );
    }
};

struct heap_updater_t {
    template<typename Container>
    void operator()(Container &c, const double val, const size_t limit) const {
        if (c.size() >= limit) {
            pop_heap(std::begin(c), std::end(c));
            c.pop_back();
        }

        c.push_back(val);
        push_heap(std::begin(c), std::end(c));
    }
};


template<typename Updater, typename Container, typename Samples>
size_t test(Container &c, const size_t acc_lim, const Samples &samples, const size_t iters) {
    const Updater upd;
    for(const auto &i : boost::irange<size_t>(0, iters)) {
        upd(c, samples[i % samples.size()], acc_lim);
    }

    // cerr << "c.size: " << c.size() << '\n';
    return iters;
}

std::vector<double>
gen_samples(const size_t samples_count) {
    decltype(gen_samples(0)) v;

    std::random_device rd;
    std::mt19937 gen(rd());

    const auto rnd = [=] (const int i) mutable { return static_cast<double>(gen() % samples_count * 0.1); };

    boost::transform(boost::irange<int>(0, samples_count), std::back_inserter(v), rnd);
    return v;
}

template<typename T, typename U>
auto to(const U& u) -> decltype(std::chrono::duration_cast<T>(u))
{
        return std::chrono::duration_cast<T>(u);
}

template<typename Container, typename Samples, typename Test>
void run_test(const char *name, const Samples &smpl, const Test &t) {
    using clock = std::chrono::high_resolution_clock;

    Container hist;

    auto ts = clock::now();
    const auto iters = t(hist, smpl);
    auto te = clock::now();

    if (iters) {
        const auto delta = te - ts;
        cerr << name << ": "
            // << "iters " << iters << ' '
            << "total " << to<std::chrono::microseconds>(delta).count() << " us, "
            << "per update: " << to<std::chrono::microseconds>(delta).count() / static_cast<double>(iters) <<  " us\n";
    }
}


int main(int argc, char *argv[]) {
    constexpr auto ITERS = size_t{10 * 1000 * 1000};

    const auto samples1k = gen_samples(1000);
    const auto samples1M = gen_samples(1000 * 1000);

    const auto it = size_t{ (argc > 1) ? strtoul(argv[1], nullptr, 10) : ITERS };

    cerr << "iters: " << it << '\n';

    using namespace std::placeholders;

    typedef decltype(samples1M) samples_type;
    for(const auto &acc_size : {100, 500, 1000, 10000}) {

        cerr << "acc size: " << acc_size << '\n';

        run_test<mapping_t>("\tmap, direct order", samples1M,
            std::bind(test<direct_order_updater_t, mapping_t, samples_type>,
            _1, // acc container
            acc_size, // acc limit
            _2, // samples
            it)
        );

        run_test<mapping_t>("\tmap, reverse order", samples1M,
            std::bind(test<reverse_order_updater_t, mapping_t, samples_type>,
            _1, // acc container
            acc_size, // acc limit
            _2, // samples
            it)
        );

        run_test<setting_t>("\tset, direct order", samples1M,
            std::bind(test<direct_order_updater_t, setting_t, samples_type>,
            _1, // acc container
            acc_size, // acc limit
            _2, // samples
            it)
        );

        run_test<setting_t>("\tset, reverse order", samples1M,
            std::bind(test<reverse_order_updater_t, setting_t, samples_type>,
            _1, // acc container
            acc_size, // acc limit
            _2, // samples
            it)
        );

        run_test<setting_t>("\theap, reverse order", samples1M,
            std::bind(test<reverse_order_updater_t, setting_t, samples_type>,
            _1, // acc container
            acc_size, // acc limit
            _2, // samples
            it)
        );

    }

    return EXIT_SUCCESS;
}
