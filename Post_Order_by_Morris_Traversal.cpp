/*
Given a binary tree. Find the postorder traversal of the tree without using recursion. Return a list containing the postorder traversal of the tree, calculated without using recursion.

Examples :

Input:
           1
         /   \
        2     3
      /  \
     4    5

Output: 4 5 2 3 1
Explanation: Postorder traversal (Left->Right->Root) of the tree is 4 5 2 3 1.
Input:
             8
          /      \
        1          5
         \       /   \
          7     10    6
           \   /
            10 6

Output: 10 7 1 6 10 6 5 8 
Explanation: Postorder traversal (Left->Right->Root) of the tree is 10 7 1 6 10 6 5 8 .
 

 
Constraints:
1 <= Number of nodes <= 105
1 <= Data of a node <= 105

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(1)
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
    vector<int> postOrder(Node* root) {
        // code here
        // postorder :- LRN / NRL
        
        vector<int>ans;   
        while(root)
        {
            if(!root->right) //if right don't exist , push back th element in ans
            {
                ans.push_back(root->data);
                root=root->left;
            }
            
            else
            {
                
                Node *curr = root->right;
                while(curr->left && curr->left!=root)
                {
                    curr=curr->left;
                    // travel to the leftmost node 
                }
                
                // Not traversed 
            // if the leftmost Node is NULL then push abck the element and make 
            // link to the root Node
                
                if(curr->left==NULL)
                {
                    ans.push_back(root->data);
                    curr->left=root;
                    root=root->right;
                }
                
                
                // traversed 
                // if we already traversed then just we need to  reak the link 
                // b/w the node and root 
                
                else
                {
                    curr->left=NULL;
                    root=root->left;
                }
            }
        }
        
        // reverse the array 
        reverse(ans.begin(),ans.end());
        return ans;
    }
};