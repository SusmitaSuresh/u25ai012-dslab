#include<iostream>
using namespace std;


#include<iostream>
using namespace std;

class Stack
{
    public:
    int n;
    int *stack = new int[n];
    int *min = new int[n];
    int top = -1;
    int top1 = -1;

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
        if(top1 == -1 || x<=min[top1])
        {
            top1++;
            min[top1] = x;
        }
    }
    
    int pop()
    {
        if(top == -1)
        {
            cout<<"underflow"<<endl;
            return -1;
        }
        int y = stack[top];
        if(stack[top] == min[top1])
        {
            top1--;
        }
        top--;
        return y;
    }

    int getMin()
    {
        if(top1 == -1)
        {
            return -1;
        }
        else
        {
            return min[top1];
        }
    }
};

int main()
{
    Stack *x = new Stack(5);
    x->push(1);
    x->push(2);
    x->push(0);
    x->push(3);
    cout<<x->getMin();
    x->pop();
    x->pop();
    cout<<x->getMin();
}