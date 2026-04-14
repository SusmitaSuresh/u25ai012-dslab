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

    void findMiddle()
    {
        if(s == NULL)
        {
            cout<<"list empty"<<endl;
            return;
        }
        Node *p;
        p = s;
        int count = 0;
        while(p!=NULL)
        {
            p = p->next;
            count++;
        }
        p = s;
        if(count%2==0)
        {
            for(int i=0; i<count/2-1; i++)
            {
                p = p->next;
            }
            cout<<p->data<<"and"<<p->next->data<<"are the middle terms"<<endl;
        }
        else
        {
            for(int i=0; i<count/2; i++)
            {
                p = p->next;
            }
            cout<<p->data<<"is the middle term"<<endl;
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
    x.insertAtBeginning(100);


    x.display();

    x.findMiddle();
}