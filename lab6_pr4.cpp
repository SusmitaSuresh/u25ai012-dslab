#include<iostream>
#include<string>
#include<cstring>
using namespace std;

class Stack
{
    public:
    int n;
    char *stack;
    int top;

    Stack();
    Stack(int num)
    {
        n = num;
        stack = new char[n];
        top = -1;
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
            return '\0';
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

string infixToPostfix(string s) 
{
    string s1;   //final string that gets returned
    string temp;
    Stack x = Stack(s.length());    //max length of stack is the length of given string
    int k = 0;
    for(int i=0; i<s.length(); i++)
    {
        switch (s[i])       //make sure stack isnt empty, it causes infinite loop of underflow (trauma)
        {
            case '(': x.push(s[i]);
                      break;
            case '=': while(!x.isEmpty() && x.peek()!='(' && x.peek()!='=')
                      {
                          temp = x.pop();
                          s1.append(temp);
                      }
                      x.push(s[i]);
                      break;
            case '+': while(!x.isEmpty() && x.peek()!='(' && x.peek()!='=')
                      {
                          temp = x.pop();
                          s1.append(temp);
                      }
                      x.push(s[i]);
                      break;
            case '-': while(!x.isEmpty() && x.peek()!='(' && x.peek()!='=')
                      {
                          temp = x.pop();
                          s1.append(temp);
                      }
                      x.push(s[i]);
                      break;
            case '*': while(!x.isEmpty() && x.peek()!='(' && x.peek()!='=' && x.peek()!='+' && x.peek()!='-')
                      {
                          temp = x.pop();
                          s1.append(temp);
                      }
                      x.push(s[i]);
                      break;
            case '/': while(!x.isEmpty() && x.peek()!='(' && x.peek()!='=' && x.peek()!='+' && x.peek()!='-')
                      {
                          temp = x.pop();
                          s1.append(temp);
                      }
                      x.push(s[i]);
                      break;
            case '%': while(!x.isEmpty() && x.peek()!='(' && x.peek()!='=' && x.peek()!='+' && x.peek()!='-')
                      {
                          temp = x.pop();
                          s1.append(temp);
                      }
                      x.push(s[i]);
                      break;
            case '^': while(!x.isEmpty() && x.peek()!='(' && x.peek()!='=' && x.peek()!='+' && x.peek()!='-' && x.peek()!='*' && x.peek()!='/' && x.peek()!='%')
                      {
                          temp = x.pop();
                          s1.append(temp);
                      }
                      x.push(s[i]);
                      break;
            case ')': while(!x.isEmpty() && x.peek()!='(')
                      {
                          temp = x.pop();
                          s1.append(temp);
                      }
                      x.pop();  //remove the '(' also
                      break;
            default: temp = s[i];
                     s1.append(temp);
       }
    }
        while(!x.isEmpty())
        {
            s1 += x.pop();
        }
    return s1;
}

int main()
{
    string s = "(A+B)*(C-D)";      //remove ] for balanced
    string s1 = infixToPostfix(s);
    cout<<s<<endl;
    cout<<s1<<endl;
}