#include<iostream>
using namespace std;

class Employee
{
protected: int eid;
          float salary;

public:   Employee()
        {
            this->eid=1;
            this->salary=2000;
        }
        Employee(int eid, float salary)
        {
            this->eid=eid;
            this->salary=salary;
        }
        int get_eid()
        {
            return this->eid;
        }
        void set_eid(int eid)
        {
            this->eid=eid;
        }
        float get_salary()
        {
            return this->salary;
        }
        void set_salary(float salary)
        {
            this->salary=salary;
        }
        virtual void accept()
        {
            cout<<"Enter Employee details : "<<endl;
            cout<<"Eid : ";
            cin>>this->eid;
            cout<<"Salary : ";
            cin>>this->salary;
        }
        virtual void display()
        {
            cout<<"Employee details are : "<<endl;
            cout<<"Eid : "<<this->eid<<endl;
            cout<<"Salary : "<<this->salary<<endl;
        }
       virtual ~Employee()
        {
            cout<<"Employee destructor"<<endl;
        }

};

class Manager : virtual public Employee
{
private: float bonus;
protected: 
        void accept_manager()
        {
            cout<<"Enter bonus : ";
            cin>>this->bonus;
        }
        void display_manager()
        {
            cout<<"Bonus : "<<this->bonus<<endl;
        }
public:
        Manager()
        {
            this->bonus=500;
        }
        Manager(float bonus)
        {
            this->bonus=500;
        }
    
        Manager(int eid, float salary, float bonus):Employee(eid,salary)
        {
           
            this->bonus=bonus;
        }
        float get_bonus()
        {
            return this->bonus;
        }
        void set_bonus(float bonus)
        {
            this->bonus=bonus;
        }
        void accept()
        {
            Employee::accept();
            cout<<"Enter bonus : ";
            cin>>this->bonus;
        }
        
        virtual void display()
        {
            Employee::display();
            cout<<"Bonus : "<<this->bonus<<endl;

        }

};

class Salesman : virtual public Employee
{
private:  float comm;
protected: 
            void accept_salesman()
            {
                cout<<"Enter commission : ";
                cin>>this->comm;
            }
            void display_salesman()
            {
                cout<<"Commission : ";
                cout<<this->comm<<endl;
            }


public: 
            Salesman()
            {
                this->comm=1000;
            }
            Salesman(float comm)
            {
                this->comm=comm;
            }
            Salesman(int eid, float salary, float comm):Employee(eid,salary)
            {
                this->comm=comm;
            }
            float get_comm()
            {
                return this->comm;
            }
            void set_comm(float comm)
            {
                this->comm=comm;
            }
            virtual void accept()
            {
                Employee::accept();
                cout<<"Commission : ";
                cin>>comm;
            }
            virtual void display()
            {
                Employee::display();
                cout<<"Commission : "<<this->comm<<endl;
            }
            
};

class Sales_Manager:  public Manager,  public Salesman
{
public:
        Sales_Manager()
        {

        }
        Sales_Manager(int eid, float salary, float bonus, float comm):Employee (eid,salary),Manager(bonus),Salesman(comm)
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
int main()
{
    Employee e;
    e.accept();
    e.display();

    Salesman s;
    s.accept();
    s.display();

    Sales_Manager sm;
    sm.accept();
    sm.display();

    Employee *e1=new Manager();
    e1->accept();
    e1->display();
    delete e1;

    Employee *e2=new Salesman();
    e2->accept();
    e2->display();
    delete e2;

    Employee *e3=new Sales_Manager();
    e3->accept();
    e3->display();     

    Employee *e4=new Sales_Manager(4,5000,300,400);
    e4->display();

    Employee *e5[2]={new Manager(3,4000,500),new Salesman(4,5000,200)};
    e5[0]->display();

    return 0;
}