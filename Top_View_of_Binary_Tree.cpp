/*
You are given a binary tree, and your task is to return its top view. The top view of a binary tree is the set of nodes visible when the 
tree is viewed from the top.

Note: 

Return the nodes from the leftmost node to the rightmost node.
If two nodes are at the same position (horizontal distance) and are outside the shadow of the tree, consider the leftmost node only. 
Examples:

Input: root[] = [1, 2, 3] 
 
Output: [2, 1, 3]
Input: root[] = [10, 20, 30, 40, 60, 90, 100]
 
Output: [40, 20, 10, 30, 100]
Explanation: The root 10 is visible.
On the left, 40 is the leftmost node and visible, followed by 20.
On the right, 30 and 100 are visible. Thus, the top view is 40 20 10 30 100.
Input: root[] = [1, 2, 3, N, 4, N, N, N, 5, N, 6]
       1
     /   \
    2     3
     \   
      4
       \
        5
         \
          6
Output: [2, 1, 3, 6]
Explanation: Node 1 is the root and visible.
Node 2 is the left child and visible from the left side.
Node 3 is the right child and visible from the right side.
Nodes 4, 5, and 6 are vertically aligned, but only the lowest node 6 is visible from the top view. Thus, the top view is 2 1 3 6.
Constraints:
1 ≤ number of nodes ≤ 105
1 ≤ node->data ≤ 105


*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
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
      // Function to return a list of nodes visible from the top view
      // from left to right in Binary Tree.
      void find(Node *root , int pos , int &l , int &r)
      {
          if(!root)
          {
              return ;
          }
          
          l = min(l,pos);
          r = max(r,pos);
          
          find(root->left,pos-1,l,r);
          find(root->right,pos+1,l,r);
      }
      
      void tview(Node *root , int pos , vector<int>&ans , vector<int>&level , int lev)
      {
          if(!root)
          {
              return ;
          }
          
          if(level[pos]>lev)
          {
              ans[pos]=root->data;
              level[pos]=lev;
          }
          
          tview(root->left,pos-1,ans,level,lev+1);
          tview(root->right,pos+1,ans,level,lev+1);
      }
      
      
      vector<int> topView(Node *root) {
          // code here
          int l = 0 , r = 0;
          find(root,0,l,r);
          vector<int>ans(r-l+1);
          vector<int>level(r-l+1,INT_MAX);
          
          tview(root,-1*l,ans,level,0);
         return ans;
         
      }
  };
