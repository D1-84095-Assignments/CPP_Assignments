#include<iostream>
using namespace std;
class Student
{
private:
        string name;
        char gender;
        int rollno;
        int marks[3];
        float per;
public:
        void accept()
        {
            cout<<"Enter name :";
            cin>>this->name;
            cout<<"Enter gender :";
            cin>>this->gender;
            cout<<"Enter Roll no : ";
            cin>>this->rollno;
            cout<<"Enter marks for three subjects out of 100"<<endl;
            cout<<"Marks : ";
            for(int i=0;i<3;i++)
                cin>>marks[i];
        }
        float calcPercentage()
        {
            int sum=0;
            for(int i=0;i<3;i++)
                sum=sum+this->marks[i];
            return (float)sum*100/300;
        }
        void print()
        {
           
            cout<<"Name : "<<this->name<<endl;
            cout<<"Gender : "<<this->gender<<endl;
            cout<<"Roll no : "<<this->rollno<<endl;
            cout<<"Percentage : "<<calcPercentage()<<endl;
        }
        int getRollno()
        {
            return this->rollno;
        }
       
};

void swap(Student &a, Student &b)
{
    Student temp;
    temp=a;
    a=b;
    b=temp;
}
int searchRecords(Student arr[],int rollno)
{
        for(int i=0;i<5;i++)
          {  if(arr[i].getRollno()==rollno)
            return i;}
            return -1;
}
void sortRecords(Student arr[])
{
        int min,j;
        for(int i=0;i<4;i++)
        {   
            min=i;
            for(j=i+1;j<5;j++)
            {
            if(arr[min].getRollno()>arr[j].getRollno())
            min=j;
            }
            swap(arr[min],arr[i]);
        }
}

enum EMenu
{
EXIT,ACCEPT,PRINT,SEARCH,SORT
};

int main()
{
    Student arr[5];
    int choice;
    int index;
    int rollno;
    do
    {
        cout<<"Enter your choice"<<endl;
        cout<<"0.EXIT"<<endl<<"1.ACCEPT"<<endl;
        cout<<"2.PRINT"<<endl<<"3.SEARCH"<<endl<<"4.SORT"<<endl;
        cin>>choice;

        switch(EMenu(choice))
        {
            case EXIT   :   cout<<"Thank you!"<<endl;
                            break;
            case ACCEPT :   for(int i=0;i<5;i++)
                                arr[i].accept();
                                break;
            case PRINT  :   cout<<"Student details : "<<endl;
                            for(int i=0;i<5;i++)
                                arr[i].print();
                            break;
            case SEARCH :   cout<<"Enter roll no of a student to search"<<endl;
                            cin>>rollno;
                            index=searchRecords(arr, rollno);
                            if(index!=-1)
                            arr[index].print();
                            break;
            case SORT   :   sortRecords(arr);
                            for(int i=0;i<5;i++)
                               { arr[i].print();
                               cout<<endl;}
        }
    }while(choice!=0);
    
    return 0;
}

