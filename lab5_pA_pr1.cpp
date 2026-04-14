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

    void reverse()
    {
        if(s == NULL ||s->next ==NULL)
        {
            return;
        } 
        Node *p = s;
        while(p!=NULL)
        {
            Node *q = p->prev;
            p->prev = p->next;
            p->next = q;       

            if(p->prev == NULL)
            {
                s = p;
                p = NULL;
                break;
            }
            p = p->prev;
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
    x.insert(10);
    x.insert(20);
    x.insert(30);
    x.insert(40);
    x.insert(50);
    x.insert(60);
    x.insert(70);
    x.insert(80);

    x.display();
    x.reverse();
    x.display();

}