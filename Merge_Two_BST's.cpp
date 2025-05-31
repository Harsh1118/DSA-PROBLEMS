/*
Given two BSTs, return elements of merged BSTs in sorted form.

Examples :

Input: root1 = [5, 3, 6, 2, 4]
       5
     /   \
    3     6
   / \
  2   4 
root2 = [2, 1, 3, N, N, N, 7, 6, N]
        2
      /   \
     1     3
            \
             7
            /
           6
Output: [1, 2, 2, 3, 3, 4, 5, 6, 6, 7]
Explanation: After merging and sorting the two BST we get [1, 2, 2, 3, 3, 4, 5, 6, 6, 7].
Input: root1 = [12, 9, N, 6, 11]
       12
     /   
    9
   / \    
  6   11
root2 = [8, 5, 10, 2]
      8
    /  \
   5    10
  /
 2
Output: [2, 5, 6, 8, 9, 10, 11, 12]
Explanation: After merging and sorting the two BST we get [2, 5, 6, 8, 9, 10, 11, 12].
Constraints:
1 ≤ number of nodes, root->data ≤ 105

Expected Complexities
Time Complexity: O((m+n)*log(m+n))
Auxiliary Space: O(Height of BST1 + Height of BST2 + m + n)

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
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    
    void Inorder(Node *root , vector<int>&arr)
    {
        if(!root)
        {
            return;
        }
        
        Inorder(root->left,arr);
        arr.push_back(root->data);
        Inorder(root->right,arr);
    }
    vector<int> merge(Node *root1, Node *root2) {
        // Your code here
        vector<int>ans1;
        vector<int>ans2;
        vector<int>ans;
        Inorder(root1,ans1);
        Inorder(root2,ans2);
        int i = 0 , j = 0;
        
        while(i<ans1.size() && j<ans2.size())
        {
            if(ans1[i]<ans2[j])
            {
                ans.push_back(ans1[i++]);
            }
            else
            {
                ans.push_back(ans2[j++]);
            }
        }
        
        while(i<ans1.size())
        {
            ans.push_back(ans1[i++]);
        }
        
        while(j<ans2.size())
        {
            ans.push_back(ans2[j++]);
        }
        
        return ans;
    }
};