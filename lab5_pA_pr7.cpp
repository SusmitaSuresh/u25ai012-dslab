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

    static Node* Merge(Node *s1, Node *s2)
    {
        if(s2 == NULL )
        {
            return s1;
        }
        if(s1 == NULL)
        {
            return s2;
        }
        
        Node *res;
        Node *p=s1, *q=s2, *curr = NULL;
        while(p!=NULL && q!=NULL)
        {
            if(p->data<q->data)
            {
                if(curr == NULL)
                {
                    curr = p;
                    res = curr;
                    p = p->next;
                    continue;
                }
                curr->next = p;
                p->prev = curr;
                curr = curr->next;
                p = p->next;
            }
            else
            {
                if(curr == NULL)
                {
                    curr = q;
                    res = curr;
                    q = q->next;
                    continue;
                }
                curr->next = q;
                q->prev = curr;
                curr = curr->next;
                q = q->next;
            }
        }
        if(p!=NULL)
        {
            curr->next = p;
            p->prev = curr;
            curr = curr->next;
        }
        else if(q!=NULL)
        {
            curr->next = q;
            q->prev = curr;
            curr = curr->next;
        }
        return res;
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

    void display(Node *s)      
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
    LinkedList x,y,z;
    x.insert(8);
    x.insert(5);
    x.insert(4);
    x.insert(1);
    y.insert(9);
    y.insert(6);
    y.insert(3);
    y.insert(2);

    x.display();
    y.display();

    z.s = LinkedList::Merge(x.s, y.s);  //this is how to access static functions through cpp
    z.display();     

}