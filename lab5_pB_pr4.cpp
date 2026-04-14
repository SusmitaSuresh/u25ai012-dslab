#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
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

    void reverseCLL()
    {
        if(s == NULL || s->next == s)
        {
            return;
        }
        Node *p = s, *q = s->next, *r;
        do
        {
            r = q->next;
            q->next = p;
            if(q==s)
            {
                s = p;
                break;
            }
            p = q;
            q = r;
        }while(q!=s->next);
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

    x.insert(1);
    x.insert(2);
    x.insert(3);
    x.insert(4);
    x.insert(5);
    x.insert(6);
    x.insert(7);
    x.insert(8);
    x.displayCLL();
    x.reverseCLL();

    x.displayCLL();

}