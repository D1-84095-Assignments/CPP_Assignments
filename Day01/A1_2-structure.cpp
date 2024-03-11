#include<iostream>
using namespace std;
struct Date
{
 private:   
        int day;
        int month;
        int year;
public:
        void initDate()
        {
        this->day=1;
        this->month=1;
        this->year=2001;
        }
        void printDateOnConsole()
        {
        cout<<"Date is:"<<this->day<<"-"<<this->month<<"-"<<this->year<<endl;
        }
        void acceptDateFromConsole()
        {
            cout<<"Enter day, month and year of a date"<<endl;
            cin>>this->day>>this->month>>this->year;
        }
        bool isLeapYear()
        {
            if((this->year%4==0 && this->year%100!=0)|| (this->year%400==0))
                return true;
            else return false;
        }

};
int menu()
{
    int choice;
    cout<<"Enter your choice"<<endl;
    cout<<"0.Exit"<<endl<<"1.Initialise date"<<endl;
    cout<<"2.Print date on console"<<endl<<"3.Accept date from console"<<endl;
    cout<<"4.Check if leap year"<<endl;
    cin>>choice;
    return choice;
}
int main()
{
    Date d;
    int choice;
    while((choice = menu())!=0)
        {
            switch(choice)
            {
                case 1:d.initDate();
                        break;
                case 2:d.printDateOnConsole();
                        break;
                case 3:d.acceptDateFromConsole();
                        break;
                case 4:if (d.isLeapYear())
                        cout<<"Entered year is a leap year"<<endl;
                        else cout<<"Entered year is not a leap year"<<endl;
                        break;
                default:cout<<"Invalid choice"<<endl;

            }
        }

    return 0;
}
