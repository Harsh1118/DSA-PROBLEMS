/*
Given a binary tree, return an array where elements represent the bottom view of the binary tree from left to right.

Note: If there are multiple bottom-most nodes for a horizontal distance from the root, then the latter one in the level 
traversal is considered. For example, in the below diagram, 3 and 4 are both the bottommost nodes at a horizontal distance of 0, 
here 4 will be considered.

                      20
                    /    \
                  8       22
                /   \     /   \
              5      3 4     25
                     /    \      
                 10       14

For the above tree, the output should be 5 10 4 14 25.

Examples :

Input:
       1
     /   \
    3     2
Output: 3 1 2
Explanation: First case represents a tree with 3 nodes and 2 edges where root is 1, left child of 1 is 3 and right child of 1 is 2.

Thus bottom view of the binary tree will be 3 1 2.
Input:
         10
       /    \
      20    30
     /  \
    40   60
Output: 40 20 60 30
Input:
        1
       /   
      2
Output: 2 1
Constraints:
1 <= number of nodes <= 105
1 <= node->data <= 105


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

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution {
    public:
    void find(Node *root , int pos , int &l , int &r)
    {
        if(!root)
        {
            return;
        }
        
        l = min(l,pos);
        r = max(r,pos);
        
        find(root->left,pos-1,l,r);
        find(root->right,pos+1,l,r);
    }
    
    void tview(Node *root , int pos,vector<int>&ans, vector<int>&level, int lev)
    {
        if(!root)
        {
            return;
        }
        if(level[pos]<lev)
        {
            ans[pos]=root->data;
            level[pos]=lev;
        }
        tview(root->left,pos-1,ans,level,lev+1);
        tview(root->right,pos+1,ans,level,lev+1);
    }
      vector<int> bottomView(Node *root) {
          // Your Code Here
          int l = 0, r=0;
          find(root,0,l,r);
          vector<int>ans(r-l+1);
          vector<int>level(r-l+1,0);
          
          tview(root,-1*l,ans,level,0);
          return ans;
      }
  };