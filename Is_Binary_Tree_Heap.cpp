/*
You are given a binary tree, and the task is to determine whether it satisfies the properties of a max-heap.

A binary tree is considered a max-heap if it satisfies the following conditions:

Completeness: Every level of the tree, except possibly the last, is completely filled, and all nodes are as far 
left as possible.
Max-Heap Property: The value of each node is greater than or equal to the values of its children.
Examples:

Input: root[] = [97, 46, 37, 12, 3, 7, 31, 6, 9]
 
Output: true
Explanation: The tree is complete and satisfies the max-heap property.
Input: root[] = [97, 46, 37, 12, 3, 7, 31, N, 2, 4] 
 
Output: false
Explanation: The tree is not complete and does not follow the Max-Heap Property, hence it is not a max-heap.
Constraints:
1 ≤ number of nodes ≤ 103
1 ≤ node->data ≤ 103

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(n)
*/
#include<iostream>
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
  int count(Node* root)
  {
      if(!root)
      {
          return 0;
      }
      return 1+count(root->left)+count(root->right);
  }
  
  bool CBT(Node* root, int index, int total_nodes)
  {
      if(!root)
      {
          return 1;
      }
      if(index>=total_nodes)
      {
          return 0;
      }
      return CBT(root->left,2*index+1,total_nodes) && CBT(root->right,2*index+2,total_nodes);
  }
  
  bool MaxHeap(Node* root)
  {
      if(root->left)
      {
          if(root->data<root->left->data)
          {
              return 0;
          }
          
          if(!MaxHeap(root->left))
          {
              return 0;
          }
      }
      
      if(root->right)
      {
          if(root->data<root->right->data)
          {
              return 0;
          }
          
          return MaxHeap(root->right);
      }
      
      return 1;
  }
  
    bool isHeap(Node* tree) {
        // code here
        int n = count(tree);
        
        if(!CBT(tree,0,n))
        {
            return 0;
        }
        
        return MaxHeap(tree);
    }
};