/*
Given two arrays representing the inorder and preorder traversals of a binary tree, construct the tree and return 
the root node of the constructed tree.

Note: The output is written in postorder traversal.

Examples:

Input: inorder[] = [1, 6, 8, 7], preorder[] = [1, 6, 7, 8]
Output: [8, 7, 6, 1]
Explanation: The tree will look like

Input: inorder[] = [3, 1, 4, 0, 2, 5], preorder[] = [0, 1, 3, 4, 2, 5]
Output: [3, 4, 1, 5, 2, 0]
Explanation: The tree will look like

Input: inorder[] = [2, 5, 4, 1, 3], preorder[] = [1, 4, 5, 2, 3]
Output: [2, 5, 4, 3, 1]
Explanation: The tree will look like

Constraints:
1 ≤ number of nodes ≤ 103
0 ≤ nodes -> data ≤ 103
Both the inorder and preorder arrays contain unique values.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Node
{
    public:
    int data;
    Node *left , *right;

    Node (int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution {
    public:
    
    int find(vector<int>&inorder , int target , int start , int end )
    {
        for(int i = start; i<=end; i++)
        {
            if(inorder[i]==target)
            {
                return i;
            }
        }
        return -1;
    }
    
    Node *Tree(vector<int>&inorder,vector<int>&preorder, int Instart , int Inend , int index)
    {
        if(Instart>Inend)
        {
            return NULL;
        }
        
        Node *root = new Node(preorder[index]);
        int pos = find(inorder,preorder[index],Instart,Inend);
        
        root->left = Tree(inorder,preorder,Instart , pos-1 , index+1);
        root->right = Tree(inorder , preorder , pos+1 , Inend , index+(pos-Instart)+1);
        
        return root;
        
    }
      // Function to build the tree from given inorder and preorder traversals
      Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
          // code here
          int n = preorder.size();
          return Tree(inorder,preorder,0,n-1,0);
      }
  };