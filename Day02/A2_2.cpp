#include<iostream>
using namespace std;
class Tollbooth
{
private:
        unsigned int carTotal;
        double cashTotal;
public:
        Tollbooth()
        {
            this->carTotal=0;
            this->cashTotal=0;
        }
        void payingCar()
        {
            this->carTotal++;
            this->cashTotal+=0.5;
        }
        void nopayCar()
        {
            this->carTotal++;
        }
        void printtOnConsole()
        {
            cout<<"Total number of paying as well as nonpaying cars is : "<<this->carTotal<<endl;
            cout<<"Total amount of money collected :"<<this->cashTotal<<endl;
        }

};
int menu()
{
    int choice;
    cout<<"Enter your choice"<<endl;
    cout<<"0.Exit"<<endl<<"1.Add paying car"<<endl<<"2.Add non-paying car"<<endl;
    cout<<"3.Display total number of cars and total money calculated"<<endl;
    cin>>choice;
    return choice;
}
int main()
{
    Tollbooth t;
    int choice;
    while((choice=menu())!=0)
    {
        switch(choice)
        {
            case 1: t.payingCar();
                    break;
            case 2: t.nopayCar();
                    break;
            case 3: t.printtOnConsole();
                    break;
            default: cout<<"Invalid choice"<<endl;
                    break;

        }

    }
}