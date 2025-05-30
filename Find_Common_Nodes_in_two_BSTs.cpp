/*
Given two Binary Search Trees. Find the nodes that are common in both of them, ie- find the intersection of the two BSTs.

Note: Return the common nodes in sorted order.

Examples:

Input:
BST1:
                  5
               /     \
             1        10
           /   \      /
          0     4    7
                      \
                       9
BST2:
                10 
              /    \
             7     20
           /   \ 
          4     9

Output: 4 7 9 10

Input:
BST1:
     10
    /  \
   2   11
  /  \
 1   3
BST2:
       2
     /  \
    1    3
Output: 1 2 3
Constraints:
1 <= Number of Nodes <= 105
1 <= Node data <= 109

Expected Complexities
Time Complexity: O(N1 + N2)
Auxiliary Space: O(H1 + H2)
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
    // Function to find the nodes that are common in both BST.
    vector<int> findCommon(Node *r1, Node *r2) {
        // Your code here
        vector<int>ans;
        stack<Node*>s1,s2;
        
        while(r1)
        {
            s1.push(r1);
            r1=r1->left;
        }
        
        while(r2)
        {
            s2.push(r2);
            r2=r2->left;
        }
        
        while(!s1.empty() && !s2.empty())
        {
            if(s1.top()->data == s2.top()->data)
            {
                ans.push_back(s1.top()->data);
                r1 = s1.top()->right;
                s1.pop();
                r2 = s2.top()->right;
                s2.pop();
            }
            else if(s1.top()->data<s2.top()->data)
            {
                r1 = s1.top()->right;
                s1.pop();
            }
            else
            {
                r2 = s2.top()->right;
                s2.pop();
            }
            
            while(r1)
            {
                s1.push(r1);
                r1=r1->left;
            }
            
            while(r2)
            {
                s2.push(r2);
                r2=r2->left;
            }
        }
        return ans;
    }
};