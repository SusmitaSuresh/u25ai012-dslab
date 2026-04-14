#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    Node()
    {
        next = NULL;
    }
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};


class Queue
{
    public:
    Node *front = NULL, *rear = NULL;
    
    void enqueue(int x)
    {
        Node *p = new Node(x);
        if(rear == NULL)
        {
            rear = p;
            front = p;
        }
        else
        {
            rear->next = p;
            p->next = NULL;
            rear = rear->next;
        }
    }

    void dequeue()
    {
        if(front == NULL)
        {
            return;
        }
        if(front == rear);
        {
            rear = NULL;
        }
        Node *p = front;
        front = front->next;
        delete p;
    }

    bool isEmpty()
    {
        if(front == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int getFront()
    {
        if(front!=NULL)
        {
            return front->data;
        }
        else
        {
            cout<<"empty"<<endl;
        }
    }

    void display()
    {
        if(rear==NULL)
        {
            cout<<"linked list is empty"<<endl;
            return;
        }
        Node *p;
        p = front;
        while(p!=NULL)
        {           
            cout<<p->data;
            if(p->next!=NULL)       //it comes as 10->20->30 no arrow in the end
            {
                cout<<"->";
            }
            p = p->next;
        }
        cout<<endl;
    }
};

int main()
{
    Queue x;
    x.enqueue(10);
    x.enqueue(20);
    x.enqueue(30);

    cout<<"front is: "<<x.getFront();
    
    x.dequeue();
    x.dequeue();

    if(x.isEmpty())
    {
        cout<<"empty"<<endl;
    }
    else
    {
        cout<<"not empty"<<endl;
    }

    x.dequeue();

    if(x.isEmpty())
    {
        cout<<"empty"<<endl;
    }
    else
    {
        cout<<"not empty"<<endl;
    }
}