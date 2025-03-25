/*
Given a singly linked list, your task is to remove every kth node from the linked list. 

Examples:

Input: Linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8, k = 2
Output: 1 -> 3 -> 5 -> 7

Explanation: After removing every 2nd node of the linked list, the resultant linked list will be: 1 -> 3 -> 5 -> 7.
Input: Linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10, k = 3
Output: 1 -> 2 -> 4 -> 5 -> 7 -> 8 -> 10

Explanation: After removing every 3rd node of the linked list, the resultant linked list 
will be: 1 -> 2 -> 4 -> 5 -> 7 -> 8 -> 10.

Expected Time Complexity:  O(n)
Expected Auxiliary Space:  O(1)

Constraints:
1 <= size of linked list <= 106
1 <= node->data <= 106
1 <= k <= size of linked list
*/

#include<iostream>
using namespace std;

class Node
{
    public :
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class Solution {
    public:
      Node* deleteK(Node* head, int k) {
          // code here
          if(k==1)
          return NULL;
          
          Node *curr = head , *prev = NULL;
          int count = 1;
          while(curr)
          {
              if(k==count)
              {
                  prev->next=curr->next;
                  delete curr;
                  curr = prev->next;
                  count = 1;
              }
              
              else
              {
                  prev = curr;
                  curr=curr->next;
                  count++;
              }
          }
          return head;
      }
  };