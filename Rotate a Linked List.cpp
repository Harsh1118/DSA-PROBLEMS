/*
Given the head of a singly linked list, your task is to left rotate the linked list k times.

Examples:

Input: head = 10 -> 20 -> 30 -> 40 -> 50, k = 4
Output: 50 -> 10 -> 20 -> 30 -> 40
Explanation:
Rotate 1: 20 -> 30 -> 40 -> 50 -> 10
Rotate 2: 30 -> 40 -> 50 -> 10 -> 20
Rotate 3: 40 -> 50 -> 10 -> 20 -> 30
Rotate 4: 50 -> 10 -> 20 -> 30 -> 40

Input: head = 10 -> 20 -> 30 -> 40 , k = 6
Output: 30 -> 40 -> 10 -> 20 
 
Constraints:

1 <= number of nodes <= 105
0 <= k <= 109
0 <= data of node <= 109
*/
#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;

    Node (int val)
    {
        data = val;
        next = NULL;
    }
};

class Solution {
    public:
      Node* rotate(Node* head, int k) {
          // Your code here
          if(head == NULL || head->next == NULL)
          {
              return head;
          }
          int count = 0;
          Node *temp = head;
          
          while(temp)
          {
              count++;
              temp = temp->next;
          }
          
         k%=count;
          if(k==0)
          {
              return head;
          }
          
          Node *curr = head;
          Node *front = NULL;
          temp = head;
          
          while(temp->next)
          {
              temp = temp->next;
          }
          
          while(k--)
          {
              front = curr->next;
              curr->next = NULL;
              temp->next = curr;
              temp = temp->next;
              curr = front;
          }
          return front;
      }
  };