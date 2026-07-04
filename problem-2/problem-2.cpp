#include <iostream>
#include <string>
using namespace std;

class Account {
public:
    int accountNumber;
    string customerName;
    double balance;

    string history[100];
    int transactionCount = 0;
};

class Bank {
private:
    Account accounts[100];
    int totalAccounts = 0;

public:

    int findAccount(int accNo) {
        for (int i = 0; i < totalAccounts; i++) {
            if (accounts[i].accountNumber == accNo)
                return i;
        }
        return -1;
    }

    void openAccount() {
        cout << "Account Number: ";
        cin >> accounts[totalAccounts].accountNumber;

        cin.ignore();

        cout << "Customer Name: ";
        getline(cin, accounts[totalAccounts].customerName);

        cout << "Opening Balance: ";
        cin >> accounts[totalAccounts].balance;

        accounts[totalAccounts].history[0] =
            "Opened Account with " + to_string(accounts[totalAccounts].balance);

        accounts[totalAccounts].transactionCount++;

        totalAccounts++;

        cout << "Account Created Successfully.\n";
    }

    void deposit() {
        int accNo;
        double amount;

        cout << "Account Number: ";
        cin >> accNo;

        int index = findAccount(accNo);

        if (index == -1) {
            cout << "Account Not Found.\n";
            return;
        }

        cout << "Deposit Amount: ";
        cin >> amount;

        accounts[index].balance += amount;

        accounts[index].history[accounts[index].transactionCount++] =
            "Deposit: +" + to_string(amount);

        cout << "Deposit Successful.\n";
    }

    void withdraw() {
        int accNo;
        double amount;

        cout << "Account Number: ";
        cin >> accNo;

        int index = findAccount(accNo);

        if (index == -1) {
            cout << "Account Not Found.\n";
            return;
        }

        cout << "Withdraw Amount: ";
        cin >> amount;

        if (amount > accounts[index].balance) {
            cout << "Insufficient Balance.\n";
            return;
        }

        accounts[index].balance -= amount;

        accounts[index].history[accounts[index].transactionCount++] =
            "Withdraw: -" + to_string(amount);

        cout << "Withdrawal Successful.\n";
    }

    void transfer() {
        int sender, receiver;
        double amount;

        cout << "Sender Account: ";
        cin >> sender;

        cout << "Receiver Account: ";
        cin >> receiver;

        int s = findAccount(sender);
        int r = findAccount(receiver);

        if (s == -1 || r == -1) {
            cout << "Account Not Found.\n";
            return;
        }

        cout << "Transfer Amount: ";
        cin >> amount;

        if (amount > accounts[s].balance) {
            cout << "Insufficient Balance.\n";
            return;
        }

        accounts[s].balance -= amount;
        accounts[r].balance += amount;

        accounts[s].history[accounts[s].transactionCount++] =
            "Transfer To " + to_string(receiver) + ": -" + to_string(amount);

        accounts[r].history[accounts[r].transactionCount++] =
            "Received From " + to_string(sender) + ": +" + to_string(amount);

        cout << "Transfer Successful.\n";
    }

    void transactionHistory() {
        int accNo;

        cout << "Account Number: ";
        cin >> accNo;

        int index = findAccount(accNo);

        if (index == -1) {
            cout << "Account Not Found.\n";
            return;
        }

        cout << "\nTransaction History\n";

        for (int i = 0; i < accounts[index].transactionCount; i++) {
            cout << i + 1 << ". "
                 << accounts[index].history[i] << endl;
        }
    }

    void richestCustomer() {

        if (totalAccounts == 0) {
            cout << "No Accounts Found.\n";
            return;
        }

        int rich = 0;

        for (int i = 1; i < totalAccounts; i++) {
            if (accounts[i].balance > accounts[rich].balance)
                rich = i;
        }

        cout << "\nRichest Customer\n";
        cout << "Account Number: " << accounts[rich].accountNumber << endl;
        cout << "Customer Name : " << accounts[rich].customerName << endl;
        cout << "Balance       : " << accounts[rich].balance << endl;
    }
};

int main() {

    Bank bank;
    int choice;

    do {

        cout << "\n===== BANK MENU =====\n";
        cout << "1. Open Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Transfer Money\n";
        cout << "5. Transaction History\n";
        cout << "6. Richest Customer\n";
        cout << "7. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            bank.openAccount();
            break;

        case 2:
            bank.deposit();
            break;

        case 3:
            bank.withdraw();
            break;

        case 4:
            bank.transfer();
            break;

        case 5:
            bank.transactionHistory();
            break;

        case 6:
            bank.richestCustomer();
            break;

        case 7:
            cout << "Program Ended.\n";
            break;

        default:
            cout << "Invalid Choice.\n";
        }

    } while (choice != 7);

    return 0;
}
