#include<iostream>
using namespace std;

class Queue
{
    int n;
    int front = -1;
    int rear = -1;
    char *queue;

    public:

    Queue(int num)
    {
        n = num;
        queue = new char[n];
    }

    void enqueue(char x)
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

    char dequeue()
    {
        if(front == -1)
        {
            cout<<"underflow"<<endl;
            return 0;
        }
        char y = queue[front];
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

    bool checkPalindrome()
    {
        if(front == rear)
        {
            return true;
        }
        if(queue[front] == queue[rear])
        {
            front++;
            rear--;
            checkPalindrome();
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    string s = "madaam";
    Queue q = Queue(s.length());         //why do we need double ended queue???

    for(int i=0; i<s.length(); i++)
    {
        q.enqueue(s[i]);
    }

    if(q.checkPalindrome())
    {
        cout<<"it is palindrome"<<endl;
    }
    else
    {
        cout<<"it is not palindrome"<<endl;
    }
    
}