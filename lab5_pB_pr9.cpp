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

    int detectCycleAndCount()
    {
        int count = 0;
        if(s==NULL || s->next == NULL)
        {
            return count;
        }
        Node *p = s;
        Node *q = s->next;
        while(p!=NULL)
        {
            if(p==q)
            {
                cout<<"cycle detected"<<endl;
                do
                {
                    q = q->next;
                    count++;
                }while(p!=q);
                break;
            }
            p = p->next;
            q = q->next->next;
        }
        return count;
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
    x.insert(2);      
    x.insert(5);
    x.insert(3);
    x.insert(1);
    x.displayCLL();

    cout<<x.detectCycleAndCount();
}