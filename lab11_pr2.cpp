/*Aim:
To perform different tree traversal techniques.

Traversals:
Inorder (Left → Root → Right)
Preorder (Root → Left → Right)
Postorder (Left → Right → Root)*/


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

class BinaryTree
{
    public:

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
    void PreOrderTraversal(Node *x)
    {
        if(x == NULL)
        {
            return;
        }
        cout<<x->data<<" ";
        PreOrderTraversal(x->left);
        PreOrderTraversal(x->right);
    }
    void PostOrderTraversal(Node *x)
    {
        if(x == NULL)
        {
            return;
        }
        PostOrderTraversal(x->left);
        PostOrderTraversal(x->right);
        cout<<x->data<<" ";
    }
};

int main()
{
    Node *root = new Node(10);
    Node *lchild = new Node(2);
    Node *rchild = new Node(7);

    BinaryTree x = BinaryTree();

    root->left = lchild;
    root->right = rchild;

    cout<<"inOrder: ";
    x.InOrderTraversal(root);
    cout<<endl;

    cout<<"preOrder: ";
    x.PreOrderTraversal(root);
    cout<<endl;

    cout<<"postOrder: ";
    x.PostOrderTraversal(root);
    cout<<endl;
    
}