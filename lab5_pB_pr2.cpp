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

    void checkWhetherSorted()
    {
        if(s == NULL)
        {
            return;
        }
        Node *p = s;
        Node *q = s->next;
        while(q!=s)
        {
            if(p->data<q->data)     //descending is sorted
            {
                cout<<"unsorted"<<endl;
                return;
            }
            else
            {
                p = p->next;
                q = q->next;
            }
        }
        cout<<"sorted"<<endl;
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
    x.insert(2);        //change this to 5 for sorted
    x.insert(6);
    x.insert(7);
    x.insert(8);

    x.displayCLL();

    x.checkWhetherSorted();
}