using namespace std;
#include<iostream>
#include<vector>

class Node
{
    public:
    int data;
    Node *next;
    Node *bottom;

    Node(int x)     //add constructor in every code!!
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

class LinkedList
{
    private: 
    Node *s;

    public:

    Node* mergeTwoList(Node *l1, Node *l2)
    {
        Node *res = new Node(0);
        Node *curr = res;
        while(l1!=NULL && l2!=NULL)
        {
            if(l1->data > l2->data)
            {
                curr->bottom = l2;
                curr = curr->bottom;
                l2 = l2->bottom;  
            }
            else
            {
                curr->bottom = l1;
                curr = curr->bottom;
                l1 = l1->bottom;
            }
            curr->next = NULL;
        }
        if(l1!=NULL)
        {
            curr->bottom = l1;
        }
        else if(l2!=NULL)
        {
            curr->bottom = l2;
        }
        return res->bottom;
    }

    Node* FlattenAlinkedList(Node *s)
    {
        if(s == NULL || s->next == NULL)
        {
            return s;
        }
        Node *mergeHead = FlattenAlinkedList(s->next);
        s = mergeTwoList(s, mergeHead);        
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
            if(p->bottom!=NULL)       //it comes as 10->20->30 no arrow in the end
            {
                cout<<"->";
            }
            p = p->bottom;
        }
        cout<<endl;
    }
};

int main()
{
    Node *p = new Node(5);
    Node *q = new Node(7);
    Node *r = new Node(8);

    Node *x = new Node(10);
    Node *y = new Node(20);

    Node *a = new Node(19);
    Node *b = new Node(22);



    p->next = x;
    p->bottom = q;
    q->bottom = r;
    q->next = NULL;
    r->bottom = NULL;
    r->next = NULL;

    x->next = a;
    x->bottom = y;
    y->bottom = NULL;
    y->next = NULL;

    a->next = NULL;
    a->bottom = b;
    b->next = NULL;
    b->bottom = NULL; 


    Node *s = p;
    LinkedList *l;
    s = l->FlattenAlinkedList(p);
    l->display(s);
}