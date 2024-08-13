#include <iostream>
#include <string>
using namespace std;

// Base Account class
class Account {
public:
    string customer_name;
    int account_number;
    string account_type;
    double balance;

    void initialize_account(string name, int number, string type) {
        customer_name = name;
        account_number = number;
        account_type = type;
        balance = 0;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited " << amount << ". Updated balance: " << balance << endl;
    }

    void display_balance() {
        cout << "Balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrew " << amount << ". Updated balance: " << balance << endl;
        } else {
            cout << "Insufficient funds! Cannot withdraw " << amount << endl;
        }
    }
};

// Savings Account class
class SavAcct : public Account {
public:
    void compute_and_deposit_interest(double rate, int time_period) {
        double interest = balance * rate * time_period / 100;
        balance += interest;
        cout << "Interest of " << interest << " deposited. Updated balance: " << balance << endl;
    }
};

// Current Account class
class CurrAcct : public Account {
public:
    double minimum_balance;

    void set_minimum_balance(double min_balance) {
        minimum_balance = min_balance;
    }

    void check_minimum_balance() {
        if (balance < minimum_balance) {
            double penalty = 100; 
            balance -= penalty;
            cout << "Minimum balance not maintained. Penalty imposed: " << penalty << endl;
            cout << "Updated balance: " << balance << endl;
        }
    }
};

int main() {
    SavAcct savings;
    savings.initialize_account("John Doe", 12345, "Savings");
    savings.deposit(1000);
    savings.compute_and_deposit_interest(5, 1); // 5% interest for 1 year
    savings.withdraw(200);
    savings.display_balance();

    CurrAcct current;
    current.initialize_account("Jane Doe", 54321, "Current");
    current.deposit(500);
    current.set_minimum_balance(1000);
    current.check_minimum_balance();
    current.withdraw(100);
    current.display_balance();

    return 0;
}
