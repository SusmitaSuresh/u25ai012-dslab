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
    void insertAtGivenPosition(int pos, int data)
    {
        Node *q = new Node;
        int co = 0;
        if(pos == 0)
        {
            q->data = data;
            q->next = s;
            s = q;
            return;
        }
        Node *p = s;
        while(co<pos-1)
        {         
            if(p == NULL)
            {
                cout<<"invalid position"<<endl;
                return;
            }
            p = p->next;
            co++;
        }
        q->next = p->next;
        p->next = q;
        q->data = data;        
    }
    void deleteByPosition(int pos)
    {
        int co=0;
        if(s==NULL)
        {
            cout<<"linked list is empty"<<endl;
            return;
        }
        if(pos<0)
        {
            cout<<"invalid position"<<endl;
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
        {                       //so we end up getting segmentation fault for single element list
            cout<<"position given is wrong"<<endl;
            return;
        }
        q->next = p->next;
        delete p;
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
    
    x.insertAtGivenPosition(0,10);
    x.display();
    cout<<endl;

    x.insertAtGivenPosition(3,10);
    x.display();
    cout<<endl;

    x.insertAtGivenPosition(1,20);
    x.display();
    cout<<endl;

    x.insertAtGivenPosition(0,30);
    x.display();
    cout<<endl;

    x.insertAtGivenPosition(3,70);
    x.display();
    cout<<endl;
    
    x.deleteByPosition(3);
    x.display();
    cout<<endl;

    x.deleteByPosition(0);
    x.display();
    cout<<endl;
    
    x.deleteByPosition(-1);
    x.display();
    cout<<endl;

}