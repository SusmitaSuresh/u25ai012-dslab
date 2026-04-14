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
            rear->next = front;
        }
        else
        {
            rear->next = p;
            p->next = front;
            rear = rear->next;
        }
    }

    void dequeue()
    {
        if(front == NULL)
        {
            return;
        }
        if(front == rear)
        {
            Node *p = front;
            rear = NULL;
            front = NULL;
            delete p;
            return;
        }
        Node *p = front;
        front = front->next;
        rear->next = front;
        delete p;
    }

    int getFront()
    {
        if(front!=NULL)
        {
            return front->data;
        }
        else
        {
            cout<<"empty";
            return 0;
        }
    }
    int getRear()
    {
        if(rear!=NULL)
        {
            return rear->data;
        }
        else
        {
            cout<<"empty";
            return 0;
        }
    }


    void display()
    {
        if(front == NULL)
        {
            cout<<"linked list is empty"<<endl;
            return;
        }
        Node *p;
        p = front;
        do
        {
            cout<<p->data;
            cout<<"->";
            p = p->next;
        }while(p!=front);
        cout<<"(back to start)"<<p->data;
        cout<<endl;
    }
};

int main()
{
    Queue x;
    x.enqueue(10);
    x.enqueue(20);
    x.enqueue(30);
    x.display();

    cout<<"front is: "<<x.getFront()<<endl;
    cout<<"rear is: "<<x.getRear()<<endl;
    
    x.dequeue();
    x.dequeue();
    x.display();
    cout<<"front is: "<<x.getFront()<<endl;
    x.dequeue();
    cout<<"rear is: "<<x.getRear()<<endl;
    x.display();
    
}