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
};

class CLL
{
    public:
    
    Node *s = NULL;

    void insert(int x)
    {
        Node *p = new Node();
        p->data = x;
        if(s == NULL)
        {
            s = p;
            p->next = s;
            return;
        }
        Node *q = s;
        while(q->next!=s)
        {
            q = q->next;
        }
        q->next = p;
        p ->next = s;
    }

    void circularToLinear()
    {
        if(s == NULL)
        {
            return;
        }
        Node *p = s;
        while(p->next!=s)
        {
            p = p->next;
        }
        p->next = NULL;
    }

    void displayCLL()
    {
        if(s==NULL)
        {
            cout<<"linked list is empty"<<endl;
            return;
        }
        Node *p;
        p = s;
        do
        {
            cout<<p->data;
            cout<<"->";
            p = p->next;
        }while(p!=s);
        cout<<"(back to start)"<<p->data;
        cout<<endl;
    }

    void displayLLL()
    {
        if(s==NULL)
        {
            cout<<"linked list is empty"<<endl;
            return;
        }
        Node *p;
        p = s;
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
    CLL x;

    x.insert(1);
    x.insert(2);
    x.insert(3);
    x.insert(4);
    x.insert(2);      
    x.insert(5);
    x.insert(3);
    x.insert(1);
    x.displayCLL();

    x.circularToLinear();
    x.displayLLL();
}