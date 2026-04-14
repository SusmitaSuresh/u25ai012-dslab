#include<iostream>
using namespace std;

class Stack
{
    public:
    int n;
    int *stack = new int[n];
    int top = -1;

    Stack(int num)
    {
        n = num;
    }

    void push(int x)
    {
        if(top == n-1)
        {
            cout<<"overflow"<<endl;
            return;
        }
        top++;
        stack[top] = x;
    }
    
    int pop()
    {
        if(top == -1)
        {
            cout<<"underflow"<<endl;
            return -1;
        }
        int y = stack[top];
        top--;
        return y;
    }

    int peek()
    {
        if(top == -1)
        {
            cout<<"underflow"<<endl;
            return -1;
        }
        return stack[top];
    }

    bool isEmpty()
    {
        if(top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isFull()
    {
        if(top == n-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Stack *x = new Stack(3);
    x->push(1);
    x->push(2);
    x->push(3);
    cout<<x->peek()<<endl;
    if(x->isFull())
    {
        cout<<"full"<<endl;
    }
    else
    {
        cout<<"not full"<<endl;
    }
    x->pop();
    x->pop();
    x->pop();
    x->pop();
    if(x->isEmpty())
    {
        cout<<"empty"<<endl;
    }
    else
    {
        cout<<"not empty"<<endl;
    }
}