using namespace std;
#include<iostream>

class Node
{
    public:
    int data;
    Node *next;
    Node *prev;
    Node()
    {
        next = NULL;
        prev = NULL;
    }
};

class LinkedList
{
    private: 
    Node *s = NULL;    //start

    public:

    void insert(int x)
    {
        Node *p = new Node();
        p->data = x;
        p->prev = NULL;
        if(s == NULL)
        {
            p->next = s;
            s = p;
        }
        else
        {
            p->next = s;
            s->prev = p;
            s = p;
        }
    }

    void findSum(int target)        //it will show only once (smallest with largest)
    {
        Node *p = s;
        Node *q = s;
        int sum;
        while(q->next!=NULL)
        {
            q = q->next;
        }
        cout<<"pairs with given sum:"<<endl;
        while(p!=q && p->prev!=q)
        {
            sum = p->data + q->data;
            if(sum == target)
            {
                cout<<"("<<p->data<<","<<q->data<<")"<<endl;
                p = p->next;        //assuming that if list has 10 10 20 then only once it prints 10,20 is target is 30
                q = q->prev;
            }
            else if(sum>target)
            {
                q = q->prev;
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
            if(p->next!=NULL)        
            {
                cout<<"-><-";
            }
            p = p->next;
        }
        cout<<endl;
    }
};

int main()
{
    LinkedList x;
    x.insert(80);
    x.insert(70);
    x.insert(60);
    x.insert(50);
    x.insert(40);
    x.insert(30);
    x.insert(20);
    x.insert(10);

    x.display();
    x.findSum(60);

}