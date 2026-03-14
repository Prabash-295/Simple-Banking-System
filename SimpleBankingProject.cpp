#include <iostream>
#include <string>
using namespace std;

class Account {
private:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    Account(string accNum, string accHolder, double initialBalance)
        : accountNumber(accNum), accountHolderName(accHolder), balance(initialBalance) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << endl;
        } else {
            cout << "Deposit amount must be positive." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        } else {
            cout << "Withdrawal amount must be positive and <= balance." << endl;
        }
    }

    void displayAccountInfo() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    string accNum, accHolder;
    double initialBalance;

    cout << "Enter Account Number: ";
    getline(cin, accNum);

    cout << "Enter Account Holder Name: ";
    getline(cin, accHolder);

    cout << "Enter Initial Balance: ";
    cin >> initialBalance;

    Account myAccount(accNum, accHolder, initialBalance);

    int choice;
    double amount;

    do {
        cout << "\nMenu:\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Display Account Information\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter amount to deposit: ";
            cin >> amount;
            myAccount.deposit(amount);
            break;
        case 2:
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            myAccount.withdraw(amount);
            break;
        case 3:
            myAccount.displayAccountInfo();
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}