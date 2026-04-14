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
    void undo()
    {
        if(s == NULL)
        {
            return;
        }
        Node *p;
        p=s;
        s = s->next;
        delete p;
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
    LinkedList x;
    x.insertAtBeginning(10);
    x.insertAtBeginning(20);
    x.insertAtBeginning(30);
    x.display();
    
    x.undo();
    x.display();

    x.undo();
    x.display();

    x.undo();
    x.display();
}