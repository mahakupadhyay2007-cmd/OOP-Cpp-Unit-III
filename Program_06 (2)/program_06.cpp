#include <iostream>

class Distance {
private:
    int meters;

public:
    explicit Distance(int value) : meters(value) {}

    bool operator>(const Distance& other) const {
        return meters > other.meters;
    }

    bool operator==(const Distance& other) const {
        return meters == other.meters;
    }

    void display() const {
        std::cout << meters << " meters\n";
    }
};

int main() {
    Distance first(150);
    Distance second(100);

    std::cout << "First distance: ";
    first.display();

    std::cout << "Second distance: ";
    second.display();

    if (first > second) {
        std::cout << "First distance is greater\n";
    } else {
        std::cout << "Second distance is greater or equal\n";
    }

    if (first == second) {
        std::cout << "Both distances are equal\n";
    } else {
        std::cout << "Both distances are not equal\n";
    }

    return 0;
}