#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

class BankAccount
{
private:
    static int totalAccount;
    double account_num;
    double balance;
    string customer_name;

public:
    BankAccount() : account_num(0), balance(0.00), customer_name("")
    {
    }
    BankAccount(double account_num, double balance, string customer_name) : account_num(account_num), balance(balance), customer_name(customer_name)
    {
        totalAccount += 1;
    }
    BankAccount(const BankAccount &orig) : balance(orig.balance), customer_name(orig.customer_name) {}

    double getAccountNum() const
    {
        return account_num;
    }
    double getBalance() const
    {
        return balance;
    }
    string getCustomerName() const
    {
        return customer_name;
    }

    static int getTotalAccount()
    {
        return totalAccount;
    }

    void setAccountNum(const double account_num)
    {
        this->account_num = account_num;
    }
    void setBalance(const double balance)
    {
        this->balance = balance;
    }
    void setCustomerName(const string customer_name)
    {
        this->customer_name = customer_name;
    }

    void depositing(double newBalance)
    {
        this->balance += newBalance;
        cout << "You have deposited $" << newBalance << ". Your new balance is $" << balance << endl;
    }

    void withdraw(double withdraw)
    {
        if (balance >= withdraw)
        {
            balance -= withdraw;
            cout << "You have withdraw $" << withdraw << " amount." << endl;
            cout << "Your new balance is $" << balance << "." << endl;
        }
        else if ((balance - withdraw) < 0)
        {
            cout << "You have not sufficient amount." << endl;
        }
        else
        {
            cout << "Your balance is empty." << endl;
        }
    }

    void checking() const
    {
        cout << "You have $" << getBalance() << " amount in your account." << endl;
    }

    static double accountNumbers()
    {

        srand(static_cast<unsigned>(time(0)));

        static double account_num = rand() % 99999 + 100000;
        cout << account_num << endl;
    }

    void display() const
    {
        cout << "Account holder name: " << getCustomerName() << endl;
        cout << "Account Number is " << getAccountNum() << endl;
        cout << "Your balance is $" << getBalance() << endl;
        cout << "Total accounts: " << totalAccount << endl;
    }

    ~BankAccount()
    {
        cout << "Account "<<customer_name<<" has been closed." << endl;
    }
};

int BankAccount::totalAccount = 0;

int main()
{
    BankAccount b(5554, 5600, "Umar awan");
    b.display();
    b.depositing(400);
    b.withdraw(6000);
    b.withdraw(2);
    b.accountNumbers();
    BankAccount b1(44332, 10003, "Bilal Awan");
    b1.display();
    BankAccount b2(1122,29994, "Talha");
    b2.display();

    return 0;
}