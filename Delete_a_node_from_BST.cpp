/*
Given a Binary Search Tree and a node value x. Delete the node with the given value x from the BST. If no node with value x exists, 
then do not make any change. Return the root of the BST after deleting the node with value x.

Note: The generated output will be the inorder traversal of the modified tree.

Examples :

Input: root = [2, 1, 3]
      2
    /   \
   1     3
x = 12
Output: 1 2 3
Explanation: In the given input there is no node with value 12 , so the tree will remain same.
Input: root = [1, N, 2, N, 8, 5, 11, 4, 7, 9, 12]
            1
             \
              2
                \
                 8 
               /    \
              5      11
            /  \    /  \
           4    7  9   12
x = 11
Output: 1 2 4 5 7 8 9 12
Explanation: In the given input, tree after deleting 11 will be
             1
              \
               2
                 \
                  8
                 /  \
                5    12
               / \   /
              4   7 9 
Input: root = [2, 1, 3]
      2
    /   \
   1     3
x = 3
Output: 1 2
Explanation: In the given input, tree after deleting 3 will be
     2
    /   
   1    
Constraints:
1 <= n <= 105

Expected Complexities
Time Complexity: O(Height of the BST)
Auxiliary Space: O(Height of the BST)

*/

#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *left , *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    // Function to delete a node from BST.
    Node *deleteNode(Node *root, int target) {
        // your code goes here
        if(!root)
        {
            return NULL;
        }
        
        if(root->data>target)
        {
            root->left = deleteNode(root->left,target);
            return root;
        }
        
        else if(root->data<target)
        {
            root->right = deleteNode(root->right,target);
            return root;
        }
        
        else
        {
            if(!root->left && !root->right)
            {
                delete root;
                return NULL;
            }
            
            else if(!root->right)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }
            
            else if(!root->left)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }
            
            else
            {
                Node *child = root->left;
                Node *parent = root;
                
                while(child->right)
                {
                    parent = child;
                    child = child->right;
                }
                
                if(root!=parent)
                {
                    parent->right = child->left;
                    child->left = root->left;
                    child->right = root->right;
                    delete root;
                    return child;
                }
                
                else
                {
                    child->right = root->right;
                    delete root;
                    return child;
                }
            }
        }
    }
};