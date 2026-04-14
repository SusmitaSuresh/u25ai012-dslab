#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    int priority;
    Node *next;
    Node()
    {
        next = NULL;
    }
    Node(int x, int pr)
    {
        data = x;
        priority = pr;
        next = NULL;
    }
};


class Queue
{
    public:
    Node *top = NULL;
    
    void push(int x, int pr)
    {
        Node *p = new Node(x, pr);
        if(top == NULL)
        {
            top = p;
            return;
        }
        Node *q = top;
        Node *r = NULL;
        while(q!=NULL)
        {
            if(p->priority <= q->priority )
            {
                p->next = q;
                if(r!=NULL)
                {
                    r->next = p;
                }
                else
                {
                    top = p;
                }
                return;
            }
            r = q;
            q = q->next;
        }       
        r->next = p;
    }

    void pop()
    {
        if(top  == NULL)
        {
            cout<<"empty"<<endl;
            return;
        }
        Node *p = top;
        top = top->next;
        delete p;
    }

    int peek()     //not naming it top because top is a variable and i don't wanna be confused
    {
        if(top == NULL)
        {
            cout<<"enpty";
            return 0;
        }
        else
        {
            return top->data;
        }
    }

    void display()
    {
        if(top==NULL)
        {
            cout<<"linked list is empty"<<endl;
            return;
        }
        Node *p;
        p = top;
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
    Queue x;

    x.push(1, 3);
    x.push(4, 2);
    x.push(5, 7);
    x.push(2, 1);
    x.display();
    cout<<x.peek()<<endl;
    x.pop();
    x.pop();
    x.display();
    cout<<x.peek()<<endl;

    x.pop();
    x.pop();
    x.display();
    cout<<x.peek()<<endl;
    x.pop();   
    cout<<x.peek()<<endl;

}