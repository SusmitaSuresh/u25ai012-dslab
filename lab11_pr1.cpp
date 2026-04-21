/*1. Representation of Binary Tree
Aim:
To represent a binary tree using array and linked list representation.
Expected Approach:
Array: Parent-child indexing
Linked list: Node with data, left, and right pointers*/


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

int main()
{
    Node *root = new Node(10);
    Node *lchild = new Node(2);
    Node *rchild = new Node(7);

    root->left = lchild;
    root->right = rchild;

    cout<<"tree is: "<<endl;
    cout<<root->left->data<<"<-"<<root->data<<"->"<<root->right->data<<endl;
    
}