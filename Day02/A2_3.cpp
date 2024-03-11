#include<iostream>
using namespace std;
namespace NStudent
{
   
    class Student
    {
    private:   
            int rollno;
            string name;
            float marks;
    public:
            void initStudent()
            {
            this->rollno=1;
            this->name="Rashmi";
            this->marks=40.0;
            }
            void printStudentOnConsole()
            {
            cout<<"Student details are:"<<endl;
            cout<<"Roll No : "<<this->rollno<<endl;
            cout<<"Name : "<<this->name<<endl;
            cout<<"Marks :"<<this->marks<<endl;
            }
            void acceptStudentFromConsole()
            {
            cout<<"Enter student details:"<<endl;
            cout<<"Roll no :";
            cin>>this->rollno;
            cout<<"Name :";
            cin>>this->name;
            cout<<"Marks :";
            cin>>this->marks;
            }
    };
}

int menu()
{
    int choice;
    cout<<"Enter your choice"<<endl;
    cout<<"0.Exit"<<endl<<"1.Initialise student details"<<endl;
    cout<<"2.Print student details on console"<<endl<<"3.Accept student details on console"<<endl;
    cin>>choice;
    return choice;
}
using namespace NStudent;
int main()
{
    Student s1;
    int choice;
    while((choice=menu())!=0)
    {
        switch(choice)
        {
            case 1: s1.initStudent();
                    break;
            case 2: s1.printStudentOnConsole();
                    break;
            case 3: s1.acceptStudentFromConsole();
                    break;
            default: cout<<"Invalid choice"<<endl;

        }
    }
}
