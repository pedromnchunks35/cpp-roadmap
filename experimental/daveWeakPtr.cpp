#include <iostream>
#include <memory>
#include <atomic>
#include <thread>
void AdvancedSharedPtr();
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

int main()
{
    AdvancedSharedPtr();
}
void AdvancedSharedPtr()
{
    //? NEVER DO THIS:
    // Base *p = sp1.get();

    //? DO THIS
    std::shared_ptr<Base> sp1 = std::make_shared<Base>();
    std::weak_ptr<Base> wp1 = sp1;

    if (std::shared_ptr<Base> locked = wp1.lock())
    {
        locked->speak();
    }

    sp1.reset();

    if (wp1.expired())
    {
        std::cout << "The weak ptr is expired" << "\n";
    }

    //? ALIAS CREATION OF OTHER SHARED PTR
    std::shared_ptr<Base> sp2 = std::make_shared<Base>();
    std::shared_ptr<Base> sp2_alias(sp2, sp2.get());
    sp2_alias->speak();
    std::cout << "sp2 use_cout" << sp2.use_count() << "\n";

    //? SHARED PTR FOR ARRAYS
    std::shared_ptr<Base[]> sp3(new Base[3]);
    sp3[0].speak();
    sp3[1].speak();
    sp3[2].speak();

    //? ATOMIC OPERATIONS
    std::shared_ptr<Base> sp4 = std::make_shared<Base>();
    std::shared_ptr<Base> sp5;

    std::thread t1([&]()
                   { std::atomic_store(&sp5, std::atomic_load(&sp4)); });
    std::thread t2([&]()
                   { std::atomic_store(&sp4, std::shared_ptr<Base>(nullptr)); });
    t1.join();
    t2.join();
    if (sp5)
    {
        sp5->speak();
    }
}