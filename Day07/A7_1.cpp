#include <iostream>
using namespace std;

class Employee
{
private:
    int eid;
    float salary;

public:
    Employee()
    {
        this->eid = 1;
        this->salary = 2000;
    }
    Employee(int eid, float salary)
    {
        this->eid = eid;
        this->salary = salary;
    }
    int get_eid()
    {
        return this->eid;
    }
    void set_eid(int eid)
    {
        this->eid = eid;
    }
    float get_salary()
    {
        return this->salary;
    }
    void set_salary(float salary)
    {
        this->salary = salary;
    }
    virtual void accept()
    {
        cout << "Enter Employee details : " << endl;
        cout << "Eid : ";
        cin >> this->eid;
        cout << "Salary : ";
        cin >> this->salary;
    }
    virtual void display()
    {
        cout << "Employee details are : " << endl;
        cout << "Eid : " << this->eid << endl;
        cout << "Salary : " << this->salary << endl;
    }
    virtual ~Employee()
    {
        cout << "Employee destructor" << endl;
    }
};

class Manager : virtual public Employee
{
private:
    float bonus;

protected:
    void accept_manager()
    {
        cout << "Enter bonus : ";
        cin >> this->bonus;
    }
    void display_manager()
    {
        cout << "Bonus : " << this->bonus << endl;
    }

public:
    Manager()
    {
        this->bonus = 500;
    }
    Manager(float bonus)
    {
        this->bonus = 500;
    }

    Manager(int eid, float salary, float bonus) : Employee(eid, salary)
    {

        this->bonus = bonus;
    }
    float get_bonus()
    {
        return this->bonus;
    }
    void set_bonus(float bonus)
    {
        this->bonus = bonus;
    }
    void accept()
    {
        Employee::accept();
        cout << "Enter bonus : ";
        cin >> this->bonus;
    }

    virtual void display()
    {
        Employee::display();
        cout << "Bonus : " << this->bonus << endl;
    }
};

class Salesman : virtual public Employee
{
private:
    float comm;

protected:
    void accept_salesman()
    {
        cout << "Enter commission : ";
        cin >> this->comm;
    }
    void display_salesman()
    {
        cout << "Commission : ";
        cout << this->comm << endl;
    }

public:
    Salesman()
    {
        this->comm = 1000;
    }
    Salesman(float comm)
    {
        this->comm = comm;
    }
    Salesman(int eid, float salary, float comm) : Employee(eid, salary)
    {
        this->comm = comm;
    }
    float get_comm()
    {
        return this->comm;
    }
    void set_comm(float comm)
    {
        this->comm = comm;
    }
    virtual void accept()
    {
        Employee::accept();
        cout << "Commission : ";
        cin >> comm;
    }
    virtual void display()
    {
        Employee::display();
        cout << "Commission : " << this->comm << endl;
    }
};

class Sales_Manager : public Manager, public Salesman
{
public:
    Sales_Manager()
    {
    }
    Sales_Manager(int eid, float salary, float bonus, float comm) : Employee(eid, salary), Manager(bonus), Salesman(comm)
    {
    }
    void accept()
    {
        Employee::accept();
        Manager::accept_manager();
        Salesman::accept_salesman();
    }
    void display()
    {
        Employee::display();
        Manager::display_manager();
        Salesman::display_salesman();
    }
};

int menu()
{
    int choice;
    cout << "Enter your choice" << endl;
    cout << "1.Accept Manager" << endl;
    cout << "2.Accept Salesman" << endl;
    cout << "3.Accept Sales_Manager" << endl;
    cout << "4.Display count of all employees with respect to designation" << endl;
    cout << "5.Display all managers" << endl;
    cout << "6.Display all salesman" << endl;
    cout << "7.Display all sales managers" << endl;
    cin >> choice;
    return choice;
}

int main()
{
    int choice;
    Employee *eptr[10];
    int count = 0;
    int countM;
    int countS;

    int countSM;

    while ((choice = menu()) != 0)
    {
        switch (choice)
        {

        case 1:
            eptr[count] = new Manager();
            eptr[count]->accept();

            count++;
            break;

        case 2:
            eptr[count] = new Salesman();
            eptr[count]->accept();

            count++;

            break;

        case 3:
            eptr[count] = new Sales_Manager();
            eptr[count]->accept();

            count++;
            break;

        case 4:

            countM = 0;
            countS = 0;
            countSM = 0;

            cout
                << "Total number of employees = " << count << endl;

            for (int i = 0; i < count; i++)
            {
                if (typeid(*eptr[i]) == typeid(Manager))
                    countM++;

                if (typeid(*eptr[i]) == typeid(Salesman))
                    countS++;

                if (typeid(*eptr[i]) == typeid(Sales_Manager))

                    countSM++;
            }
            cout << "Number of Manager = " << countM << endl;
            cout << "Number of Salesman = " << countS << endl;
            cout << "Number of Salesmanager = " << countSM << endl;
            break;

        case 5:

            for (int i = 0; i < count; i++)
            {
                if (typeid(*eptr[i]) == typeid(Manager))
                {
                    eptr[i]->display();
                }
                eptr[i]->display();
                cout << endl;
            }
            break;
        case 6:
            for (int i = 0; i < count; i++)
            {
                if (typeid(*eptr[i]) == typeid(Salesman))
                    eptr[i]->display();
                cout << endl;
            }
            break;
        case 7:
            for (int i = 0; i < count; i++)
            {
                if (typeid(*eptr[i]) == typeid(Sales_Manager))
                    eptr[i]->display();
                cout << endl;
            }
            break;
        }
    }
    for (int i = 0; i < count; i++)
    {
        delete eptr[i];
        eptr[i] = NULL;
    }
    return 0;
}