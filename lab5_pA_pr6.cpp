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

    bool checkPalindrome()
    {
        Node *p = s, *q = s;
        while(q->next!=NULL)
        {
            q = q->next;
        }
        while(p!=q && p->prev!=q)
        {
            if(p->data!=q->data)
            {
                return false;
            }
            p = p->next;
            q = q->prev;
        }
        return true;
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
    x.insert(1);
    x.insert(2);
    x.insert(3);
    x.insert(4);
    x.insert(5);
    x.insert(3);
    x.insert(2);
    x.insert(1);

    x.display();

    if(x.checkPalindrome())
    {
        cout<<"palindrome";
    }
    else
    {
        cout<<"not palindrome";
    }
}