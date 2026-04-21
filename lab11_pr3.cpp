/*Aim:
To insert elements into a Binary Search Tree.*/

#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class BinarySearchTree
{
    public:
    Node *root;
    BinarySearchTree(int x)
    {
        root = new Node(x);
        root->data = x;
    }

    Node* getRoot()
    {
        return root;
    }
    
    void insert(Node *r, int x)
    {
        if(x<=r->data)
        {
            if(r->left == NULL)
            {
                Node *n = new Node(x);
                r->left = n;
            }
            else
            {
                insert(r->left,x);
            }
        }
        else
        {
            if(r->right == NULL)
            {
                Node *n = new Node(x);
                r->right = n;
            }
            else
            {
                insert(r->right,x);
            }
        }
    }

    void InOrderTraversal(Node *x)
    {
        if(x == NULL)
        {
            return;
        }
        InOrderTraversal(x->left);
        cout<<x->data<<" ";
        InOrderTraversal(x->right);
    }
    
};

int main()
{
    BinarySearchTree bst = BinarySearchTree(10);

    bst.insert(bst.getRoot(), 29);
    bst.insert(bst.getRoot(), 69);
    bst.insert(bst.getRoot(), 2);
    bst.insert(bst.getRoot(), 0);
    bst.insert(bst.getRoot(), 4);
    bst.insert(bst.getRoot(), 34);  
    
    cout<<"tree is: (inorder)"<<endl;
    bst.InOrderTraversal(bst.getRoot());
}