
#include <iostream>
#include <iomanip>
#include <chrono>

using namespace std;

// Global User Data (2D Array)
const int MAX_USERS = 3;
const int DATA_FIELDS = 3; // Card Number, PIN, Balance
int users[MAX_USERS][DATA_FIELDS] = {
    {111111, 1111, 200},
    {211111, 2111, 1000},
    {311111, 3111, 4000}
};

// Function Prototypes
int getInt();
bool login(int &loggedInUserIndex);
void displayMenu(int loggedInUserIndex);
void checkBalance(int loggedInUserIndex);
void withdrawMoney(int loggedInUserIndex);
void changePIN(int loggedInUserIndex);
void updateUserData(int loggedInUserIndex, int fieldIndex, int newValue);
void illusion();


// Main Program
int main() {
    int loggedInUserIndex;
    if (login(loggedInUserIndex)) {
        displayMenu(loggedInUserIndex);
    } else {
        cout << "Too many failed attempts. Goodbye!" << endl;
    }
    return 0;
}

// Input Validation Function
int getInt() {
    int value;
    while (!(cin >> value) || value < 0) {
        cout << "Please enter a valid number: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    return value;
}
void illusion() {
    const string message = "computing beep boop ";
    const char spinner[] = {'\\', '|', '/', '-'};
    const int spinnerSize = sizeof(spinner) / sizeof(spinner[0]);
    int count = 0;

    while (count < 10) {
        cout << message <<spinner[count % spinnerSize] << "\r";
        cout.flush();

        auto start = chrono::steady_clock::now();
        while (chrono::steady_clock::now() - start < chrono::milliseconds(200)) {
        }

        count++;
    }
    return;
}

// Login Function
bool login(int &loggedInUserIndex) {
    int cardNumber, pin, attempts = 3;

    while (attempts > 0) {
        cout << "Enter your 6-digit card number: ";
        cardNumber = getInt();

        // Check if card number exists
        loggedInUserIndex = -1;
        for (int i = 0; i < MAX_USERS; i++) {
            if (users[i][0] == cardNumber) { // Match card number
                loggedInUserIndex = i;
                break;
            }
        }

        if (loggedInUserIndex == -1) {
            cout << "Card number not found. Attempts left: " << --attempts << endl;
            continue;
        }

        // PIN Verification
        while (attempts > 0) {
            cout << "Enter your 4-digit PIN: ";
            pin = getInt();

            if (users[loggedInUserIndex][1] == pin) {
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
void displayMenu(int loggedInUserIndex) {
    int choice;
    do {
        cout << "\n--- Main Menu ---" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Withdraw Money" << endl;
        cout << "3. Change PIN" << endl;
        cout << "4. Exit" << endl;
        cout << "Select an option: ";
        choice = getInt();

        switch (choice) {
            case 1:
                checkBalance(loggedInUserIndex);
                break;
            case 2:
                withdrawMoney(loggedInUserIndex);
                break;
            case 3:
                changePIN(loggedInUserIndex);
                break;
            case 4:
                illusion();
                cout << "Thank you for using our ATM. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);
}

// Check Balance
void checkBalance(int loggedInUserIndex) {
    illusion();
    cout << "Your current balance is: " << users[loggedInUserIndex][2] << ",-\n" << endl;
}

// Withdraw Money
void withdrawMoney(int loggedInUserIndex) {
    int amount;
    int denominations[] = {5000, 2000, 1000, 200};
    int numDenominations = sizeof(denominations) / sizeof(denominations[0]);

    while (true) {
        cout << "Enter the amount to withdraw: ";
        amount = getInt();

        // Validate amount
        if (amount <= 0 || amount > users[loggedInUserIndex][2]) {
            cout << "Invalid amount or insufficient balance. Please try again.\n";
            continue;
        }

        // Check if the amount can be dispensed
        int tempAmount = amount;
        int notesCount[numDenominations] = {0};
        for (int i = 0; i < numDenominations; i++) {
            notesCount[i] = tempAmount / denominations[i];
            tempAmount %= denominations[i];
        }

        if (tempAmount != 0) {
            cout << "The amount cannot be dispensed with available denominations. Try again.\n";
            continue;
        }

        // Dispense money
        cout << "Dispensing: ";
        for (int i = 0; i < numDenominations; i++) {
            if (notesCount[i] > 0) {
                cout << notesCount[i] << "x" << denominations[i] << " ";
            }
        }
        cout << "\n";

        users[loggedInUserIndex][2] -= amount; // Update balance
        illusion();
        cout << "Withdrawal successful. New balance: " << users[loggedInUserIndex][2] << "\n" << endl;
        break;
    }
}

// Change PIN
void changePIN(int loggedInUserIndex) {
    int newPIN, confirmPIN;

    cout << "Enter your new 4-digit PIN: ";
    newPIN = getInt();

    if (newPIN < 1000 || newPIN > 9999) {
        cout << "Invalid PIN. It must be a 4-digit number. Try again.\n" << endl;
        return;
    }

    cout << "Confirm your new PIN: ";
    confirmPIN = getInt();

    if (newPIN == confirmPIN) {
        users[loggedInUserIndex][1] = newPIN; // Update PIN
        illusion();
        cout << "PIN changed successfully.\n" << endl;
    } else {
        cout << "PINs do not match. Try again.\n" << endl;
    }
}
