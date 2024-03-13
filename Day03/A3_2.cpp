#include<iostream>
using namespace std;

class Stack
{
private: int top;
         int size;
         int *arr;
public:
        Stack()
        {
                this->size=5;
                arr=new int[size];
                this->top=-1;
                for(int i=0;i<this->size;i++)
                        arr[i]=-1;
                this->top=-1;
        }
        Stack(int size)
        {
                this->size=size;
                arr=new int[this->size];
                this->top=-1;
        }
        void push(int a)
        {
                this->top++;
                *(arr+top)=a;
               
        }
        int pop()
        {
               return arr[this->top--];
        }
        int peek()
        {       
                if(this->top==size-2)
                {for(int i=0;i<this->size;i++)
                        arr[i]=-1;}
                return this->arr[top];
        }
        bool isEmpty()
        {
                if(this->top==-1)
                        return true;
                else return false;
        }
        bool isFull()
        {
                if(this->top==size-1)
                        return true;
                else return false;
        }
        void print()
        {
                for(int i=0;i<this->size;i++)
                        cout<<this->arr[i]<<" ";
                        cout<<endl;
        }
       
        ~Stack()
        {
                delete this->arr;
        }
       
};

enum EMenu
{
        EXIT,PUSH,POP,PEEK,PRINT
};

int main()
{
int choice;
Stack s;
int data;
do
{
    cout<<"Enter your choice"<<endl;
    cout<<"0.Exit"<<endl<<"1.Push element"<<endl<<"2.Pop element"<<endl;
    cout<<"3.Peek element"<<endl<<"4.Print elements in stack"<<endl;
    
    cin>>choice;

    switch(EMenu(choice))
    {
        case EXIT   :   cout<<"Thank you"<<endl;
                        break;
        case PUSH   :   if(s.isFull())
                            cout<<"Stack is full"<<endl;
                        else {cout<<"Enter data to push"<<endl;
                            cin>>data;
                            s.push(data);}
                            break;
        case POP    :   if(s.isEmpty())
                                cout<<"Stack is empty"<<endl;
                        else    cout<<"Popped element is : "<<s.pop()<<endl;
                        break;
        case PEEK   :   if(s.isEmpty())
                                cout<<"Stack is empty"<<endl;
                        else cout<<"Element is : "<<s.peek()<<endl;
                        break;
        case PRINT  :   if(s.isEmpty())
                                cout<<"Stack is empty"<<endl;
                        else s.print();
                        break;
        
                      
        
    }

} while (choice!=0);
return 0;
}