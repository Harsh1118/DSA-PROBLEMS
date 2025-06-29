/*
Given an AVL tree and N values to be deleted from the tree. Write a function to delete a given value from the tree. All the N values which 
needs to be deleted are passed one by one as input data by driver code itself, you are asked to return the root of modified tree after deleting 
the value.

Example 1:

Tree = 
        4
      /   \
     2     6
    / \   / \  
   1   3 5   7

N = 4
Values to be deleted = {4,1,3,6}

Input: Value to be deleted = 4
Output:
        5    
      /   \
     2     6
    / \     \  
   1   3     7

Input: Value to be deleted = 1
Output:
        5    
      /   \
     2     6
      \     \  
       3     7

Input: Value to be deleted = 3
Output:
        5    
      /   \
     2     6
            \  
             7

Input: Value to be deleted = 6
Output:
        5    
      /   \
     2     7

Your Task:  
You dont need to read input or print anything. Complete the function delelteNode() which takes the root of the tree and the value of the node to 
be deleted as input parameters and returns the root of the modified tree.

Note: The tree will be checked after each deletion. 
If it violates the properties of balanced BST, an error message will be printed followed by the inorder traversal of the tree at that moment.
If instead all deletion are successful, inorder traversal of tree will be printed.
If every single node is deleted from tree, 'null' will be printed.

Expected Time Complexity: O(height of tree)
Expected Auxiliary Space: O(height of tree)

Constraints:
1 ≤ N ≤ 500
*/

#include<iostream>
using namespace std;

class Node
{
    public:
    int data , height;
    Node* left , *right;

    Node(int val)
    {
        data = val;
        height = 1;
        left = right = NULL;
    }
};

int getheight(Node *root)
{
    if(!root)
    {
        return 0;
    }
    return root->height;
}

int getbalance(Node* root)
{
    return getheight(root->left) - getheight(root->right);
}

Node* rightRotation(Node* root)
{
    Node* child = root->left;
    Node* childright = child->right;
    
    child->right = root;
    root->left = childright;
    
    root->height = 1 + max(getheight(root->left),getheight(root->right));
    child->height = 1 + max(getheight(child->left),getheight(child->right));
    
    return child;
}

Node* leftRotation(Node* root)
{
    Node *child = root->right;
    Node *childleft = child->left;
    
    child->left = root;
    root->right = childleft;
    
    root->height = 1 + max(getheight(root->left),getheight(root->right));
    child->height = 1 + max(getheight(child->left),getheight(child->right));
    
    return child;
}

Node* deleteNode(Node* root, int key) {
    // add code here,
    if(!root)
    {
        return NULL;
    }
    
    if(key<root->data)
    {
        root->left = deleteNode(root->left,key);
    }
    else if(key>root->data)
    {
        root->right = deleteNode(root->right,key);
    }
    else
    {
        //Leaf Node
        if(!root->left && !root->right)
        {
            delete root;
            return NULL;
        }
        else if(root->left && !root->right)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else if(!root->left && root->right)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else
        {
            Node* curr = root->right;
            while(curr->left)
            {
                curr = curr->left;
            }
            root->data = curr->data;
            root->right = deleteNode(root->right,curr->data);
        }
    }
    root->height = 1 + max(getheight(root->left),getheight(root->right));
    
    
    int balance = getbalance(root);
    
    if(balance>1)
    {
        if(getbalance(root->left)>=0)
        {
            return rightRotation(root);
        }
        else
        {
            root->left = leftRotation(root->left);
            return rightRotation(root);
        }
        
    }
    else if(balance<-1)
    {
        if(getbalance(root->right)<=0)
        {
            return leftRotation(root);
        }
        else
        {
            root->right = rightRotation(root->right);
            return leftRotation(root);
        }
        
    }
    else
    {
        return root;
    }
}