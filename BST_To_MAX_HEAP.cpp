/*
Given a Binary Search Tree. Convert a given BST into a Special Max Heap with the condition that all the values 
in the left subtree of a node should be less than all the values in the right subtree of the node. 
This condition is applied on all the nodes in the so converted Max Heap.

Example 1:

Input :
                 4
               /   \
              2     6
            /  \   /  \
           1   3  5    7  

Output : 1 2 3 4 5 6 7 
Exaplanation :
               7
             /   \
            3     6
          /   \  /   \
         1    2 4     5
The given BST has been transformed into a
Max Heap and it's postorder traversal is
1 2 3 4 5 6 7.

Your task :
You don't need to read input or print anything. Your task is to complete the function convertToMaxHeapUtil() 
which takes the root of the tree as input and converts the BST to max heap.
Note : The driver code prints the postorder traversal of the converted BST.
 
Expected Time Complexity : O(n)
Expected Auxiliary Space : O(n)
 
Constraints :
1 ≤ n ≤ 105
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
  void Inorder(Node* root, vector<int>&ans)
  {
      if(!root)
      {
          return;
      }
      Inorder(root->left,ans);
      ans.push_back(root->data);
      Inorder(root->right,ans);
  }
  
  void Postorder(Node* root, int&index, vector<int>&ans)
  {
      if(!root)
      {
          return ;
      }
      Postorder(root->left,index,ans);
      Postorder(root->right,index,ans);
      
      root->data=ans[index];
      index++;
  }
    void convertToMaxHeapUtil(Node* root) {
        // Your code goes here
        if(!root)
        {
            return;
        }
        
        vector<int>ans;
        Inorder(root,ans);
        int index = 0;
        Postorder(root,index,ans);
    }
};
