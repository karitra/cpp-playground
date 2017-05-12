#include <iostream>
#include <string>
#include <map>

#include <boost/any.hpp>

struct A {
    std::string a;
    std::string b;

    std::string
    get_boo(const std::string& key) const {
        return boost::any_cast<std::string>(other.at(key));
    }

    void
    set_boo(const std::string& key, const std::string& value) {
        other[key] = value;
    }

private:
    std::map<std::string, boost::any> other;
};

int main()
{
    enum class Z : unsigned {
        FOO
    };

    A a;
    auto an = boost::any{};
    auto ans = boost::any{};
    auto zans = boost::any{};

    an = 100500u;
    ans = std::string("something");
    if (an.empty()) {
        std::cerr << "It's empty!\n";
    } else {
        std::cerr << "It has value!\n";
        const char *s = "zoo";
        zans = s;
        // std::cerr << "val(const char*): " << boost::any_cast<const std::string&>(zans) << '\n';
        std::cerr << "val(const str&): " << boost::any_cast<const std::string&>(ans) << '\n';
        std::cerr << "val(str&): " << boost::any_cast<std::string&>(ans) << '\n';
        std::cerr << "val(str): " << boost::any_cast<std::string>(ans) << '\n';
        std::cerr << "val(int): " << boost::any_cast<unsigned>(an) << '\n';
        
        ans = Z::FOO;
        
        std::cerr << "ans: " << static_cast<unsigned>(boost::any_cast<Z>(ans)) << '\n';

        // these one throws!    
        //std::cerr << "val(str): " << boost::any_cast<std::string>(an) << '\n';
        //std::cerr << "val(str&): " << boost::any_cast<std::string&>(an) << '\n';
    }

    a.set_boo("one", "hello string");
    auto v = a.get_boo("one");

    std::cerr << "value: " << v << '\n';
}

