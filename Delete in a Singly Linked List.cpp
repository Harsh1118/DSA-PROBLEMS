/*
Given a singly linked list and an integer, x. Delete the xth node (1-based indexing) from the singly linked list.

Examples:

Input: Linked list: 1 -> 3 -> 4, x = 3
Output: 1 -> 3

Explanation: After deleting the node at the 3rd position (1-base indexing), the linked list is as 1 -> 3. 
Input: Linked list: 1 -> 5 -> 2 -> 9, x = 2 
Output: 1 -> 2 -> 9
Explanation: After deleting the node at 2nd position (1-based indexing), the linked list is as 1 -> 2 -> 9.
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
      /* Function to delete a node from a linked list */
      Node* deleteNode(Node* Head, int x) {
          // code here
          if(Head!=NULL)
          {
          if(x==1)
          {
              Node *temp = Head;
              Head = temp->next;
              delete temp;
              return Head;
          }
          
          else 
          {
              Node *temp = Head;
              Node *prev = NULL;
              x--;
              while(x--)
              {
                  prev = temp;
                  temp=temp->next;
              }
              prev->next = temp->next;
              delete temp;
              return Head;
          }
      }
      }
  };