#include<iostream>
using namespace std;

class Stack
{
    public:
    int n;
    char *stack = new char[n];
    int top = -1;

    Stack(int num)
    {
        n = num;
    }

    void push(char x)
    {
        if(top == n-1)
        {
            cout<<"overflow"<<endl;
            return;
        }
        top++;
        stack[top] = x;
    }
    
    char pop()
    {
        if(top == -1)
        {
            cout<<"underflow"<<endl;
            return -1;
        }
        char y = stack[top];
        top--;
        return y;
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

    int sizeOfStack()
    {
        return n;
    }
    
    Stack* reverseStringUsingStack()
    {
        Stack *temp = new Stack(sizeOfStack());     //all these functions automatically apply using str
        while(!isEmpty())
        {
            temp->push(pop());
        }
        return temp;
    }

    ~Stack() 
    {
        delete[] stack;
    }

};

int main()
{
    Stack *str = new Stack(6);

    str->push('s');
    str->push('t');
    str->push('r');
    str->push('i');
    str->push('n');
    str->push('g');

    while(!str->isEmpty())
    {
        cout<<str->pop();
    }

    cout<<endl;

    str->push('s');
    str->push('t');
    str->push('r');
    str->push('i');
    str->push('n');
    str->push('g');

    str = str->reverseStringUsingStack();

    while(!str->isEmpty())
    {
        cout<<str->pop();
    }

    delete str;
}