#include <bits/stdc++.h>
using namespace std;

// Base class that stores Bank Name
class accountbase {
protected:
    string bankname;

public:
    accountbase(string bankname) { this->bankname = bankname; }

    string getBankName() { return bankname; }
};

// Interface = can deposit only
class notwithdraw {
public:
    virtual void deposite(double amount) = 0;
};

// Interface = can deposit + withdraw
class withdraw : public notwithdraw {
public:
    virtual void withdraws(double amount) = 0;
    virtual string getBankName() = 0;   // <-- IMPORTANT FIX
};

// ------------------- Saving Account -------------------
class savingaccount : public withdraw, public accountbase {
private:
    double balance;

public:
    savingaccount(string bankname) : accountbase(bankname) { balance = 0; }

    void deposite(double amount) {
        balance += amount;
        cout << "Deposited in Saving (" << bankname << "): " 
             << amount << " | Balance: " << balance << endl;
    }

    void withdraws(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawn from Saving (" << bankname << "): "
                 << amount << " | Balance: " << balance << endl;
        } else {
            cout << "Insufficient funds in Saving (" << bankname << ")!" << endl;
        }
    }

    string getBankName() override { return bankname; }
};

// ------------------- Current Account -------------------
class currentaccount : public withdraw, public accountbase {
private:
    double balance;

public:
    currentaccount(string bankname) : accountbase(bankname) { balance = 0; }

    void deposite(double amount) {
        balance += amount;
        cout << "Deposited in Current (" << bankname << "): "
             << amount << " | Balance: " << balance << endl;
    }

    void withdraws(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawn from Current (" << bankname << "): "
                 << amount << " | Balance: " << balance << endl;
        } else {
            cout << "Insufficient funds in Current (" << bankname << ")!" << endl;
        }
    }

    string getBankName() override { return bankname; }
};

// ------------------- Fixed Deposit Account -------------------
class fixeddepositaccount : public notwithdraw, public accountbase {
private:
    double balance;

public:
    fixeddepositaccount(string bankname) : accountbase(bankname) { balance = 0; }

    void deposite(double amount) {
        balance += amount;
        cout << "Deposited in Fixed Deposit (" << bankname << "): "
             << amount << " | Balance: " << balance << endl;
    }
};

// ------------------- BANK CLIENT -------------------
class bankclient {
private:
    vector<notwithdraw*> accounts;
    vector<withdraw*> withdrawableaccounts;

public:
    bankclient(vector<notwithdraw*> &acc, vector<withdraw*> &wacc) {
        accounts = acc;
        withdrawableaccounts = wacc;
    }

    void process() {
        for (auto *acc : accounts)
            acc->deposite(1000);
            

        for (auto *wacc : withdrawableaccounts) {
            wacc->deposite(2000);
            wacc->withdraws(500);
        }
    }

    void withdrawFromBank(string bankName, double amount) {
        for (auto *w : withdrawableaccounts) {
            if (w->getBankName() == bankName) {   // FIXED
                w->withdraws(amount);
                return;
            }
        }
        cout << "No withdrawable account found for bank: " << bankName << endl;
    }
};

// ------------------- MAIN -------------------
int main() {
    vector<notwithdraw*> accounts;
    vector<withdraw*> withdrawableaccounts;

    accounts.push_back(new fixeddepositaccount("Bank A"));
    withdrawableaccounts.push_back(new savingaccount("Bank B"));
    withdrawableaccounts.push_back(new currentaccount("Bank C"));

    bankclient *client = new bankclient(accounts, withdrawableaccounts);

    cout << "\n--- Default Processing ---\n";
    client->process();

    cout << "\n--- Withdraw Using Bank Name ---\n";
    client->withdrawFromBank("Bank B", 200);
    client->withdrawFromBank("Bank C", 300);
    client->withdrawFromBank("Bank D", 400);

    return 0;
}
