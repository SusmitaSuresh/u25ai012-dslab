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

    Node* halfTheCircularLinkedList()
    {
        if(s == NULL)
        {
            return s;
        }
        
        int n = 1;
        Node *p = s;
        while(p->next!=s)
        {
            p = p->next;
            n++;
        }               //p is at the end

        if(n%2!=0)
        {
            cout<<"invalid size"<<endl;
            return NULL;
        }

        Node *q=s;
        for(int i=0; i<n/2 - 1; i++)
        {
            q = q->next;
        }
        
        p->next = q->next;
        q->next = s;
        return p->next;
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

    CLL y;
    y.s = x.halfTheCircularLinkedList();
    
    x.displayCLL();
    y.displayCLL();
}