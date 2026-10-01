#include <iostream>
#include <string>
#include <utility>
#include <memory>
#include <vector>

class Employee {
protected:
    int employeeId;
    std::string name;

public:
    Employee(int id, std::string employeeName)
        : employeeId(id), name(std::move(employeeName)) {}

    virtual double calculateSalary() const = 0;

    void displayBasicDetails() const {
        std::cout << "Employee ID: " << employeeId << '\n';
        std::cout << "Name: " << name << '\n';
    }

    virtual ~Employee() = default;
};

class PermanentEmployee : public Employee {
private:
    double basicSalary;
    double allowance;
    double taxRate;

public:
    PermanentEmployee(int id, std::string employeeName, double basic,
                      double extra, double tax)
        : Employee(id, std::move(employeeName)),
          basicSalary(basic), allowance(extra), taxRate(tax) {}

    double calculateSalary() const override {
        double grossSalary = basicSalary + allowance;
        double tax = grossSalary * taxRate / 100;
        return grossSalary - tax;
    }
};

class ContractEmployee : public Employee {
private:
    double hourlyRate;
    int hoursWorked;

public:
    ContractEmployee(int id, std::string employeeName, double rate, int hours)
        : Employee(id, std::move(employeeName)),
          hourlyRate(rate), hoursWorked(hours) {}

    double calculateSalary() const override {
        return hourlyRate * hoursWorked;
    }
};

class FreelanceEmployee : public Employee {
private:
    double projectPayment;

public:
    FreelanceEmployee(int id, std::string employeeName, double payment)
        : Employee(id, std::move(employeeName)),
          projectPayment(payment) {}

    double calculateSalary() const override {
        return projectPayment;
    }
};

void printPaySlip(const Employee& employee) {
    employee.displayBasicDetails();
    std::cout << "Salary: Rs. " << employee.calculateSalary() << "\n\n";
}

int main() {
    std::vector<std::unique_ptr<Employee>> employees;

    employees.push_back(
        std::make_unique<PermanentEmployee>(
            201, "Neha", 45000.0, 7000.0, 10.0));

    employees.push_back(
        std::make_unique<ContractEmployee>(
            202, "Rohan", 600.0, 75));

    employees.push_back(
        std::make_unique<FreelanceEmployee>(
            203, "Priya", 30000.0));

    double totalPayroll = 0.0;

    for (const auto& employee : employees) {
        printPaySlip(*employee);
        totalPayroll += employee->calculateSalary();
    }

    std::cout << "Total Payroll: Rs. " << totalPayroll << '\n';

    return 0;
}