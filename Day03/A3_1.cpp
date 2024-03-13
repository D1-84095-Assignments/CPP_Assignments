#include<iostream>
using namespace std;

class Time
{
private: int h;
         int m;
         int s;
public: 
        Time()
        {
            this->h=0;
            this->m=0;
            this->s=0;
        }
        Time(int h, int m, int s)
        {
            this->h=h;
            this->m=m;
            this->s=s;
        }
        void printTime()
        {
            cout<<"Time is - "<<this->h<<" : "<<this->m<<" : "<<this->s<<endl;
        }
        int getHour()
        {
            return this->h;
        }
        int getMinute()
        {
            return this->m;
        }
        int getSeconds()
        {
            return this->s;
        }
        void setHour(int h)
        {
            this->h=h;
        }
        void setMinute(int m)
        {
            this->m=m;
        }
        void setSeconds(int s)
        {
            this->s=s;       
        }
};

int main()
{
   Time *ptr[5]={new Time(2,3,20),new Time(5,2,30),new Time,new Time(3,4,50),new Time};
   for(int i=0;i<5;i++)
       {
        ptr[i]->printTime();
        cout<<endl;
       } 

    for(int i=0;i<5;i++)
       { 
        delete ptr[i];
        ptr[i]=NULL;
       }
   
    return 0;
}

