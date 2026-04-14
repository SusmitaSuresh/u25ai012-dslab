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

    void removeDuplicates()
    {
        if(s == NULL)
        {
            cout<<"list empty"<<endl;
            return;
        }
        else if(s->next == NULL)
        {
            cout<<"only one element"<<endl;
            return;
        }
        Node *p;
        p = s;
        while(p->next!=NULL)
        {
            if(p->data == p->next->data)
            {
                Node *temp;
                temp = p->next;
                p->next = p->next->next;
                delete temp;
            }
            else
            {
                p = p->next;
            }
        }
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

    x.insertAtBeginning(1);
    x.insertAtBeginning(1);
    x.insertAtBeginning(1);
    x.insertAtBeginning(2);
    x.insertAtBeginning(2);
    x.insertAtBeginning(3);
    x.insertAtBeginning(4);
    x.insertAtBeginning(4);
    x.insertAtBeginning(5);
    x.insertAtBeginning(5);

    x.display();

    x.removeDuplicates();

    x.display();

}