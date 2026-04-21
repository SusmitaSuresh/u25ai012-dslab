#include<iostream>
using namespace std;

class Queue
{
    int n;
    int front = -1;
    int rear = -2;
    int *queue;

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
        if(rear == -2)
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
            rear = -2;
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

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout<<"count: "<<q.CountNoOfElements();

    q.enqueue(4);
    q.enqueue(5);
    cout<<"count: "<<q.CountNoOfElements();

    q.dequeue();
    q.dequeue();
    cout<<"count: "<<q.CountNoOfElements();

    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout<<"count: "<<q.CountNoOfElements();

}