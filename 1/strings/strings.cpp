#include <iostream>

int main()
{
    std::string x = "Hello world";
    std::cout << x << std::endl;
    //? sums
    x.append(" Stonks");
    std::cout << x << std::endl;
    //? replaces
    x.assign("1kkkkk3");
    std::cout << x << std::endl;
    std::cout << x.at(0) << std::endl;
    //? returns the last member os the string
    std::cout << x.back() << std::endl;
    //? returns the first member of the string (x.begin() its like a pointer but it is not a pointer)
    std::string::iterator it = x.begin();
    std::cout << "The first char is " << *it << std::endl;
    for (auto it = x.begin(); it != x.end(); it++)
    {
        std::cout << "This is printing things out " << *it << std::endl;
    }
    //? returns the actually capacity of the string until it gets more data
    std::cout << x.capacity() << " or " << x.size() << std::endl;
    //? clears string
    x.clear();
    std::cout << x << std::endl;
    //? compare strings
    x = "2kkk2";
    std::cout << x.compare("2kkk2") << std::endl;
    std::cout << x.compare("kkk2") << std::endl;
    x.insert(1, "po");
    std::cout << x << std ::endl;
    //? find methods
    std::cout << x.find_first_not_of("2") << std::endl;
    std::cout << x.find("2") << std::endl;
    std::cout << x.find_first_of("2") << std::endl;
    std::cout << x.find_last_not_of("2") << std::endl;
    std::cout << x.find_last_of("2") << std::endl;
}