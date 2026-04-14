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
    
    int pop()
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

    char peek()
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

bool isValid(string s) 
{
    int n = s.length();
    Stack *st = new Stack(n);
    for(int i=0; i<n; i++)
    {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            st->push(s[i]);
        }
        else if(s[i] == ')' || s[i] == ']' || s[i] == '}')
        {
            if(st->isEmpty())
            {
                return false;
            }
            else
            {
                if((s[i]==')' && st->peek()=='(') || (s[i]==']' && st->peek()=='[') || (s[i]=='}' && st->peek()=='{'))
                {
                    st->pop();
                }
                else
                {
                    return false;
                }
            }
        }
    }
    if(st->isEmpty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string s = "[(a+b) * {c+d}]]";      //remove ] for balanced
    if(isValid(s))
    {
        cout<<"balanced";
    }
    else
    {
        cout<<"unbalanced";
    }
}
