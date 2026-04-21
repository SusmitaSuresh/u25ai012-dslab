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
    
    ~Stack() 
    {
        delete[] stack;
    }

};

class Queue
{
    public:

    int n;
    int front = -1;
    int rear = -1;
    int *queue;

    Queue(int num)
    {
        n = num;
        queue = new int[n];
    }

    void enqueue(int x)
    {
        if(rear == n-1)
        {
            cout<<"overflow"<<endl;
            return;
        }
        if(rear == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear++;
        }
        queue[rear] = x;
    }

    int dequeue()
    {
        if(front == -1)
        {
            cout<<"underflow"<<endl;
            return 0;
        }
        int y = queue[front];
        if(front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }
        return y;
    }

    int CountNoOfElements()
    {
        return rear-front+1;
    }
};

int main()
{
    Queue q = Queue(5);
    Stack s = Stack(5);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    
    int n = q.CountNoOfElements();

    for(int i=0; i<n; i++)
    {
        s.push(q.dequeue());
    }
    for(int i=0; i<n; i++)
    {
        q.enqueue(s.pop());
    }
    
}