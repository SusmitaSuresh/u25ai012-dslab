#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Chaining
{
    public:
    Node* *hash;   //creating pointer of type node pointer is so cool-> it just means double pointer tho-> shut up let me be happy 
    int m;
    Chaining(int n)
    {
        m = n;
        hash = new Node*[m];
        for(int i=0; i<m; i++)
        {
            hash[i] = NULL;
        }
    }

    int HF(int key)
    {
        return key%m;
    }

    void createHashTable(int arr[])
    {
        for(int i=0; i<m; i++)
        {
            Node *p = new Node(arr[i]);
            if(hash[HF(arr[i])]==NULL)
            {
                hash[HF(arr[i])] = p;
            }
            else
            {
                p->next = hash[HF(arr[i])];
                hash[HF(arr[i])] = p;
            }
        }
    }

    void displayHashTable()
    {
        for(int i=0; i<m; i++)
        {
            Node *p = hash[i];
            while(p!=NULL)
            {
                cout<<p->data;
                p = p->next;
            }
            cout<<endl;
        }
    }
};

int main()
{
    int n;
    int *a;
    cout<<"enter number of elements in a: "<<endl;
    cin>>n;
    a = new int[n];
    cout<<"enter elements of a: "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }

    Chaining ch = Chaining(n);
    ch.createHashTable(a);
    ch.displayHashTable();

}