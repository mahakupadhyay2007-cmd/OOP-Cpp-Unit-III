#include <iostream>

class Balance {
private:
    double balance;

public:
    explicit Balance(double givenBalance) : balance(givenBalance) {}

    Balance operator-() const {
        return Balance(-balance);
    }

    void display() const {
        std::cout << balance << '\n';
    }
};

int main() {
    Balance first(7500.50);
    Balance second = -first;

    std::cout << "Original balance: ";
    first.display();

    std::cout << "Negative balance: ";
    second.display();

    return 0;
}