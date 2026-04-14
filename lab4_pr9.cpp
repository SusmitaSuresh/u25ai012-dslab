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
    Node *s1 = NULL;
    
    void insertAtBeginning(int data)
    {
        Node *q = new Node;     //makes new node
        q->data = data;
        q->next = s;
        s=q;
    }

    void findIntersection()
    {
        Node *p, *q;
        p = s1;
        q = s;
        while(p!=NULL)
        {
            while(q!=NULL)
            {
                if(q == p)
                {
                    cout<<"there is an intersection"<<endl;
                    return;
                }
                q = q->next; 
            }
            q = s;
            p = p->next;
        }
        cout<<"there is no intersection"<<endl;
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

    Node p, q, r, y, z;
    p.data = 1;
    q.data = 2;
    r.data = 3;
    y.data = 5;
    z.data = 6;
    
    x.s = &p;
    x.s1 = &y;

    p.next = &q;
    q.next = &r;
    r.next = NULL;

    y.next = &z;
    z.next = &q;

    
    x.findIntersection();
}