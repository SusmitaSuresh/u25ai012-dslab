using namespace std;
#include<iostream>

class Node
{
    public:
    int data;
    Node *next;
};

class LinkedList
{
    public:
    Node *s = NULL;    //start    
    void insertAtBeginning(int data)
    {
        Node *q = new Node;     //makes new node
        q->data = data;
        q->next = s;
        s=q;
    }

    void mergeTwoLists(Node *s1)
    {
        if(s == NULL)
        {
            display(s1);
            return;
        }
        if(s1 == NULL)
        {
            display(s);
            return;
        }
        if(s->data > s1->data)
        {
            Node *temp = s;
            s = s1;
            s1 = temp;
        }
        Node *p, *q, *r, *res;
        r = NULL;
        p = s;
        q = s1;
        while(p!=NULL && q!=NULL)
        {
            if(p->data >= q->data)
            {
                if(r == NULL)
                {
                    res = p;
                    r = p;
                    p = p->next;
                }
                else
                {
                    r->next = p;
                    p = p->next;
                    r = r->next;
                }
            }
            else
            {
                if(r == NULL)
                {
                    res = q;
                    r = q;
                    q = q->next;
                }
                else
                {
                    r->next = q;
                    r = r->next;
                    q = q->next;
                }
            }
        }
        if(p!=NULL)
        {
            r->next = p;
        }
        else if(q!=NULL)
        {
            r->next = q;
        }
        display(res);
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
            if(p->next!=NULL)       //it comes as 10->20->30 no arrow in the end
            {
                cout<<"->";
            }
            p = p->next;
        }
        cout<<endl;
    }
};

int main()
{
    LinkedList x;
    LinkedList y;


    x.insertAtBeginning(10);
    x.insertAtBeginning(40);
    x.insertAtBeginning(50);
    x.insertAtBeginning(90);
    x.display(x.s);

    y.insertAtBeginning(20);
    y.insertAtBeginning(30);
    y.insertAtBeginning(60);
    y.insertAtBeginning(70);
    y.insertAtBeginning(100);
    y.insertAtBeginning(120);
    y.insertAtBeginning(140);
    y.display(y.s);

    x.mergeTwoLists(y.s);
}