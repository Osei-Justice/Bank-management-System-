
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {

    // Customer information arrays
    string names[5];
    string accountNumbers[5];
    string pins[5];
    double balances[5];

    // Program variablesS
    int totalCustomers = 0;
    int choice;
    bool running = true;

    // Banking menu
    while (running) {

        cout << "\n====================================" << endl;
        cout << "       BANKING MANAGEMENT SYSTEM" << endl;
        cout << "====================================" << endl;

        cout << "1. Create Account" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Transfer Money" << endl;
        cout << "5. Check Account Balance" << endl;
        cout << "6. Calculate Account Interest" << endl;
        cout << "7. Display All Customers" << endl;
        cout << "8. Exit" << endl;

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {

            
case 1: {

    if (totalCustomers >= 5) {
        cout << "\nSorry! Maximum customer limit reached." << endl;
        break;
    }

    cout << "\nEnter Customer Name: ";
    cin.ignore();
    getline(cin, names[totalCustomers]);

    cout << "Enter Account Number: ";
    cin >> accountNumbers[totalCustomers];

    // Check for duplicate account numbers
    bool duplicate = false;

    for (int i = 0; i < totalCustomers; i++) {

        if (accountNumbers[i] == accountNumbers[totalCustomers]) {
            duplicate = true;
            break;
        }
    }

    if (duplicate) {
        cout << "\nAccount number already exists!" << endl;
        break;
    }

    // Validate four-digit PIN
cout << "Create 4-digit PIN: ";
cin >> pins[totalCustomers];

bool validPIN = (pins[totalCustomers].length() == 4);

for (int i = 0; i < 4; i++) {
    if (pins[totalCustomers][i] < '0' ||
        pins[totalCustomers][i] > '9') {
        validPIN = false;
    }
}

if (!validPIN) {
    cout << "\nInvalid PIN! Enter exactly four digits." << endl;
    break;
}

    balances[totalCustomers] = 100.00;

    totalCustomers++;

    cout << "\nAccount Created Successfully!" << endl;
    cout << "Initial Balance: GHc 100.00" << endl;

    break;
}


           
case 2: {
    if (totalCustomers == 0) {
        cout << "\nNo customer accounts registered yet!" << endl;
        break;
    }

    string searchAccount;
    cout << "\nEnter Account Number: ";
    cin >> searchAccount;

    int customerIndex = -1;

    // Search for the account
    for (int i = 0; i < totalCustomers; i++) {
        if (accountNumbers[i] == searchAccount) {
            customerIndex = i;
            break;
        }
    }

    // Check whether the account exists
    if (customerIndex == -1) {
        cout << "\nAccount not found!" << endl;
        break;
    }

    double amount;

    cout << "Enter Deposit Amount: GHc ";
    cin >> amount;

    // Validate the deposit amount
    if (amount <= 0) {
        cout << "\nInvalid amount! Deposit must be greater than zero." << endl;
        break;
    }

    // Update the customer's balance
    balances[customerIndex] += amount;

    cout << "\nDeposit Successful!" << endl;
    cout << "Deposited Amount: GHc "
         << fixed << setprecision(2) << amount << endl;

    cout << "Updated Balance: GHc "
         << balances[customerIndex] << endl;

    break;
}


            
case 3: {
    if (totalCustomers == 0) {
        cout << "\nNo customer accounts registered yet!" << endl;
        break;
    }

    string searchAccount;
    cout << "\nEnter Account Number: ";
    cin >> searchAccount;

    int customerIndex = -1;

    for (int i = 0; i < totalCustomers; i++) {
        if (accountNumbers[i] == searchAccount) {
            customerIndex = i;
            break;
        }
    }

    if (customerIndex == -1) {
        cout << "\nAccount not found!" << endl;
        break;
    }

    string enteredPIN;
    int attempts = 0;
    bool pinVerified = false;

    do {
        cout << "Enter your 4-digit PIN: ";
        cin >> enteredPIN;

        if (enteredPIN == pins[customerIndex]) {
            pinVerified = true;
        } else {
            attempts++;
            cout << "Incorrect PIN! Attempts remaining: "
                 << 3 - attempts << endl;
        }

    } while (!pinVerified && attempts < 3);

    if (!pinVerified) {
        cout << "\nTransaction cancelled! Too many incorrect PIN attempts." << endl;
        break;
    }

    double amount;
    cout << "Enter Withdrawal Amount: GHc ";
    cin >> amount;

    if (amount <= 0) {
        cout << "\nInvalid amount! Withdrawal must be greater than zero." << endl;
        break;
    }

    double fee = 0;

    if (amount > 500) {
        fee = 2;
    }

    double totalDeduction = amount + fee;

    if (totalDeduction > balances[customerIndex]) {
        cout << "\nInsufficient balance!" << endl;
        cout << "Available Balance: GHc "
             << balances[customerIndex] << endl;
        cout << "Required Amount Including Fee: GHc "
             << totalDeduction << endl;
        break;
    }

    balances[customerIndex] -= totalDeduction;

    cout << "\nWithdrawal Successful!" << endl;
    cout << "Withdrawal Amount: GHc " << amount << endl;
    cout << "Transaction Fee: GHc " << fee << endl;
    cout << "Updated Balance: GHc "
         << balances[customerIndex] << endl;

    break;
}


case 4: {
    if (totalCustomers < 2) {
        cout << "\nAt least two customer accounts are required for a transfer." << endl;
        break;
    }

    string senderAccount, receiverAccount;

    cout << "\nEnter Sender Account Number: ";
    cin >> senderAccount;

    int senderIndex = -1;

    for (int i = 0; i < totalCustomers; i++) {
        if (accountNumbers[i] == senderAccount) {
            senderIndex = i;
            break;
        }
    }

    if (senderIndex == -1) {
        cout << "\nSender account not found!" << endl;
        break;
    }

    cout << "Enter Receiver Account Number: ";
    cin >> receiverAccount;

    int receiverIndex = -1;

    for (int i = 0; i < totalCustomers; i++) {
        if (accountNumbers[i] == receiverAccount) {
            receiverIndex = i;
            break;
        }
    }

    if (receiverIndex == -1) {
        cout << "\nReceiver account not found!" << endl;
        break;
    }

    if (senderIndex == receiverIndex) {
        cout << "\nYou cannot transfer money to the same account!" << endl;
        break;
    }

    string enteredPIN;
    int attempts = 0;
    bool pinVerified = false;

    do {
        cout << "Enter Sender's 4-digit PIN: ";
        cin >> enteredPIN;

        if (enteredPIN == pins[senderIndex]) {
            pinVerified = true;
        } else {
            attempts++;
            cout << "Incorrect PIN! Attempts remaining: "
                 << 3 - attempts << endl;
        }

    } while (!pinVerified && attempts < 3);

    if (!pinVerified) {
        cout << "\nTransfer cancelled! Too many incorrect PIN attempts." << endl;
        break;
    }

    double amount;
    cout << "Enter Transfer Amount: GHc ";
    cin >> amount;

    if (amount <= 0) {
        cout << "\nInvalid transfer amount!" << endl;
        break;
    }

    double fee = 0;

    if (amount > 1000) {
        fee = 5;
    }

    double totalDeduction = amount + fee;

    if (totalDeduction > balances[senderIndex]) {
        cout << "\nInsufficient funds to complete transfer!" << endl;
        cout << "Sender's Balance: GHc "
             << balances[senderIndex] << endl;
        cout << "Required Amount Including Fee: GHc "
             << totalDeduction << endl;
        break;
    }

    // Update both accounts only after all checks pass
    balances[senderIndex] -= totalDeduction;
    balances[receiverIndex] += amount;

    cout << "\nTransfer Successful!" << endl;
    cout << "Amount Transferred: GHc " << amount << endl;
    cout << "Transfer Fee: GHc " << fee << endl;
    cout << "Sender's Updated Balance: GHc "
         << balances[senderIndex] << endl;
    cout << "Receiver's Updated Balance: GHc "
         << balances[receiverIndex] << endl;

    break;
}


            
case 5: {
    if (totalCustomers == 0) {
        cout << "\nNo customer accounts registered yet!" << endl;
        break;
    }

    string searchAccount;
    cout << "\nEnter Account Number: ";
    cin >> searchAccount;

    int customerIndex = -1;

    for (int i = 0; i < totalCustomers; i++) {
        if (accountNumbers[i] == searchAccount) {
            customerIndex = i;
            break;
        }
    }

    if (customerIndex == -1) {
        cout << "\nAccount not found!" << endl;
        break;
    }

    cout << "\nAccount Holder: "
         << names[customerIndex] << endl;

    cout << "Account Number: "
         << accountNumbers[customerIndex] << endl;

    cout << "Current Balance: GHc "
         << fixed << setprecision(2)
         << balances[customerIndex] << endl;

    break;
}


           
case 6: {
    if (totalCustomers == 0) {
        cout << "\nNo customer accounts registered yet!" << endl;
        break;
    }

    string searchAccount;
    cout << "\nEnter Account Number: ";
    cin >> searchAccount;

    int customerIndex = -1;

    for (int i = 0; i < totalCustomers; i++) {
        if (accountNumbers[i] == searchAccount) {
            customerIndex = i;
            break;
        }
    }

    if (customerIndex == -1) {
        cout << "\nAccount not found!" << endl;
        break;
    }

    double rate;

    if (balances[customerIndex] < 1000) {
        rate = 0.02;
    }
    else if (balances[customerIndex] < 5000) {
        rate = 0.04;
    }
    else if (balances[customerIndex] < 10000) {
        rate = 0.06;
    }
    else {
        rate = 0.08;
    }

    double interest = balances[customerIndex] * rate;

    cout << "\nInterest Calculation Successful!" << endl;
    cout << "Account Holder: "
         << names[customerIndex] << endl;

    cout << "Current Balance: GHc "
         << balances[customerIndex] << endl;

    cout << "Interest Rate: " << rate * 100 << "%" << endl;

    cout << "Interest Earned: GHc "
         << interest << endl;

    balances[customerIndex] += interest;

    cout << "New Account Balance: GHc "
         << balances[customerIndex] << endl;

    break;
}

            
case 7: {
    if (totalCustomers == 0) {
        cout << "\nNo customers registered yet!" << endl;
        break;
    }

    cout << "\n====================================" << endl;
    cout << "         REGISTERED CUSTOMERS" << endl;
    cout << "====================================" << endl;

    for (int i = 0; i < totalCustomers; i++) {
        cout << "\nCustomer " << i + 1 << endl;

        cout << "Name: "
             << names[i] << endl;

        cout << "Account Number: "
             << accountNumbers[i] << endl;

        cout << "Balance: GHc "
             << fixed << setprecision(2)
             << balances[i] << endl;

        cout << "------------------------------------" << endl;
    }

    cout << "\nTotal Registered Customers: "
         << totalCustomers << endl;

    break;
}

            
case 8: {
    cout << "\nThank you for using our Banking Management System!" << endl;
    cout << "Goodbye!" << endl;

    running = false;
    break;
}

        }
    }

    return 0;
}
