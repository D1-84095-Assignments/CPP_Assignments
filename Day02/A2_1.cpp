#include<iostream>
using namespace std;
class Box
{
private: 
        int l;
        int w;
        int h;
public:
        Box()
        {
            this->l=1;
            this->w=1;
            this->h=1;
        }
        Box(int l, int w, int h)
        {
            this->l=l;
            this->w=w;
            this->h=h;
        }
        void acceptDimensions()
        {
            cout<<"Enter length, width and height"<<endl;
            cin>>this->l>>this->w>>this->h;
        }
        void calcVolume()
        {
            cout<<"Volume is : "<<(this->l)*(this->w)*(this->h)<<endl;
        }
        void displayDimensionAndVolume()
        {
            cout<<"Dimensions are : "<<endl;
            cout<<"Length :"<<this->l<<endl;
            cout<<"Width :"<<this->w<<endl;
            cout<<"Height :"<<this->h<<endl;
            this->calcVolume();
        }
};
int menu()
{
    int choice;
    cout<<"Enter your choice"<<endl;
    cout<<"0.Exit"<<endl<<"1.Accept data"<<endl;
    cout<<"2.Calculate volume"<<endl<<"3.Display dimensions and volume"<<endl;
    cin>>choice;
    return choice;
}
int main()
{
    int choice;
    Box b;
    
    while((choice=menu())!=0)
    {
        switch(choice)
        {
            case 1: b.acceptDimensions();
                    break;
            case 2: b.calcVolume();
                    break;
            case 3: b.displayDimensionAndVolume();
                    break;
            default:cout<<"Invalid choice"<<endl;
            break;

        }

    }

    return 0;
}

