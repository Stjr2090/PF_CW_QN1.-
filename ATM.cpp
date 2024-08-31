#include <iostream>
#include <string>
#include <map>
using namespace std;

// Structure to represent a bank account
struct Account {
    string id ;
    string password;
    double balance;
};

// Map to store bank accounts
map<string, Account> accounts;

// Function to create a new account
void createAccount() {
    string id, password;
    cout << "Please enter your user name: ";
    cin >> id;
    cout << "Please enter your password: ";
    cin >> password;

    // Check if account already exists
    if (accounts.find(id) != accounts.end()) {
        cout << "Account already exists!" << endl;
        return;
    }

    // Create new account
    Account newAccount;
    newAccount.id = id;
    newAccount.password = password;
    newAccount.balance = 0.0;
    accounts[id] = newAccount;

    cout << "Thank You! Your account has been created!" << endl;
}

// Function to login to an existing account
bool login(string& id) {
    string password;
    cout << "Please enter your user name: ";
    cin >> id;
    cout << "Please enter your password: ";
    cin >> password;

    // Check if account exists and password matches
    if (accounts.find(id) != accounts.end() && accounts[id].password == password) {
        cout << "Access Granted!" << endl;
        return true;
    } else {
        cout << "* LOGIN FAILED! *" << endl;
        return false;
    }
}

// Function to deposit money into an account
void deposit(string id) {
    double amount;
    cout << "Amount of deposit: Ush ";
    cin >> amount;
    accounts[id].balance += amount;
}

// Function to withdraw money from an account
void withdraw(string id) {
    double amount;
    cout << "Amount of withdrawal: Ush ";
    cin >> amount;
    if (amount > accounts[id].balance) {
        cout << "Insufficient funds!" << endl;
    } else {
        accounts[id].balance -= amount;
    }
}

// Function to request balance of an account
void requestBalance(string id) {
    cout << "Your balance is Ush " << accounts[id].balance << "." << endl;
}

int main() {
    string id;
    char choice;

    do {
        cout << "Hi! Welcome to the ATM Machine!" << endl;
        cout << "Please select an option from the menu below:" << endl;
        cout << "l -> Login" << endl;
        cout << "c -> Create New Account" << endl;
        cout << "q -> Quit" << endl;
        cin >> choice;

        switch (choice) {
            case 'l':
                if (login(id)) {
                    do {
                        cout << "d -> Deposit Money" << endl;
                        cout << "w -> Withdraw Money" << endl;
                        cout << "r -> Request Balance" << endl;
                        cout << "q -> Quit" << endl;
                        cin >> choice;

                        switch (choice) {
                            case 'd':
                                deposit(id);
                                break;
                            case 'w':
                                withdraw(id);
                                break;
                            case 'r':
                                requestBalance(id);
                                break;
                            case 'q':
                                break;
                            default:
                                cout << "Invalid choice. Please try again." << endl;
                        }
                    } while (choice != 'q');
                }
                break;
            case 'c':
                createAccount();
                break;
            case 'q':
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 'q');

    return 0;
}
