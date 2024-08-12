#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
    string name;
    string accountNumber;
    string accountType;
    double balance;

public:
    BankAccount(string depositorName, string accNumber, string accType, double initialBalance = 0.0) {
        name = depositorName;
        accountNumber = accNumber;
        accountType = accType;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << ". New balance: " << balance << endl;
        } else {
            cout << "Deposit amount must be positive." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << ". New balance: " << balance << endl;
        } else {
            cout << "Insufficient balance or invalid amount." << endl;
        }
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    BankAccount account("John Doe", "123456789", "Savings", 1000.0);

    account.display();
    account.deposit(500.0);
    account.withdraw(300.0);
    account.display();

    return 0;
}
