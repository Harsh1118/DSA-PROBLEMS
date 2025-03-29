/*
Given the head of two sorted linked lists consisting of nodes respectively. The task is to merge both lists and 
return the head of the sorted merged list.

Examples:

Input: head1 = 5 -> 10 -> 15 -> 40, head2 = 2 -> 3 -> 20
Output: 2 -> 3 -> 5 -> 10 -> 15 -> 20 -> 40
Explanation:

Input: head1 = 1 -> 1, head2 = 2 -> 4
Output: 1 -> 1 -> 2 -> 4
Explanation:

Constraints:
1 <= no. of nodes<= 103
0 <= node->data <= 105
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
      Node* sortedMerge(Node* head1, Node* head2) {
          // code here
          Node *head = new Node(0);
          Node *tail = head;
          while(head1 && head2)
          {
              if(head1->data <= head2->data)
              {
                  tail->next=head1;
                  head1 = head1->next;
                  tail = tail->next;
                  tail->next = NULL;
                  
              }
              
              else 
              {
                  tail->next = head2;
                  head2 = head2->next;
                  tail=tail->next;
                  tail->next = NULL;
              }
          }
          
          if(head1)
          {
              tail->next = head1;
          }
          
          else
          {
              tail->next = head2;
          }
          tail = head;
          head=head->next;
          delete tail;
          
          return head;
          
      }
  };