#include <iostream>

using namespace std;

template<typename Boo>
struct boo {
    Boo b;
    int i;
};

int main()
{
   const auto b = boo<int>{1,2};
   cout << "b == " << b.b << '\n';
}

