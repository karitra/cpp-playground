#include <iostream>
#include <unordered_map>
#include <cstdlib>


struct boo {
    boo(int i) : i(i) {
        std::cerr << "boo(" << this->i << ")\n";
    }
    
    boo(const boo& other) : i(other.i) {
        std::cerr << "boo(" << this->i << ") copy\n";
     }

    boo(boo&& other) : i(std::move(other.i)) {
        std::cerr << "boo(" << this->i << ") move\n";
    }

    ~boo() {
        std::cerr << "~boo(" << this->i << ")\n";
    }

    int i;
};


auto main(int argc, const char *argv[]) -> int {
    std::cerr << "Running\n";
    std::unordered_map<std::string, boo> orig{ {"a", boo(1)}, {"b", boo(2)}, {"z", boo(3)} }; 
    std::cerr << "Moving initializer\n";
    std::unordered_map<std::string, boo> dst(
        std::make_move_iterator(std::begin(orig)),
        std::make_move_iterator(std::end(orig))
    );

    std::cerr << "clear from orig\n";
    orig.clear();
    std::cerr << "orig is empty, exiting\n"; 


    return EXIT_SUCCESS;
}

