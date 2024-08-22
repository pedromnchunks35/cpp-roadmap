#include <iostream>
#include <memory>

class B;  // Forward declaration

class A {
public:
    std::shared_ptr<B> b;  // Shared pointer to B
    ~A() { std::cout << "A destroyed\n"; }
};

class B {
public:
    std::shared_ptr<A> a;  // Shared pointer to A
    ~B() { std::cout << "B destroyed\n"; }
};

int main() {
    {
        std::shared_ptr<A> a = std::make_shared<A>();
        std::shared_ptr<B> b = std::make_shared<B>();

        a->b = b;  // A holds a shared_ptr to B
        b->a = a;  // B holds a shared_ptr to A (cyclic reference)
    }

    // "A destroyed" and "B destroyed" will not be printed
    // Memory leak occurs here
    return 0;
}
