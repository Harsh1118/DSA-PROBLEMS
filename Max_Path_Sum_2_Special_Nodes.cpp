/*
Given a binary tree in which each node element contains a number. Find the maximum possible path sum from one special node 
to another special node.

Note: Here special node is a node that is connected to exactly one different node.

Examples:

Input: root = [3, 4, 5, -10, 4, N, N]
                         
Output: 16
Explanation: Maximum Sum lies between special node 4 and 5. 4 + 4 + 3 + 5 = 16.
Input: root = [-15, 5, 6, -8, 1, 3, 9, 2, -3, 0, 4, -1, 10]


Output:  27
Explanation: The maximum possible sum from one special node to another is (3 + 6 + 9 + 0 + -1 + 10 = 27)
Input: root = [3, 4, 1, -10, 4] 

                         
Output: 12
Explanation: Maximum Sum lies between special node 4 and 5. 4 + 4 + 3 + 1 = 12.
Constraints:
2  ≤  number of nodes  ≤  104
-103  ≤ node->data ≤ 103

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(n)
*/
#include<iostream>
#include<climits>
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
  
  int pathsum(Node*root,int &sum)
  {
      if(!root)
      {
          return 0;
      }
      
      if(!root->left && !root->right)
      {
          return root->data;
      }
      
      int left = pathsum(root->left,sum);
      int right = pathsum(root->right,sum);
      
      if(root->left && root->right)
      {
          sum = max(sum,root->data+left+right);
          return root->data+max(left,right);
      }
      
      if(root->left)
      {
          return root->data+left;
      }
      
      if(root->right)
      {
          return root->data+right;
      }
  }
  
    int maxPathSum(Node* root) {
        // code here
        int sum = INT_MIN;
        int val = pathsum(root,sum);
        
        if(root->left&&root->right)
        {
            return sum;
        }
        
        return max(sum,val);
    }
};
