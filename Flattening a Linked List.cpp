/*
Given a linked list containing n head nodes where every node in the linked list contains two pointers:
(i) next points to the next node in the list.
(ii) bottom pointer to a sub-linked list where the current node is the head.
Each of the sub-linked lists nodes and the head nodes are sorted in ascending order based on their data.
Your task is to flatten the linked list such that all the nodes appear in a single level while maintaining 
the sorted order.

Note:
1. ↓ represents the bottom pointer and -> represents the next pointer.
2. The flattened list will be printed using the bottom pointer instead of the next pointer.

Examples:

Input:

Output: 5-> 7-> 8-> 10 -> 19-> 20-> 22-> 28-> 30-> 35-> 40-> 45-> 50.
Explanation: 
Bottom pointer of 5 is pointing to 7.
Bottom pointer of 7 is pointing to 8.
Bottom pointer of 8 is pointing to 10 and so on.
Input:
 
Output: 5-> 7-> 8-> 10-> 19-> 22-> 28-> 30-> 50
Explanation:
Bottom pointer of 5 is pointing to 7.
Bottom pointer of 7 is pointing to 8.
Bottom pointer of 8 is pointing to 10 and so on.
Constraints:
0 <= n <= 100
1 <= number of nodes in sub-linked list(mi) <= 50
1 <= node->data <= 104
*/

#include<iostream>
using namespace std;

class Node
{
    public :
    int data;
    Node *next;
    Node *bottom;

    Node(int value)
    {
        data = value;
        next = NULL;
        bottom = NULL;
    }
};

class Solution {
    public:
    
    Node *merge(Node *head1 , Node *head2)
    {
        Node *head = new Node(0);
        Node *tail = head;
        
        while(head1 && head2)
        {
            if(head1->data<=head2->data)
            {
                tail->bottom = head1;
                head1 = head1->bottom;
                tail = tail->bottom;
                tail->bottom = NULL;
                
            }
            
            else
            {
                tail->bottom = head2;
                head2 = head2->bottom;
                tail = tail->bottom;
                tail->bottom = NULL;
            }
        }
        
        if(head1)
        {
            tail->bottom = head1;
        }
        
        else
        {
            tail->bottom = head2;
        }
        return head->bottom;
    }
    
      // Function which returns the  root of the flattened linked list.
      Node *flatten(Node *root) {
          // Your code here
          Node *head1 , *head2 , *head3;
          
          while(root->next)
          {
              head1 = root;
              head2 = root->next;
              head3 = root->next->next;
              head1->next = NULL;
              head2->next = NULL;
              root = merge(head1,head2);
              root->next = head3;
          }
          
          return root;
      }
  };