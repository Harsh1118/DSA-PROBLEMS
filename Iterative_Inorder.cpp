/*
Given a binary tree. Find the inorder traversal of the tree without using recursion.

Example 1

Input:
           1
         /    \
       2       3
      /   \
    4     5
Output: 4 2 5 1 3
Explanation:
Inorder traversal (Left->Root->Right) of 
the tree is 4 2 5 1 3.
Example 2

Input:
            8
          /   \
            1      5
             \    /  \
             7   10   6
             \  /
          10 6
Output: 1 7 10 8 6 10 5 6
Explanation:
Inorder traversal (Left->Root->Right) 
of the tree is 1 7 10 8 6 10 5 6.
 

Your task:
You don't need to read input or print anything. Your task is to complete the function inOrder() which takes the root of the 
tree as input and returns a list containing the inorder traversal of the tree, calculated without using recursion.

Expected time complexity: O(N)
Expected auxiliary space: O(N)


Constraints:
1 <= Number of nodes <= 105
1 <= Data of a node <= 105
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
    Node *left,*right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution {
    public:
      vector<int> inOrder(Node* root) {
          // code here
          vector<int>ans;
          if(!root)
          {
              return ans;
          }
          stack<Node*>s;
          s.push(root);
          stack<bool>visited;
          visited.push(0);
          
          while(!s.empty())
          {
              Node *temp = s.top();
              s.pop();
              int flag = visited.top();
              visited.pop();
              
              if(!flag)
              {
                  if(temp->right)
                  {
                      s.push(temp->right);
                      visited.push(0);
                  }
                  s.push(temp);
                  visited.push(1);
                  if(temp->left)
                  {
                      s.push(temp->left);
                      visited.push(0);
                  }
              }
              
              else
              {
                  ans.push_back(temp->data);
              }
          }
          return ans;
      }
  };