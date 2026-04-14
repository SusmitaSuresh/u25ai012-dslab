using namespace std;
#include<iostream>
#include<vector>

class Node
{
    public:
    int data;
    Node *next;
};

class LinkedList
{
    private: 
    vector<Node*> start;

    public:

    LinkedList(vector<Node*> s1)
    {
        start = s1;     //we get an array of start nodes    (vector is a dynamically sized array)
    }

    void mergeKsortedLinkedLists()
    {
        for(int i=0; i<start.size()-1; i++)
        {
            Node *s = start[i];
            Node *s1 = start[i+1];
            if(s == NULL)
            {
                continue;
            }
            if(s1 == NULL &&s!=NULL)
            {
                start[i+1] = start[i];
                continue;
            }
            if(s->data > s1->data)
            {
                Node *temp = s;
                s = s1;
                s1 = temp;
            }
            Node *p, *q, *r;
            r = s;
            p = s->next;
            q = s1;
            while(p!=NULL && q!=NULL)
            {
                if(p!=NULL && p->data <= q->data)
                {
                    r->next = p;
                    p = p->next;
                    r = r->next;
                }
                else
                {
                    r->next = q;
                    if(q!=NULL)
                    {
                        q = q->next;
                    }
                    r = r->next;
                }
            }
            if(p!=NULL && q==NULL)
            {
                while(p!=NULL)
                {
                    r->next = p;
                    p = p->next;
                    r = r->next;
                }
            }
            else if(p == NULL && q!=NULL)
            {
            while(q!=NULL)
                {
                    r->next = q;
                    q = q->next;
                    r = r->next;
                } 
            }  
            start[i+1] = s; 
        }
        display(start.back());
    }

    void display(Node *s)
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
    
}