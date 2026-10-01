#include <iostream>
#include <string>

int add(int first, int second) {
    return first + second;
}

double add(double first, double second) {
    return first + second;
}

int add(int first, int second, int third) {
    return first + second + third;
}

std::string add(std::string first, std::string second) {
    return first + second;
}

int main() {
    std::cout << "Sum of two integers: " << add(15, 25) << '\n';
    std::cout << "Sum of two doubles: " << add(4.2, 5.8) << '\n';
    std::cout << "Sum of three integers: " << add(12, 18, 25) << '\n';
    std::cout << "Joined strings: " << add("Good ", "Morning") << '\n';

    return 0;
}