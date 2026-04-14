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

    void insertSorted(int x)
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
        if(s->data> p->data)
        {
            while(q->next!=s)
            {
                q = q->next;
            }
            q->next = p;
            p->next = s;
            s = p;
            return;
        }
        while(q->next!=s && q->next->data <= p->data)       //we check data of node after q for insertion u idiot
        {
            q = q->next;
        }
        p->next = q->next;
        q->next = p;

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
};

int main()
{
    CLL x;

    x.insertSorted(1);
    x.insertSorted(2);
    x.insertSorted(3);
    x.insertSorted(4);
    x.insertSorted(2);      
    x.insertSorted(5);
    x.insertSorted(3);
    x.insertSorted(1);

    x.displayCLL();
}