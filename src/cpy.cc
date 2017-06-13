//
// Attempt to recall interview task with some kind of holder class 
// smart pointer with reference count and non trivial copy
// ctor sequence
//
#include <iostream>
#include <memory>

using namespace std;

struct Base {
    int i;
};

struct Y {
    Y(int a, int b, int c) {}
    int boo[4];
};

struct Q { int a; int b; int c; Base base; Q() = default;};

struct Qd { 
    int a; 
    int b; 
    int c;

    Base base;

    Qd() {
        cerr << "ctor(Qd)\n";
    }
};


struct Z {
    Z() {
        cerr << "ctor(Z)\n";
    }

    Z(const Z&) {
        cerr << "cpy(Z)\n";
    }
};

struct A {
    A() {
        cerr << "ctor(A)\n";
    }

    ~A() {
        cerr << "dtor(A)\n";
    }

    A(const A&) = delete;

    auto
    operator=(const A&) -> A& = delete;

    A(const Z& z)
    {
        cerr << "pseudo cpy(A)\n";
    }
};

struct B : A, Z {

    B() {
        cerr << "ctor(B)\n";    
    }    

    B(const B& b) : A(static_cast<const Z&>(b)), Z(b) {
        cerr << "cpy(B)\n";
    }

    ~B() {
        cerr << "dtor(B)\n";
    }

    B&
    operator=(const B& b) {
        cerr << "B::assing operator\n";
        return *this;
    }
};

int main()
{
    cerr << "b1\n";
    B b1;
    cerr << "b2\n";
    B b2 = b1;
    cerr << "b3\n";
    B b3(b2);
    cerr << "Q\n";
    Q q1;
    Q q2{};

    cerr << "Q1: " << q1.a << q1.b << q1.c << '\n';
    cerr << "Q2: " << q2.a << q2.b << q2.c << '\n';

    Qd qd{};
    cerr << "Qd: " << qd.a << qd.b << qd.c << '\n';

    auto q3 = new Q;
    auto q4 = new Q();

    cerr << "Q3: " << q3->a << q3->b << q3->c << q3->base.i << '\n';
    cerr << "Q4: " << q4->a << q4->b << q4->c << q4->base.i << '\n';

    Q q5;
    auto q6 = Q();

    cerr << "Q5: " << q5.a << q5.b << q5.c << q5.base.i << '\n';
    cerr << "Q6: " << q6.a << q6.b << q6.c << q6.base.i << '\n';

    Y y = {1,2,3};

    auto boo = std::make_shared<Y>(1,2,3);
    auto foo = unique_ptr<Y>( new Y{1,2,3});

    cerr << "sizeof(int) " << sizeof(int) << '\n';
    cerr << "sizeof(Y): " << sizeof(boo) << '\n';

    cerr << "sizeof(): " << sizeof(foo) << '\n';
}

