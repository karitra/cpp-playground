#include <utility>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main(int argc, char *argv[])
{
    using record_type = std::pair<std::string, std::map<std::string, int>>;
    std::vector<record_type> rv;

    record_type z{ "hello", {{"a", 1}} };
    // rv.emplace_back({ "hello", {{"a", 1}} });

    for(const auto& el : rv) {
        cerr << el.first << '\n';
    }
}
