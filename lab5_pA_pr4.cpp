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
    private: 
    Node *s = NULL;    //start

    public:

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

    void removeDuplicates()
    {
        if(s == NULL || s->next == NULL)
        {
            return;
        }
        int count=0;
        Node *p = s;
        Node *q = s->next;
        while(p!=NULL)
        {
            q = p->next;
            count = 0;
            while(q!=NULL)
            {
                if(p->data == q->data)
                {
                    count++;
                    q->prev->next = q->next;
                    if(q->next!=NULL)
                    {
                        q->next->prev = q->prev;
                    }
                    Node *temp = q;
                    q = q->next;
                    delete temp;
                }
                else
                {
                    q = q->next;
                }
            }
            if(count>0)
            {
                Node *temp = p;
                if(temp == s)
                {
                    s = s->next;
                    p = p->next;
                    s->prev = NULL;
                    delete temp;
                }
                else
                {
                    p->next->prev = p->prev;
                    p->prev->next = p->next;
                    p = p->next;
                    delete temp;
                }
            }
            else
            {
                p = p->next;
            }
        }
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
    x.insert(5);
    x.insert(2);
    x.insert(3);
    x.insert(6);
    x.insert(2);
    x.insert(5);
    x.insert(2);
    x.insert(4);

    x.display();

    x.removeDuplicates();
    x.display();
}