#include <iostream>
#include <map>
#include <vector>

#include <boost/range/numeric.hpp>

using namespace std;

struct aggregate_proxy_t;

struct A {
	A(int zz) : z(zz) {
		cerr << "A ctor: " << zz << '\n';
	}

	A(const A &other) {
		cerr << "A copy\n"; 
	    z = other.z;
    }

	A(A &&other) {
		cerr << "A move\n";
	}
	
    A(const A &&other) {
		cerr << "A const move\n";
	}

	virtual ~A() {
		cerr << "A dtor\n";
	}

	int z;

    auto
    operator=(aggregate_proxy_t&& arg) -> A&;
};

struct aggregate_proxy_t {

    int val;

    aggregate_proxy_t() : val{} {
        cerr << "proxy ctor\n";
    }
 
    aggregate_proxy_t(const aggregate_proxy_t& other) {
        cerr << "proxy copy ctor\n";
        val = other.val;
    }

    aggregate_proxy_t(aggregate_proxy_t&& other) {
        cerr << "proxy move ctor\n";
        val = other.val;
    }
    
    auto
    operator=(const aggregate_proxy_t& other) -> aggregate_proxy_t& = default; 

    ~aggregate_proxy_t() {
        cerr << "proxy dtor\n";
    }

    auto
    operator+(const A& arg) -> aggregate_proxy_t& {
        cerr << "summation\n";
        val += arg.z;
        return *this;
    }
};
    
auto
A::operator=(aggregate_proxy_t&& arg) -> A& 
{
    cerr << "move assigned to A\n";
    this->z = arg.val; // std::move(arg.val);
    return *this;
}

struct B 
{
	B(A a) : local(std::move(a)) {}
	A local;
};

int foo(A a) {
	cerr << "foo: a.z = " << a.z << '\n';
	return a.z;
}

B boo() {
	A a(100500);
	a.z++;

	// return B(std::move(a));
	return B(a);
}

int main()
{
	//A b(1310);
	//foo(A(100500));
	const auto b = boo();

	cerr << "b.z " << b.local.z << '\n';

    std::map<int, A> am = {
        {1, {100}},
        {2, {200}},
        {3, {300}},
        {4, {300}}
     };

    cerr << "move iterators:\n";
    std::map<int, A> am1;
    
    for(auto it = std::begin(am); it != std::end(am); ++it) {
        am1.emplace(std::move(*it));
    }

    cerr << "clear am\n";
    am.clear();
    cerr << "clear am: done\n";

    std::map<int, A> am2;

    cerr << "copy_if with move iterator\n";

    std::copy_if(
        std::make_move_iterator(std::begin(am1)), 
        std::make_move_iterator(std::end(am1)), 
        std::inserter(am2, std::end(am2)),
        [] (const std::pair<int, A> &el) {
            return el.first % 2;
        }
    );

    cerr << "am2 content:\n";
    for(const auto& el : am2) {
        cerr << "\tk = " << el.first 
             << "\tv = " << el.second.z << '\n';  
    }

    cerr << "\nsummation test\n";
    std::vector<A> avec = { {1}, {2}, {3}, {4} };

    for(const auto& v : avec) {
        cerr << "val = " << v.z << '\n';
    }

    A x{0};
    x = boost::accumulate(avec, aggregate_proxy_t{});

    cerr << "x.z = " << x.z << '\n';
}

