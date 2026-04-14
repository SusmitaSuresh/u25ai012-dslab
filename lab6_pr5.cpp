#include<iostream>
#include<string>
#include<cstring>
using namespace std;

class Stack
{
    public:
    int n;
    int *stack;
    int top;

    Stack();
    Stack(int num)
    {
        n = num;
        stack = new int[n];
        top = -1;
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
            return '\0';
        }
        int y = stack[top];
        top--;
        return y;
    }

    int peek()
    {
        if(top == -1)
        {
            return '\0';
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
};

int postfixEvaluation(string s) 
{
    Stack x = Stack(s.length());
    int y,z;
    for(int i=0; i<s.length(); i++)
    {
        switch (s[i])
        {
            case '+':   z = x.pop();
                        y = x.pop();
                        x.push(y+z);
                        break;
            case '-':   z = x.pop();
                        y = x.pop();
                        x.push(y-z);
                        break;
            case '*':   z = x.pop();
                        y = x.pop();
                        x.push(y*z);
                        break;
            case '/':   z = x.pop();
                        y = x.pop();
                        x.push(y/z);
                        break;
            case '%':   z = x.pop();
                        y = x.pop();
                        x.push(y%z);
                        break;
            case '^':   z = x.pop();
                        y = x.pop();
                        x.push(y^z);
                        break;
            default: x.push(s[i]-'0');
        }
    }
    return x.pop();
}

int main()
{
    string s = "82/3-";      
    cout<<"postfix evaluation is: "<<postfixEvaluation(s);
}