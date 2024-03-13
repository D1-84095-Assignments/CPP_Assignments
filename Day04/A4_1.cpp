#include<iostream>
using namespace std;

class Date
{
private :
        int day;
        int month;
        int year;
public:
        Date()
        {
        this->day=1;
        this->month=1;
        this->year=1990;
        
        }
        Date(int day, int month, int year)
        {
        this->day=day;
        this->month=month;
        this->year=year;
        }
        void accept()
        {
        cout<<"Enter day, month and year in a date : "<<endl;
        cout<<"Day : ";
        cin>>this->day;
        cout<<"Month : ";
        cin>>this->month;
        cout<<"Year :";
        cin>>this->year;
        }
        void display()
        {
        cout<<"Date : "<<endl;
        cout<<this->day<<"-"<<this->month<<"-"<<this->year<<endl;

        }
        int get_day()
        {
        return this->day;
        }
        int get_month()
        {
        return this->month;
        }
        int get_year()
        {
        return this->year;
        }
        void set_day(int day)
        {
        this->day=day;
        }
        void set_month(int month)
        {
        this->month=month;
        }
        void set_year(int year)
        {
        this->year=year;
        }
        bool is_leap_year()
        {
        if(((this->year%4==0)&& (this->year%100!=0)) || this->year%400==0)
                return true;
        else    return false;
        }
        

};



class Person
{
private : 
        string name;
        string address;
        Date birthdate;
public:
        Person()
        {
        this->name="Roshni";
        this->address="Rajkamal Square";
        this->birthdate= Date();
        }
        Person(string name, string address, int dd, int mm, int yy):birthdate(dd,mm,yy)
        {
        this->name=name;
        this->address=address;
        }
        void accept()
        {
        cout<<"Enter name : ";
        cin>>this->name;
        cout<<"Enter address : ";
        cin>>this->address;
        cout<<"Enter birthdate : ";
        birthdate.accept();
        }
        void display()
        {
        cout<<"Person details are : "<<endl;
        cout<<"Name : "<<this->name<<endl;
        cout<<"Address :"<<this->address<<endl;
        cout<<"Birthdate : "<<endl;
        birthdate.display();

        }
        string get_name()
        {
        return this->name;

        }
        string get_address()
        {
        return this->address;
        }
        Date get_birthdate()
        {
        return this->birthdate;
        }
        void set_name(string name)
        {
        this->name=name;
        }
        void set_address(string address)
        {
        this->address=address;
        }
        void set_birthdate(Date birthdate)
        {
        this->birthdate=birthdate;
        }

};

class Employee
{
private:   
        int eid;
        float salary;
        string dept;
        Date joining;
public:
        Employee()
        {
        this->eid=1;
        this->salary=200;
        this->dept="Labor";
        this->joining=Date();
        }
        Employee(int eid, float salary, string dept, int dd,int mm, int yy):joining(dd,mm,yy)
        {
        this->eid=eid;
        this->salary=salary;
        this->dept=dept;

        }
        void accept()
        {  
        cout<<"<Enter employee details : "<<endl;
        cout<<"Id : ";
        cin>>this->eid;
        cout<<"Salary : ";
        cin>>this->salary;
        cout<<"Dept : ";
        cin>>this->dept;
        this->joining.accept();

        }
        void display()
        {
        cout<<"Employee details : "<<endl;
        cout<<"Id : "<<this->eid<<endl;
        cout<<"Salary : "<<this->salary<<endl;
        cout<<"Dept : "<<this->dept<<endl;
        cout<<"Joining date : "<<endl;
        this->joining.display();
        }
        int get_eid()
        {
        return this->eid;

        }
        float get_salary()
        {
        return this->salary;

        }
        string get_dept()
        {
        return this->dept;
        }
        Date get_joining()
        {
        return this->joining;
        }
        void set_eid(int eid)
        {
        this->eid=eid;

        }
        void set_salary(float salary)
        {
        this->salary=salary;
        }
        void set_dept(string dept)
        {
        this->dept=dept;
        }
        void set_joining(Date joining)
        {
        this->joining=joining;
        }
};

int main()
{
        Date d;
        d.accept();
        d.display();
        bool b= d.is_leap_year();
                if(b)
                cout<<"Year is a leap year"<<endl;
                else cout<<"Year is not a leap year"<<endl;

        Person p;
        p.accept();
        p.display();

        Employee e(2,2000,"Salary",3,4,1990);
        e.display();
        


        return 0;
}