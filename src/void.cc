#include <iostream>

void boo(void)
{
    return;
}

void foo(void)
{
    return;
}

int
main()
{
    //foo(boo());
    std::cerr << "It works!\n";
}

