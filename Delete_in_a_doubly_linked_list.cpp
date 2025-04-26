/*
Given a Doubly Linked list and a position. The task is to delete a node from a given position 
(position starts from 1) in a doubly linked list and return the head of the doubly Linked list.

Examples:

Input: LinkedList = 1 <--> 3 <--> 4, x = 3
Output: 1 <--> 3
Explanation: After deleting the node at position 3 (position starts from 1),the linked list will be now as 1 <--> 3.
 
Input: LinkedList = 1 <--> 5 <--> 2 <--> 9, x = 1
Output: 5 <--> 2 <--> 9
Explanation:

Constraints:
2 <= size of the linked list <= 106
1 <= x <= size of the linked list 
1 <= node->data <= 104

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(1)
*/
#include<iostream>
class Node
{
    public:
    int data;
    Node *next,*prev;

    Node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class Solution {
    public:
      // Function to delete a node at given position.
      Node* deleteNode(Node* head, int x) {
          // Your code here
          if(x==1)
          {
              if(head!=NULL)
              {
                  if(head->next == NULL)
                  {
                      delete head;
                      head = NULL;
                  }
                  
                  else
                  {
                      Node *temp = head;
                      head = temp->next;
                      head->prev = NULL;
                      delete temp;
                  }
              }
          }
          
          else
          {
              Node *curr = head;
              while(--x)
              {
                  curr=curr->next;
              }
              
              if(curr->next == NULL)
              {
                  curr->prev->next = NULL;
                  delete curr;
              }
              
              else
              {
                  curr->prev->next = curr->next;
                  curr->next->prev = curr->prev;
                  delete curr;
              }
          }
          
          return head;
      }
  };