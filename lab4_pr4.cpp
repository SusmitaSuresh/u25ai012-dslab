using namespace std;
#include<iostream>

class Node
{
    public:
    int data;
    Node *next;
    Node *random;
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

    Node* cloneListWithRandomPointers()
    {
        //we insert a copy of nodes right after the og node and link randoms in one loop then next in the other loop

        if(s == NULL)
        {
            return NULL;
        }
        Node *p = s;

        while(p!=NULL)      //duplicate nodes are inserted
        {
            Node *q = new Node();
            q->data = p->data;
            q->next = p->next;
            p->next = q;
            p = p->next->next;
        }
        
        p = s;

        while(p!=NULL)      //links the random pointers 
        {
            if(p->random!=NULL)
            {
                p->next->random = p->random->next;
            }
            else
            {
                p->next->random = NULL;
            }
            p = p->next->next;
        }

        p = s;
        Node *q = s->next;
        Node *s1 = s->next;

        while(p!=NULL)        //links all the next pointers
        {
            p->next = p->next->next;
            if(q->next!=NULL)
            {
                q->next = q->next->next;
            }
            p = p->next;
            q = q->next;
        }
        return s1;
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
    LinkedList x,y;
    Node p, q, r;
    p.data = 1;
    q.data = 2;
    r.data = 3;
    x.s = &p;
    p.next = &q;
    q.next = &r;
    r.next = NULL;
    p.random = NULL;
    q.random = &r;
    r.random = &p;

    x.display();

    y.s = x.cloneListWithRandomPointers();
    y.display();
}