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
    Node *end = NULL;

    public:
    void insertAtTail(int data)
    {
        Node *q = new Node;
        if(s == NULL)
        {
            q->data = data;
            q->next = NULL;
            s = q;
            end = q;
            return;
        }
        q->data = data;
        q->next = NULL;
        end->next = q;
        end = q;
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
    }
};


int main()
{
    LinkedList x;
    x.insertAtTail(10);
    x.display();
    cout<<endl;

    x.insertAtTail(20);
    x.display();
    cout<<endl;
    x.insertAtTail(30);
    
    x.display();
    cout<<endl;


    x.insertAtTail(40);
    x.display();
    cout<<endl;
}