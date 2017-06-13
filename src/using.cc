#include <iostream>

using namespace std;

auto foo() -> int {
    return 100500;
}

struct A {
    using type = int();
};

struct B : public A {
    using A::type;

    auto run(type f) -> int {
        return f();
    }
};

enum Foo {
    Kva1,
    Kva2
};

struct C {
    C() {
        cerr << "C ctor\n";
    }
};

struct D: public C {
    D(int i) {
        cerr << "D ctor\n";
    }
};

struct E {
    int i;
    int j;
};

struct F {
    F() = default;
    int i;
    int j;
};

int main()
{
    B b;
    cerr << "result: " << b.run(foo) << '\n'; 

    if (Kva1 != 100500) {
        cerr << "it works\n";
    }

    D d(100500);

    E e;
    cerr << "e.i = " << e.i << " e.j = " << e.j << '\n';  
    E e2 = E();
    cerr << "e2.i = " << e2.i << " e2.j = " << e2.j << '\n';  
    const auto e3 = E{};
    cerr << "e3.i = " << e3.i << " e3.j = " << e3.j << '\n';  
    const auto f = F{};
    cerr << "f.i = " << f.i << " f.j = " << f.j << '\n';  
    F f2;
    cerr << "f2.i = " << f2.i << " f2.j = " << f2.j << '\n';  
}

