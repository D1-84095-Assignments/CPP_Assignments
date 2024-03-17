#include<iostream>
using namespace std;

void factorial(int num)
{
    if(num<=0)
        throw "Number should not be negative or zero";
    int fact=1;
    for(int i=2;i<=num;i++)
        fact=fact*i;

    cout<<"Fctorial of given number is : "<<fact<<endl;
}

int main()
{
    int num;
    cout<<"Enter number to find factorial"<<endl;
    cin>>num;

    try
    {
        {factorial(num);}
    }
    catch(const char* message)
    {
        cout<<message<<endl;
    }
    
}