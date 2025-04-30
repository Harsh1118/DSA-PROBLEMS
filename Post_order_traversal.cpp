/*
Given a binary tree, find the Postorder Traversal of it and return a list containing the postorder traversal of the given tree.

Examples:

Input: root = [19, 10, 8, 11, 13]
        19
     /     \
    10      8
  /    \
 11    13
Output: [11, 13, 10, 8, 19]
Input: root = [11, 15, N, 7]
          11
         /
       15
      /
     7
Output: [7, 15, 11]
Constraints:
1 <= number of nodes <= 105
0 <= node->data <= 106
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

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution {
    public:
    void post(vector<int>&ans , Node *root)
    {
        if(root==NULL)
        {
            return;
        }
        post(ans,root->left);
        post(ans,root->right);
        ans.push_back(root->data);
    }
      // Function to return a list containing the postorder traversal of the tree.
      vector<int> postOrder(Node* root) {
          // Your code here
          vector<int>ans;
          post(ans,root);
          return ans;
      }
  };