/*
Given a linked list where nodes can contain values 0s, 1s, and 2s only. 
The task is to segregate 0s, 1s, and 2s linked list such that all zeros segregate to the head side, 
2s at the end of the linked list, and 1s in the middle of 0s and 2s.

Examples:

Input: LinkedList: 1->2->2->1->2->0->2->2
Output: 0->1->1->2->2->2->2->2
Explanation: All the 0s are segregated to the left end of the linked list, 2s to the right end of the list,
 and 1s in between.
 
Input: LinkedList: 2->2->0->1
Output: 0->1->2->2
Explanation: After arranging all the 0s,1s and 2s in the given format, the output will be 0 1 2 2.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(n).

Constraints:
1 <= no. of nodes <= 106
0 <= node->data <= 2
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
      // Function to sort a linked list of 0s, 1s and 2s.
      Node* segregate(Node* head) {
  
          // Add code here
          
          if(head==NULL || head->next ==  NULL)
          {
              return head;
          }
          Node *head0 = NULL , *tail0 = NULL;
          Node *head1 = NULL , *tail1 = NULL;
          Node *head2 = NULL , *tail2 = NULL;
          
          Node *curr = head;
          
          
          while(curr)
          {
              if(curr->data == 0)
              {
                  if(head0==NULL)
                  {
                      head0 = curr;
                      tail0 = head0;
                  }
                  
                  else
                  {
                      tail0->next = curr;
                      tail0=tail0->next;
                  }
              }
              
              else if(curr->data == 1)
              {
                  if(head1==NULL)
                  {
                      head1 = curr;
                      tail1 = head1;
                  }
                  
                  else
                  {
                      tail1->next = curr;
                      tail1=tail1->next;
                  }
              }
              
              else
              {
                  if(head2==NULL)
                  {
                      head2 = curr;
                      tail2 = head2;
                  }
                  
                  else
                  {
                      tail2->next = curr;
                      tail2=tail2->next;
                  }
              }
              
              curr = curr->next;
          }
          if(tail0&&tail1&&tail2)
          {
          tail0->next = head1;
          tail1->next = head2;
          tail2->next = NULL;
          }
          else if(tail0&&tail1)
          {
          tail0->next = head1;
          tail1->next = NULL;
          }
          else if(tail1&&tail2)
          {
          tail1->next = head2;
          tail2->next = NULL;
          }
          else if(tail0 && tail2)
          {
              tail0->next = head2;
              tail2->next = NULL;
          }
          
          
          if(head0)
          {
              return head0;
          }
          
          else if(head1)
          {
              return head1;
          }
          else
          {
              return head2;
          }
      }
  };