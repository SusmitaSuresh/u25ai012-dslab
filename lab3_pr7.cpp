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

    void reverseInBatches(int k)
    {
        if (s == NULL || s->next == NULL || k <= 1)
        {
            cout<<"invalid"<<endl;
            return;
        }

        Node *p = NULL, *q = s, *r = NULL;
        Node *prevGrpEnd = NULL;
        Node *newHead = NULL;

        while (q != NULL)
        {
            /* Step 1: check k nodes */
            Node *temp = q;
            int co = 0;
            while (temp != NULL && co < k)
            {
                temp = temp->next;
                co++;
            }

            if (co < k)
            {
                if (prevGrpEnd != NULL)
                {
                    prevGrpEnd->next = q;
                }
                break;
            }

            Node *grpStart = q;   // will become end of the grp after reversal
            p = NULL;
            r = NULL;

            for (int i = 0; i < k; i++)
            {
                r = q->next;
                q->next = p;
                p = q;
                q = r;
            }

            if (newHead == NULL)
            {
                newHead = p;
            }
            else
            {
                prevGrpEnd->next = p;       // p is the HEAD of current reversed group
            }
            prevGrpEnd = grpStart;      //the new group start should be previous grpup end
        }
        s = newHead;
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
    x.insertAtBeginning(110);

    x.display();

    x.reverseInBatches(4);

    x.display();

}