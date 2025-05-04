/*
Given a binary tree and the task is to find the spiral order traversal of the tree and return the list containing the elements.
Spiral order Traversal mean: Starting from level 0 for root node, for all the even levels we print the node's value from right to 
left and for all the odd levels we print the node's value from left to right.
For below tree, function should return [1, 2, 3, 4, 5, 6, 7]

 spiral_order

Examples:

Input: root = [1, 3, 2]
      1
    /   \
   3     2
Output: [1, 3, 2]
Explanation: Start with root (1), print level 0 (right to left), then level 1 (left to right).
Input: root = [10, 20, 30, 40, 60]

           10
         /     \
        20     30
      /    \
    40     60
Output: [10, 20, 30, 60, 40]
Explanation: Start with root (10), print level 0 (right to left), level 1 (left to right), and continue alternating.
Input: root = [1, 2, N, 4]
           1
         /     
        2    
      /   
    4     
Output: [1, 2, 4]
Explanation: Start with root (1), then level 1 (left to right), then level 2 (right to left).
Constraints:
1 <= number of nodes <= 105
0 <= node->data <= 105


*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
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
      vector<int> findSpiral(Node* root) {
          // code here
          stack<Node*>s1;
          stack<Node*>s2;
          
          s1.push(root);
          vector<int>ans;
          
          while(!s1.empty() || !s2.empty())
          {
              if(!s1.empty())
              {
                  while(!s1.empty())
                  {
                      Node *temp = s1.top();
                      s1.pop();
                      ans.push_back(temp->data);
                      if(temp->right)
                      {
                          s2.push(temp->right);
                      }
                      if(temp->left)
                      {
                          s2.push(temp->left);
                      }
                  }
              }
              
              else
              {
                  while(!s2.empty())
                  {
                      Node *temp = s2.top();
                      s2.pop();
                      ans.push_back(temp->data);
                      if(temp->left)
                      {
                          s1.push(temp->left);
                      }
                      if(temp->right)
                      {
                          s1.push(temp->right);
                      }
                  }
              }
          }
          return ans;
      }
  };