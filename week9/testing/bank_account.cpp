// TODO(student) - in class activity
#include <iostream>
#include <cassert>
class BankAccount {
    double balance_;

 public:
    BankAccount() : BankAccount(0) {}
    BankAccount(double initial) : balance_{initial} {}
    void deposit(double amount) { balance_ += amount; }
    void withdraw(double amount) {
        if (amount > balance_) {
            throw std::invalid_argument("overdraft");
        }
        balance_ -= amount;
    }
    double balance() { return balance_; }

    BankAccount& transfer_to(BankAccount& other, double amount) {
        this->withdraw(amount);
        other.deposit(amount);
        return *this;
    }
};

bool equal(double x, double y) { return std::abs(x - y) < 5e-7; }

int main() {
    BankAccount account(100.0);               // Given I have an account with $100
    assert(equal(account.balance(), 100.0));  // Then my account balance should be $100

    account.deposit(20.0);                    // When I deposit $20
    assert(equal(account.balance(), 120.0));  // Then my account balance should be $120

    account.withdraw(25.0);                   // When I withdraw $25
    assert(equal(account.balance(), 95.0));   // Then my account balance should be $95

    bool exception_thrown_on_overdraft = false;
    try {
        account.withdraw(200.0);              // When I try to withdraw $200
    } catch (const std::invalid_argument& err) {
        exception_thrown_on_overdraft = true;
    }
    assert(exception_thrown_on_overdraft);    // Then the withdrawal fails with an exception
    assert(equal(account.balance(), 95.0));   // And my account balance should be $95

    BankAccount second(50.0);                 // Given second account with $50
    account.transfer_to(second, 18.76);       // When I transfer $18.76 to the second account
    assert(equal(account.balance(), 76.24));  // Then my account balance should be $76.24
    assert(equal(second.balance(), 68.76));   // And the second account balance should be $68.76

    exception_thrown_on_overdraft = false;
    try {
        account.transfer_to(second, 76.25);   // When I try to transfer $76.25 to the second account
    } catch (const std::invalid_argument& err) {
        exception_thrown_on_overdraft = true;
    }
    assert(exception_thrown_on_overdraft);    // Then the transfer fails with an exception
    assert(equal(account.balance(), 76.24));  // And my account balance should be $76.24
    assert(equal(second.balance(), 68.76));   // And the second account balance should be $68.76

    BankAccount third(123.45);                // Given a third account with $123.45
    account.transfer_to(second, 10.0)         // When I transfer $10 to the second account
           .transfer_to(third, 12.0);         //      and 12 to the third account
    assert(equal(account.balance(), 54.24));  // The my account balance should be $54.24
    assert(equal(second.balance(), 78.76));   // And the second account balance should be $78.76
    assert(equal(third.balance(), 135.45));   // And the third account balance should be $135.45

    std::cout << "All tests passed!\n";
    return 0;
}