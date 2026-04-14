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
    Node *s;
    public:
    void detectCycleAndUnlink()
    {
        Node *p, *q;
        p = s;      //slow
        q = s;      //fast

        while(q!=NULL && q->next!=NULL)
        {
            p = p->next;
            q = q->next->next;
            if(q == p)    //if cycle detected then outside loop stops and inside loops run so its still O(n)
            {
                p = s;    //we start again from start and move both pointers by one, if they meet then thats the starting position
                while(p!=q)
                {
                    p = p->next;
                    q = q->next;
                }
                while(q->next!=p)   //then we find the last node of the cycle and then inlink it
                {
                    q = q->next;
                }
                q->next = NULL;
                return;
            }
        }
        cout<<"cycle not detected"<<endl;
    }
};

int main()
{
    LinkedList x;
    //idk how to show output??
}