#include <iostream>
#include <vector>
using namespace std;

enum Eaccount_type
{
    SAVING,
    CURRENT,
    DMAT
};
class insufficient_funds
{
private:
    int acc_id;
    double cur_balance;
    double withdraw_amount;

public:
    insufficient_funds(int acc_id, double cur_balance, double withdraw_amount)
    {
        this->acc_id = acc_id;
        this->cur_balance = cur_balance;
        this->withdraw_amount = withdraw_amount;
    }
    void display()
    {
        cout << "Insufficient fund account with : " << endl;
        cout << "Account id : " << this->acc_id << endl;
        cout << "Current balance : " << this->cur_balance << endl;
        cout << "Withdraw amount : " << this->withdraw_amount << endl;
    }
};

class Account
{
private:
    int id;
    Eaccount_type type;
    double balance;

public:
    Account()
    {
        this->id = 1;
        this->type = SAVING;
        this->balance = 1000;
    }
    Account(int id, Eaccount_type type, double balance)
    {
        this->id = id;
        this->type = type;
        this->balance = balance;
    }
    void accept()
    {
        cout << "Enter account details : " << endl;
        cout << "id : ";
        cin >> this->id;
        int t1;
        cout << "type : (Press 0 for CURRENT ACCOUNT, Press 1 for SAVINGS ACCOUNT, Press 2 for DMAT account)";
        cin >> t1;
        switch (t1)
        {
        case 0:
            type = CURRENT;
        case 1:
            type = SAVING;
        case 2:
            type = DMAT;
        }

        cout << "balance : ";
        cin >> this->balance;
    }
    void display()
    {
        cout << "Account details are : " << endl;
        cout << "id : " << this->id << endl;
        cout << "type : " << this->type << endl;
        cout << "balance : " << this->balance << endl;
    }
    int get_id()
    {

        return this->id;
    }
    void set_id(int id)
    {
        if (id <= 0)
            throw "id cannot be zeo or negative.";
        this->id = id;
    }
    Eaccount_type get_type()
    {
        if (this->type != SAVING && this->type != CURRENT && this->type != DMAT)
            throw "Type cannot be other than CURRENT,SAVING or DMAT";

        return this->type;
    }
    void set_type(Eaccount_type type1)
    {
        if (type1 != SAVING && type1 != CURRENT && type1 != DMAT)
            throw "Type cannot be other than CURRENT,SAVING or DMAT";
        this->type = type1;
    }
    double get_balance()
    {
        if (this->balance < 500)
            throw insufficient_funds(this->id, this->balance, 0);
        return this->balance;
    }

    void withdraw(double amount)
    {
        this->balance = this->balance - amount;
        if (this->balance < 500)
            throw insufficient_funds(this->id, this->balance, amount);
        cout << "Updated account balance : " << this->balance << endl;
    }
    void deposit(double amount)
    {
        this->balance = this->balance + amount;
        cout << "Updated account balance : " << this->balance << endl;
    }
};

Account create_account()
{

    int id;
    Eaccount_type type;
    double balance;

    cout << "\nEnter account id";
    cin >> id;
    if (id <= 0)
        throw 2;
    cout << "\nEnter account type";
    int t1;
    cout << "\ntype : (Press 0 for CURRENT ACCOUNT, Press 1 for SAVINGS ACCOUNT, Press 2 for DMAT account)";
    cin >> t1;
    switch (t1)
    {
    case 0:
        type = CURRENT;
    case 1:
        type = SAVING;
    case 2:
        type = DMAT;
    }

    if (type != SAVING && type != CURRENT && type != DMAT)
        throw 9.8;

    cout << "\nEnter balance" << endl;
    cin >> balance;
    if (balance < 1000)
        throw "Balance should be at least Rs.1000";

    Account acc_new(id, type, balance);
    return acc_new;
}

int main()
{
    int choice, amount;
    int search_id;
    Account new_acc;
    vector<Account *> a;

    for (int i = 0; i < 5; i++)
        a[i] = NULL;

    for (int i = 0; i < 5; i++)
    {
        
        try
        {
            *a[i] = create_account();
        }

        catch (int)
        {
            cout << "Id cannot be zero or negative";
        }
        catch (double)
        {
            cout << "Type cannot be other than CURRENT,SAVING or DMAT";
        }
        catch (const char *e)
        {
            cout << e;
        }
    }
    do
    {
        cout << "Enter your choice" << endl;
        cout << "0.Exit" << endl;
        cout << "1.Deposit" << endl;
        cout << "2.Withdraw" << endl;
        cout << "3.Display all accounts" << endl;

        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "ThankYou!" << endl;
            break;
        case 1:
            cout << "Enter an account id to deposit." << endl;
            cin >> search_id;

            for (int i = 0; i < a.size(); i++)
                if (a[i] != NULL && a[i]->get_id() == search_id)
                {
                    cout << "Enter an amount to deposit" << endl;
                    cin >> amount;
                    a[i]->deposit(amount);
                    break;
                }

            break;
        case 2:
            cout << "Enter an account id to withdraw." << endl;
            cin >> search_id;

            for (int i = 0; i < a.size(); i++)
                if (a[i] != NULL && a[i]->get_id() == search_id)
                {
                    cout << "Enter an amount to withdraw" << endl;
                    cin >> amount;
                    try
                    {
                        a[i]->withdraw(amount);
                    }

                    catch (insufficient_funds e)
                    {
                        e.display();
                    }
                    break;
                }
        case 3:
        
            for (int i = 0; i < a.size(); i++)
                {
                    if( a[i] != NULL )
                    a[i]->display();
                }
                }
    } while (choice != 0);

    try
    {
        (a[0]->get_balance());
    }
    catch (insufficient_funds e)
    {
        e.display();
    }

    for (int i = 0; i < a.size(); i++)
    {
    if (a[i] != NULL)
        delete a[i];
    }
    return 0;
}