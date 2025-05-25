/*
Minimum element in BST
Difficulty: BasicAccuracy: 70.95%Submissions: 213K+Points: 1Average Time: 15m
Given the root of a Binary Search Tree. The task is to find the minimum valued element in this given BST.

Examples

Input: root = [5, 4, 6, 3, N, N, 7, 1]
ex-1
Output: 1
Input: root = [10, 5, 20, 2]
ex-2
Output: 2
Input: root = [10, N, 10, N, 11]
             10
              \
               10
                \
                 11
Output: 10
Constraints:
0 <= number of nodes <= 105
0 <= node->data <= 105

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(1)
*/
#include<iostream>
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
    int minValue(Node* root) {
        // Code here
        if(!root->left)
        {
            return root->data;
        }
        minValue(root->left);
        
    }
};