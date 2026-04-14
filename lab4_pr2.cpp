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
    public:
    
    void insertAtBeginning(int data)
    {
        Node *q = new Node;     //makes new node
        q->data = data;
        q->next = s;
        s=q;
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
        cout<<endl;
    }
};

int main()
{
    LinkedList x;

    x.insertAtBeginning(10);
    x.insertAtBeginning(20);
    x.insertAtBeginning(30);
    x.insertAtBeginning(40);
    x.insertAtBeginning(50);
    x.insertAtBeginning(60);
    x.insertAtBeginning(70);
    x.insertAtBeginning(80);
    x.insertAtBeginning(90);
    x.insertAtBeginning(100);

    x.display();

    x.detectCycle();
}