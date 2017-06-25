#include <memory>
#include <iostream>

using namespace std;

struct A {
    template<class Event>
    auto
    check() -> void;
};

struct B : A {
    template<class Event>
    auto
    check() -> void;
};

struct C : A {
    template<class Event>
    auto
    check() -> void;
};

template<>
auto
B::check<int>() -> void {
    cerr << "B::check<int>\n";
}

template<>
auto
B::check<double>() -> void {
    cerr << "B::check<double>\n";
}

template<>
auto
C::check<int>() -> void {
    cerr << "C::check<int>\n";
}

auto
make_with_base(const int slct) -> std::shared_ptr<A> {
    switch(slct) {
        case 0: return std::make_shared<B>();
        case 1: return std::make_shared<C>();
    }

    throw 1;
}


auto
add(int a,int b,int c) -> int {
    return a + b + c;
}

template<typename Fn>
auto
run(Fn fn) -> void
{
    fn();
}

template<class... Args>
auto
zoo(Args&&... args) -> void
{
    cerr << "zoo\n";
}

/*
template<>
auto
zoo(int,int,std::function<void()> f) -> void
{
   cerr << "zoo::f\n";
   f();
}
*/


template<class... Args>
auto
boo(Args&&... args) -> void
{
    cerr << "boo\n";
    run([&args...]()->void{
        cerr << "res: " << add(std::forward<Args>(args)...) << '\n'; 
    });
}

int main()
{
    auto p1 = make_with_base(0);
    auto p2 = make_with_base(1);

//    p1->check<int>();
//    p1->check<double>();

//    p2->check<int>();

    boo(1,2,3);
    // boo(1,2);
    
    cerr << "\n";
}

