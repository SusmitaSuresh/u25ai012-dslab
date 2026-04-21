/*Aim:
To delete elements from a Binary Search Tree.*/

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
    Node *root= NULL;

    Node* getRoot()
    {
        return root;
    }
    
    void insert(Node *r, int x)
    {
        if(r==NULL)
        {
            root = new Node(x);
            return;
        }
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

    Node* deleteNode(Node* r, int x)
    {
        if(r == NULL)
        {
            return NULL;
        }
        if(x < r->data)
        {
            r->left = deleteNode(r->left, x);   //recursivelly we find what the child will be
        }
        else if(x > r->data)
        {
            r->right = deleteNode(r->right, x);
        }
        else
        {
            if(r->left == NULL && r->right == NULL)     //when leaf, we simply delete
            {
                delete r;
                return NULL;
            }
            else if(r->left == NULL)        //one child, we give the child as new parent
            {
                Node* temp = r->right;
                delete r;
                return temp;
            }
            else if(r->right == NULL)
            {
                Node* temp = r->left;
                delete r;
                return temp;
            }
            else        //for 2child, we find max of lst, or min of rst and give that as new parent
            {
                Node* succ = r->right;
                while(succ->left != NULL)
                {
                    succ = succ->left;
                }
                r->data = succ->data;
                r->right = deleteNode(r->right, succ->data);
            }
        }
        return r;
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
    BinarySearchTree bst = BinarySearchTree();

    bst.insert(bst.getRoot(), 29);
    bst.insert(bst.getRoot(), 69);
    bst.insert(bst.getRoot(), 2);
    bst.insert(bst.getRoot(), 0);
    bst.insert(bst.getRoot(), 4);
    bst.insert(bst.getRoot(), 34);  
    
    cout<<"tree is: (inorder)"<<endl;
    bst.InOrderTraversal(bst.getRoot());
}