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
    Node *s = NULL;
    public:

    void insertAtBeginning(int data)
    {
        Node *q = new Node;
        q->data = data;
        q->next = s;
        s=q;
    }

    void deleteByLastPosition(int pos)
    {
        if(s == NULL)
        {
            cout<<"empty linked list"<<endl;
            return;
        }
        if(pos<1)
        {
            cout<<"invalid position"<<endl;
            return;
        }
        int co=1;           //1 based indexing from the end
        Node *p, *q;
        p = s;
        q = s;
        while(q->next!=NULL)
        {
            q = q->next;
            if(co>pos)      //we get p and q to have 'pos-1' no. of elements between them
            {
                p = p->next;
            }
            co++;
        }
        if(co<pos)  //if q is at last element before they reach the expected no. of gaps, then its invalid
        {
            cout<<"invalid position"<<endl;
        }
        else if(co == pos)  //this means that the moment q reaches null, no. of gaps recieved
        {                   //so that implies starting Node should be deleted
            s = s->next;
            delete p;
        }
        else
        {
            q = p->next;
            p->next = q->next;
            delete q;
        }
    }
    
    void display()
    {
        if(s == NULL)
        {
            cout<<"linked list is empty"<<endl;
            return;
        }
        Node *p;
        p = s;
        while(p != NULL)
        {
            
            cout<<p->data;
            if(p->next != NULL)       //it comes as 10->20->30 no arrow in the end
            {
                cout<<"->";
            }
            p = p->next;
        }
        cout<<endl<<endl;
    }
};

int main()
{
    LinkedList x;
    x.insertAtBeginning(50);
    x.insertAtBeginning(40);
    x.insertAtBeginning(30);
    x.insertAtBeginning(20);
    x.insertAtBeginning(10);

    x.display();


    x.deleteByLastPosition(1);
    x.display();

    x.deleteByLastPosition(2);
    x.display();

    x.deleteByLastPosition(3);
    x.display();

    x.deleteByLastPosition(1);
    x.display();
}