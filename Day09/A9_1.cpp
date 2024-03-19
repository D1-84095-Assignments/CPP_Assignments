#include <iostream>
using namespace std;

template <class T>
class Stack
{
private:
    int top;
    T *arr;
    int size;

public:
    Stack()
    {
        this->size = 5;
        arr = new T[size];
        this->top = -1;
    }
    Stack(int size)
    {
        this->size = size;
        arr = new T[this->size];
        this->top = -1;
    }
    void push(T a)
    {
        this->top++;
        *(arr + top) = a;
    }
    T pop()
    {
        return arr[this->top--];
    }
    T peek()
    {
        return this->arr[top];
    }
    bool isEmpty()
    {
        if (this->top == -1)
            return true;
        else
            return false;
    }
    bool isFull()
    {
        if (this->top == size - 1)
            return true;
        else
            return false;
    }

    ~Stack()
    {
        delete this->arr;
    }
};

class Box
{
private:
    int length;
    int width;
    int height;

public:
    Box()
    {
        this->length = 1;
        this->width = 1;
        this->height = 1;
    }
    Box(int length, int width, int height)
    {
        this->length = 1;
        this->width = 1;
        this->height = 1;
    }
    void display()
    {
        cout << "Box dimensions : " << endl;

        cout << "Length=" << this->length << endl;

        cout << "Width=" << this->width << endl;
        cout << "Height=" << this->height << endl;
    }
};

int main()
{
    Stack<int> s;
    if (!s.isFull())
        s.push(8);
    s.push(10);
    if (!s.isEmpty())
        cout << s.peek() << endl;
    if (!s.isEmpty())
        cout << s.pop() << endl;

    Stack<double> d;
    if (!s.isFull())
        d.push(3.4);
    cout << d.peek() << endl;

    Stack<Box> b;
  
    Box b1(10, 20, 30);
    if (!b.isFull())
        b.push(b1);
    Box b2;
    if (!b.isEmpty())
        b2 = b.pop();
    
    b2.display();

    return 0;
}
