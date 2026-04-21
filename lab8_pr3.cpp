#include<iostream>
using namespace std;

class Queue
{
    int n;
    int front = -1;
    int rear = -1;
    int *queue;
    int min;
    int max;

    public:

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
            max = x;
            min = x;
        }
        else
        {
            rear++;
        }
        if(x>max)
        {
            max = x;
        }
        if(x<min)
        {
            min = x;
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

    int getMax()
    {
        return max;
    }

    int getMin()
    {
        return min;
    }
};

int main()
{
    Queue q = Queue(5);

    q.enqueue(1);
    q.enqueue(2);
    cout<<q.getMin()<<endl;
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);  
    cout<<q.getMax();
}