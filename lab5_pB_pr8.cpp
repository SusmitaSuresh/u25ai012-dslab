using namespace std;
#include<iostream>

class Node
{
    public:
    int data;
    Node *next;
    Node()
    {
        next = NULL;
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
        if(s == NULL)
        {
            s = p;
            p->next = s;
            return;
        }
        Node *q = s;
        while(q->next!=s)
        {
            q = q->next;
        }
        q->next = p;
        p ->next = s;
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
        do
        {
            if(p->data>q->data)
            {
                if(curr == NULL)
                {
                    curr = p;
                    res = curr;
                    p = p->next;
                    continue;
                }
                curr->next = p;
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
                curr = curr->next;
                q = q->next;
            }
        }while(curr->next!=s1 && curr->next!=s2);
        if(p!=s1)
        {
            curr->next = p;
            curr = curr->next;
        }
        else if(q!=s2)
        {
            curr->next = q;
            curr = curr->next;
        }
        while(curr->next!=s1 && curr->next!=s2)
        {
            curr = curr->next;
        }
        curr->next = res;
        return res;
    }

    void displayCLL()
    {
        if(s==NULL)
        {
            cout<<"linked list is empty"<<endl;
            return;
        }
        Node *p;
        p = s;
        do
        {
            cout<<p->data;
            cout<<"->";
            p = p->next;
        }while(p!=s);

        cout<<"(back to start)"<<p->data;
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
    y.insert(7);
    x.displayCLL();
    y.displayCLL();

    z.s = LinkedList::Merge(x.s, y.s);  //this is how to access static functions through cpp
    z.displayCLL();     

}