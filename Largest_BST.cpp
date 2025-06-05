/*
You're given a binary tree. Your task is to find the size of the largest subtree within this binary tree that also satisfies the
 properties of a Binary Search Tree (BST). The size of a subtree is defined as the number of nodes it contains.

Note: A subtree of the binary tree is considered a BST if for every node in that subtree, the left child is less than the node, 
and the right child is greater than the node, without any duplicate values in the subtree.

Examples :

Input: root = [5, 2, 4, 1, 3]
Root-to-leaf-path-sum-equal-to-a-given-number-copy
Output: 3
Explanation:The following sub-tree is a BST of size 3
Balance-a-Binary-Search-Tree-3-copy
Input: root = [6, 7, 3, N, 2, 2, 4]

Output: 3
Explanation: The following sub-tree is a BST of size 3:

Constraints:
1 ≤ number of nodes ≤ 105
1 ≤ node->data ≤ 105

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(h)
*/
#include<iostream>
using namespace std;

class Node 
{
    public:
    int data;
    Node *left , *right;

    Node (int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    class Box
    {
        public:
        bool BST;
        int size;
        int min,max;
        
        Box(int data)
        {
            BST = 1;
            size = 1;
            min = data;
            max = data;
        }
    };
    
    Box *find(Node *root , int &Totalsize)
    {
        // leaf node 
        if(!root->left && !root->right)
        {
            Totalsize = max(Totalsize,1);
            return new Box(root->data);
        }
        
        // only right side
        
        else if(!root->left && root->right)
        {
            Box *head = find(root->right , Totalsize);
            // agar BST hai 
            if(head->BST && head->min>root->data)
            {
                head->size++;
                head->min = root->data;
                Totalsize = max(Totalsize,head->size);
                return head;
            }
            // agar nahi hai toh 
            else
            {
                head->BST = 0;
                return head;
            }
        }
        
        else if(root->left && !root->right)
        {
            Box *head = find(root->left,Totalsize);
            
            if(head->BST && head->max<root->data)
            {
                head->size++;
                head->max = root->data;
                Totalsize = max(Totalsize,head->size);
                return head;
            }
            else
            {
                head->BST = 0;
                return head;
            }
        }
        
        else
        {
            Box *lefthead = find(root->left,Totalsize);
            Box *righthead = find(root->right,Totalsize);
            
            if(lefthead->BST && righthead->BST && lefthead->max<root->data && righthead->min>root->data)
            {
                Box *head = new Box(root->data);
                head->size+=lefthead->size + righthead->size;
                head->min = lefthead->min;
                head->max = righthead->max;
                Totalsize = max(Totalsize,head->size);
                return head;
            }
            
            else
            {
                lefthead->BST = 0;
                return lefthead;
            }
        }
    }
    
    
    
    
    int largestBst(Node *root) {
        // Your code here
        int Totalsize = 0;
        find(root,Totalsize);
        return Totalsize;
    }
};
