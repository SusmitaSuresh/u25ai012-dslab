#include<iostream>
using namespace std;

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

    void reverseQueue()
    {
        if(front == -1)
        {
            return;
        }
        int y = dequeue();
        reverseQueue();
        enqueue(y);
    }

    void display()
    {
        for(int i=0; i<CountNoOfElements(); i++)
        {
            cout<<queue[i]<<"\t";
        }
        cout<<endl;
    }
};

int main()
{
    Queue q = Queue(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.display();

    q.reverseQueue();
    q.display();
}