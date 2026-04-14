#include <iostream>
#include<iomanip>
using namespace std;

class Node
{    
    public:
    int data;
    Node *next;   
};

class LinkedList
{
    private:
    Node *s = NULL;            //stores the start of linked list
    public:
    void insertAtHead(int data)
    {
        Node *q = new Node;     //makes new node
        q->data = data;
        q->next = s;
        s=q;
    }
    void insertAtTail(int data)
    {
        Node *q = new Node;
        if(s==NULL)
        {
            s=q;
            q->data = data;
            q->next = NULL;
        }
        else
        {

            Node *p;
            p = s;
            while(p->next!=NULL)
            {
                p = p->next;
            }
            p->next = q;
            q->next = NULL;
            q->data = data;
        }
    }
    void deleteByValue(int data)
    {
        if(s==NULL)
        {
            cout<<"linked list is empty"<<endl;;
            return;
        }
        else if((s)->next == NULL && (s)->data == data)
        {
            Node *x;
            x=s;
            s = (s)->next;
            delete x;
            return;
        }
        Node *p, *q;
        p=(s)->next;
        q=s;
        while(p!=NULL)
        {
            if(p->data == data)
            {
                q->next = p->next;
                delete p;
                return;
            }
            p = p->next;
            q = q->next;
        }
    }
    void deleteByPosition(int pos)
    {
        int co=0;
        if(s==NULL)
        {
            cout<<"linked list is empty"<<endl;
            return;
        }
        if(pos == 0)
        {
            Node *x;
            x = s;
            s = (s)->next;
            delete x;
            return;
        }
        Node *p, *q;
        p=(s)->next;
        q=s;
        while(co<pos-1)
        {
            if(p == NULL)
            {
                cout<<"position given is wrong"<<endl;
                return;
            }
            p = p->next;
            q = q->next;
            co++;
        }
        if(p == NULL)           //in last itteration, first co=0 so loop enters and p bcms null, then loop exited as 1!<1 
        {                       //so we end up getting segmentation fault
            cout<<"position given is wrong"<<endl;
            return;
        }
        q->next = p->next;
        delete p;
    }
    void searchForValue(int data)
    {
        if(s==NULL)
        {
            cout<<"linked list is empty"<<endl;;
            return;
        }
        Node *p;
        p=s;
        while(p!=NULL)
        {
            if(p->data == data)
            {
                cout<<"it is present"<<endl;
                return;
            }
            p = p->next;
        }
        cout<<"it is not present"<<endl;
    }
    void reverseList()
    {
        if(s == NULL)
        {
            cout<<"list empty"<<endl;
            return;
        }
        else if(s->next == NULL)
        {
            return;
        }
        Node *p, *q, *r;
        p = s;
        q = s->next;
        r = q->next;
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
    }
    void detectCycle()
    {
        //floyd's cycle detection uses one fast pointer and one slow pointer
        if(s==NULL)
        {
            cout<<"linked list is empty"<<endl;
            return;
        }
        else if(s->next == NULL)
        {
            cout<<"only one element"<<endl;
            return;                                                                                                        
        }
        Node *p, *q;
        p = s;      //slow pointer
        q = s;      //fast pointer
        while(q!=NULL && q->next!=NULL)
        {
            p = p->next;
            q = q->next->next;
            if(p == q)      //if they are equal then theres a loop, else it is a normal list
            {
                cout<<"cycle detected"<<endl;
                return;
            }
        }
        cout<<"cycle is not detected"<<endl;
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
    }
};

int main()
{ 
    LinkedList x;                //creates object of linkedList to access functions

    x.insertAtHead(10);         //sideNote: while passing pointer it takes copy so u need to pass pointer to pointer (**s)
    x.insertAtTail(20);       
    x.insertAtHead(91);
    x.insertAtTail(23);

    x.display();

    cout<<endl;
    x.reverseList();
    x.display();
}