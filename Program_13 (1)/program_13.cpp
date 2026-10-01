#include <iostream>

class Base {
public:
    virtual ~Base() {
        std::cout << "Base class destructor\n";
    }
};

class Derived : public Base {
public:
    ~Derived() override {
        std::cout << "Derived class destructor\n";
    }
};

int main() {
    Base* pointer = new Derived();

    delete pointer;

    return 0;
}