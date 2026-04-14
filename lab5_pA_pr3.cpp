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

    void rotateByK(int k)
    {
        int n = getSize();
        if(n==0)
        {
            return;
        }

        if(k>n)
        {
            k = k%n;
        }
        Node *p = s;
        Node *q, *r;
        for(int i=0; i<n-k-1; i++)
        {
            p = p->next;
        }  
        q = p->next;
        r = q;
        while(q->next!=NULL)
        {
            q = q->next;
        }
        p->next = NULL;
        q->next = s;
        s = r;
    }

    int getSize()
    {
        int count=0;
        Node *p = s;
        while(p!=NULL)
        {
            p = p->next;
            count++;
        }
        return count;
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
    x.insert(80);
    x.insert(70);
    x.insert(60);
    x.insert(50);
    x.insert(40);
    x.insert(30);
    x.insert(20);
    x.insert(10);

    x.display();

    x.rotateByK(3);
    
    x.display();
}