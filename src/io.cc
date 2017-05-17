#include <iostream>
#include <fstream>

using namespace std;

int main() try {
    ifstream is("Some.dummy.file.txt");
    is.exceptions(ifstream::failbit);       
} catch (...) {
    cerr << "Boo\n";
}

