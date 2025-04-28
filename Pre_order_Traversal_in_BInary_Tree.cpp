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

/*Given a binary tree, find its preorder traversal.

Examples:

Input:
        1      
      /          
    4    
  /    \   
4       2
Output: [1, 4, 4, 2]
Input:
       6
     /   \
    3     2
     \   / 
      1 2
Output: [6, 3, 1, 2, 2] 
Input:
         8
       / \
      3   10
     / \    \
    1   6   14
       / \   /
      4   7 13
Output: [8, 3, 1, 6, 4, 7, 10, 14, 13]
Constraints:
1 <= number of nodes <= 105
0 <= node->data <= 106
*/

class Solution {
    public:
  void Pre(vector<int>&ans , Node *root)
  {
      if(root == NULL)
      {
          return;
      }
      ans.push_back(root->data);
      Pre(ans,root->left);
      Pre(ans,root->right);
  }
      // Function to return a list containing the preorder traversal of the tree.
      vector<int> preorder(Node* root) {
          // write code here
          vector<int>ans;
          Pre(ans,root);
           return ans;
      }
  };


