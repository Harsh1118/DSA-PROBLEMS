/*
Given an array arr[] of n sorted linked lists of different sizes. The task is to merge them in such a way that 
after merging they will be a single sorted linked list, then return the head of the merged linked list.

Examples:

Input: arr[] = [1 -> 2 -> 3, 4 -> 5, 5 -> 6, 7 -> 8]
Output: 1 -> 2 -> 3 -> 4 -> 5 -> 5 -> 6 -> 7 -> 8
Explanation:
The arr[] has 4 sorted linked list of size 3, 2, 2, 2.
1st list: 1 -> 2-> 3
2nd list: 4 -> 5
3rd list: 5 -> 6
4th list: 7 -> 8
The merged list will be:
 
Input: arr[] = [1 -> 3, 8, 4 -> 5 -> 6]
Output: 1 -> 3 -> 4 -> 5 -> 6 -> 8
Explanation:
The arr[] has 3 sorted linked list of size 2, 3, 1.
1st list: 1 -> 3
2nd list: 8
3rd list: 4 -> 5 -> 6
The merged list will be:

Constraints
1 <= total no. of nodes <= 105
1 <= node->data <= 103

Expected Complexities
Time Complexity: O(n log n)
Auxiliary Space: O(n)
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Solution {
  public:
  class Compare
  {
      public:
      bool operator ()(Node*a,Node*b)
      {
          return a->data>b->data;
      }
  };
      Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        priority_queue<Node*,vector<Node*>,Compare>p(arr.begin(),arr.end());
          
          Node *root = new Node(0);
          Node *tail = root;
          
          Node *temp;
          
          while(!p.empty())
          {
              temp = p.top();
              p.pop();
              tail->next = temp;
              tail = tail->next;
              if(temp->next)
              {
                  p.push(temp->next);
              }
          }
          return root->next;
      }
};