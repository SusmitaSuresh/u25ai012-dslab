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
    private: 
    Node *s = NULL;    //start
    Node *s1 = NULL;
    public:
    
    void insertAtBeginning(int data)
    {
        Node *q = new Node;     //makes new node
        q->data = data;
        q->next = s;
        s=q;
    }

    void palindromeOrNot()
    {
        if(s == NULL)
        {
            cout<<"list empty"<<endl;
            return;
        }
        else if(s->next == NULL)
        {
            cout<<"palindrome"<<endl;
            return;
        }

        Node *p;
        p = s;
        Node *l = new Node;
        s1 = l;
        l->data = p->data;
        l->next = NULL;
        p = p->next;
        while(p!=NULL)
        {
            Node *n = new Node;
            l->next = n;
            n->data = p->data;
            n->next = NULL;
            l = l->next;
            p = p->next;
        }

        display();
        Node *q, *r;
        q = s->next;
        r = q->next;
        p = s;
        p->next = NULL;

        while(q!=NULL)
        {
            q->next = p;
            p=q;
            q=r;
            if(r!=NULL)
            {
                r = r->next;
            }
        }
        s = p;

        p = s;
        q = s1;
        while(p!=NULL)
        {
            if(p->data!=q->data)
            {
                cout<<"not a palindrome"<<endl;
                return;
            }
            p = p->next;
            q = q->next;
        }
        cout<<"palindrome"<<endl;
    }
    void display()
    {
        if(s1==NULL)
        {
            cout<<"linked list is empty"<<endl;
            return;
        }
        Node *p;
        p = s1;
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

    x.insertAtBeginning(1);
    x.insertAtBeginning(2);
    x.insertAtBeginning(3);
    x.insertAtBeginning(4);
    x.insertAtBeginning(5);
    x.insertAtBeginning(4);
    x.insertAtBeginning(3);
    x.insertAtBeginning(2);
    x.insertAtBeginning(1);
    x.palindromeOrNot();

}