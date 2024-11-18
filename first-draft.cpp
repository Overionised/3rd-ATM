#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// User Data Struct
struct User {
    int cardNumber;
    int pin;
    int balance;
};

// Global User Data
vector<User> users = {
    {111111, 1111, 200},
    {211111, 2111, 300},
    {311111, 3111, 400}
};

// Function Prototypes
bool login(User &loggedInUser);
void displayMenu(User &loggedInUser);
void checkBalance(const User &loggedInUser);
void withdrawMoney(User &loggedInUser);
void changePIN(User &loggedInUser);

// Main Program
int main() {
    User loggedInUser;
    if (login(loggedInUser)) {
        displayMenu(loggedInUser);
    } else {
        cout << "Too many failed attempts. Goodbye!" << endl;
    }
    return 0;
}

// Login Function
bool login(User &loggedInUser) {
    int cardNumber, pin, attempts = 3;

    while (attempts > 0) {
        cout << "Enter your 6-digit card number: ";
        cin >> cardNumber;

        // Check if card number exists
        bool cardFound = false;
        for (auto &user : users) {
            if (user.cardNumber == cardNumber) {
                loggedInUser = user; // Save the user
                cardFound = true;
                break;
            }
        }

        if (!cardFound) {
            cout << "Card number not found. Attempts left: " << --attempts << endl;
            continue;
        }

        // PIN Verification
        attempts = 3; // Reset attempts for PIN
        while (attempts > 0) {
            cout << "Enter your 4-digit PIN: ";
            cin >> pin;

            if (loggedInUser.pin == pin) {
                cout << "Login successful!\n" << endl;
                return true;
            } else {
                cout << "Incorrect PIN. Attempts left: " << --attempts << endl;
            }
        }

        return false; // Failed PIN verification
    }

    return false; // Failed login
}

// Display Menu
void displayMenu(User &loggedInUser) {
    int choice;
    do {
        cout << "\n--- Main Menu ---" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Withdraw Money" << endl;
        cout << "3. Change PIN" << endl;
        cout << "4. Exit" << endl;
        cout << "Select an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                checkBalance(loggedInUser);
                break;
            case 2:
                withdrawMoney(loggedInUser);
                break;
            case 3:
                changePIN(loggedInUser);
                break;
            case 4:
                cout << "Thank you for using our ATM. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);
}

// Check Balance
void checkBalance(const User &loggedInUser) {
    cout << fixed << setprecision(2);
    cout << "Your current balance is: $" << loggedInUser.balance << "\n" << endl;
}

// Withdraw Money
void withdrawMoney(User &loggedInUser) {
    int amount;
    vector<int> denominations = {5000, 2000, 1000, 200};

    while (true) {
        cout << "Enter the amount to withdraw: ";
        cin >> amount;

        // Validate amount
        if (amount <= 0 || amount > loggedInUser.balance) {
            cout << "Invalid amount or insufficient balance. Please try again.\n";
            continue;
        }

        // Check if the amount can be dispensed
        int tempAmount = amount;
        vector<int> notesCount(denominations.size(), 0);
        for (size_t i = 0; i < denominations.size(); i++) {
            notesCount[i] = tempAmount / denominations[i];
            tempAmount %= denominations[i];
        }

        if (tempAmount != 0) {
            cout << "The amount cannot be dispensed with available denominations. Try again.\n";
            continue;
        }

        // Dispense money
        cout << "Dispensing: ";
        for (size_t i = 0; i < denominations.size(); i++) {
            if (notesCount[i] > 0) {
                cout << notesCount[i] << "x" << denominations[i] << " ";
            }
        }
        cout << "\n";

        loggedInUser.balance -= amount;
        cout << "Withdrawal successful. New balance: $" << loggedInUser.balance << "\n" << endl;
        break;
    }
}

// Change PIN
void changePIN(User &loggedInUser) {
    int newPIN, confirmPIN;

    cout << "Enter your new 4-digit PIN: ";
    cin >> newPIN;

    cout << "Confirm your new PIN: ";
    cin >> confirmPIN;

    if (newPIN == confirmPIN && newPIN >= 1000 && newPIN <= 9999) {
        loggedInUser.pin = newPIN;
        cout << "PIN changed successfully.\n" << endl;
    } else {
        cout << "PINs do not match or are invalid. Try again.\n" << endl;
    }
}

