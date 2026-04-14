#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
};

class Stack
{
    public:
    Node *top = NULL;
    void push(int x)
    {
        Node *p = new Node();
        p->data = x;
        p->next = top;
        top = p;
    }

    int pop()
    {
        if(isEmpty())
        {
            cout<<"underflow"<<endl;
            return 0;
        }
        int y = top->data;
        Node *p = top;
        top = top->next;
        free(p);
        return y;
    }

    int peek()
    {
        if(isEmpty())
        {
            return -1;
        }
        else
        {
            return top->data;
        }
    }

    bool isEmpty()
    {
        if(top == NULL)
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
    Stack x;
    x.push(1);
    x.push(2);
    x.push(3);
    cout<<x.peek()<<endl;
    if(x.isEmpty())
    {
        cout<<"empty"<<endl;
    }
    else
    {
        cout<<"not empty"<<endl;
    }
    x.pop();
    x.pop();
    x.pop();
    x.pop();
    if(x.isEmpty())
    {
        cout<<"empty"<<endl;
    }
    else
    {
        cout<<"not empty"<<endl;
    }
}