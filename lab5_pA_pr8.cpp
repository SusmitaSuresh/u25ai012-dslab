using namespace std;
#include<iostream>

class Node
{
    public:
    int data;
    Node *next;
    Node *prev;
    Node()
    {
        next = NULL;
        prev = NULL;
    }
};

class LinkedList
{
    public:
    
    Node *s = NULL;    //start

    void insert(int x)
    {
        Node *p = new Node();
        p->data = x;
        p->prev = NULL;
        if(s == NULL)
        {
            p->next = s;
            s = p;
        }
        else
        {
            p->next = s;
            s->prev = p;
            s = p;
        }
    }

    void swapNodes(int pos1, int pos2)
    {
        if(s==NULL || s->next == NULL || pos1 == pos2 || pos1<=0 || pos2<=0)
        {
            cout<<"invalid"<<endl;
            return;
        }
        if(pos1>pos2)       //pos1 will be less than pos2
        {
            pos1 = pos1+pos2;
            pos2 = pos1 - pos2;
            pos1 = pos1 - pos2;
        }

        Node *p = s, *q = s, *temp = NULL;
        for(int i=1; i<pos2; i++)
        {
            if(q == NULL)
            {
                cout<<"invalid"<<endl;
                return;
            }
            if(i<pos1)
            {
                p = p->next;
            }
            q = q->next;
        }

        if(pos1+1 == pos2)      //adjacent nodes break 6 connections rather than 8
        {
            p->next = q->next;
            q->prev = p->prev;
            if(p->prev!=NULL)
            {
                p->prev->next = q;
            }
            else
            {
                s = q;
            }
            if(q->next!=NULL)
            {
                q->next->prev = p;
            }
            p->prev = q;
            q->next = p;
            return;
        }

        p->next->prev = q;
        if(q->next!=NULL)
        {
            q->next->prev = p;
        }
        q->prev->next = p;
        if(p->prev!=NULL)
        {
            p->prev->next = q;
        }
        else
        {
            s = q;
        } 
        temp = p->prev;
        p->prev = q->prev;
        q->prev = temp;
        temp = p->next;
        p->next = q->next;
        q->next = temp;        
    }

    void display()
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
            if(p->next!=NULL)        
            {
                cout<<"-><-";
            }
            p = p->next;
        }
        cout<<endl;
    }

    
};

int main()
{
    LinkedList x;
    x.insert(1);
    x.insert(2);
    x.insert(3);
    x.insert(4);

    x.display();

    x.swapNodes(2,4);

    x.display();

    x.swapNodes(1,2);

    x.display();

}