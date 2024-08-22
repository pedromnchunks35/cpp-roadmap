#include <iostream>
#include <memory>
#include <vector>
class Base
{
public:
    virtual void speak()
    {
        std::cout << "I am a Base." << "\n";
    }
    virtual ~Base()
    {
        std::cout << "Destroyed" << "\n";
    }
};
class Derived : public Base
{
public:
    void speak() override
    {
        std::cout << "I am a derived." << "\n";
    }
    ~Derived() override
    {
        std::cout << "Derived Destroyed" << "\n";
    }
};

void custom_deleter(Base *ptr)
{
    std::cout << "Custom delete called" << "\n";
    delete ptr;
}

int main()
{
    std::shared_ptr<Base> sp1 = std::make_shared<Base>();
    sp1->speak();

    //? CREATING THE SHARED PTR WITH A CUSTOM DELETER
    std::shared_ptr<Base> sp2(new Derived, custom_deleter);
    sp2->speak();

    //? CREATING A SHARED PTR FROM ANOTHER SHARED PTR (COPYING)
    std::shared_ptr<Base> sp3 = sp1;
    sp3->speak();

    //? RESETING SHARED_PTR AND PUT A NEW VALUE IN IT
    sp3.reset(new Derived);
    sp3->speak();

    std::cout << "sp1 use_cout: " << sp1.use_count() << "\n";

    std::vector<std::shared_ptr<Base>> container;
    container.push_back(sp1);
    container.push_back(sp2);
    container.push_back(sp3);

    for (const auto &item : container)
    {
        item->speak();
    }
}