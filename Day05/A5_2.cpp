#include<iostream>
using namespace std;
class Product
{
private: int id;
         string title;
         float price;
public:        
        Product()
        {
            this->id=1;
            this->title="The Secret";
            this->price=500;
        }
        void accept()
        {
            cout<<"Enter id, title and price"<<endl;
            cin>>this->id>>this->title>>this->price;
        }
        float get_price()
        {
           return this->price;
        }
        virtual float calcbill()
        { 
            return this->price;
        }       
};
        
class Book: public Product
{
private: string author;               
public:
        void accept()
        {
        Product::accept();
        cout<<"Enter author : ";
        cin>>this->author;
        }
        float calcbill()
        {
            return get_price()*0.9;        
        }
       
};

class Tape: public Product
{
private: string artist;
public:
        void accept()
        {
        Product::accept();
        cout<<"Enter artist name : ";
        cin>>this->artist;   
        }
        float calcbill()
        {
           return this->get_price()*0.95;           
        }       
};

int main()
{
    int choice;
    int count=0;
    
    float totalbill=0;
    Product *p[3];
    for(int i=0;i<3;i++)
        p[i]=NULL;
    do
    {
        cout<<"Enter your choice(cannot add more than three products.)"<<endl;
        cout<<"0.Exit"<<endl;
        cout<<"1.Add Book"<<endl<<"2.Add Tape"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 0 : cout<<"Thank you";
                    break;
            case 1  : 
                    p[count]=new Book();
                    p[count]->accept();
                    totalbill=totalbill+p[count]->calcbill();
                    count++;
                    break;
            case 2: 
                    p[count]=new Tape();
                    p[count]->accept();
                    totalbill=totalbill+p[count]->calcbill();
                    count++;
                    break;

        }

    } while ( count<3 && choice !=0);
    
    cout<<"Total bill : "<<totalbill<<endl;

    for(int i=0;i<3;i++)
        {
            delete p[i];
            p[i]=NULL;
        }

    return 0;
}


