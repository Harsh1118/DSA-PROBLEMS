/*
Given a binary tree root, return the maximum sum of all keys of any sub-tree which is also a Binary Search Tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:



Input: root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
Output: 20
Explanation: Maximum sum in a valid Binary search tree is obtained in root node with key equal to 3.
Example 2:



Input: root = [4,3,null,1,2]
Output: 2
Explanation: Maximum sum in a valid Binary search tree is obtained in a single root node with key equal to 2.
Example 3:

Input: root = [-4,-2,-5]
Output: 0
Explanation: All values are negatives. Return an empty BST.
 

Constraints:

The number of nodes in the tree is in the range [1, 4 * 104].
-4 * 104 <= Node.val <= 4 * 104
*/
#include<iostream>
#include<climits>
using namespace std;

class TreeNode
{
    public:
    int val;
    TreeNode* left , *right;

    TreeNode(int data)
    {
        val = data;
        left = right = NULL;
    }
};

class Box
 {
    public:
    bool BST;
    int sum;
    int max , min;

    Box()
    {
        BST = 1;
        sum = 0;
        min = INT_MAX;
        max = INT_MIN;
    }
 };

Box* find(TreeNode *root, int &Totalsum)
{
    if(!root)
    {
        return new Box();
    }

    Box* Lefthead = find(root->left,Totalsum);
    Box* Righthead = find(root->right,Totalsum);

    if(Lefthead->BST && Righthead->BST && Lefthead->max < root->val && Righthead->min > root->val)
    {
        Box* head = new Box;
        head->sum = root->val + Lefthead->sum + Righthead->sum;
        head->min = min(root->val,Lefthead->min);
        head->max = max(root->val,Righthead->max);
        Totalsum = max(Totalsum,head->sum);
        return head;
    }

    else 
    {
        Lefthead->BST = 0;
        return Lefthead;
    }
}

class Solution {
public:
    int maxSumBST(TreeNode* root) {
        int Totalsum = 0;
        find(root,Totalsum);
        return Totalsum;
    }
};