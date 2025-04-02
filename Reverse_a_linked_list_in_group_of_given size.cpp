/*
Given the head a linked list, the task is to reverse every k node in the linked list. 
If the number of nodes is not a multiple of k then the left-out nodes in the end, should be
 considered as a group and must be reversed.

Examples:

Input: head = 1 -> 2 -> 2 -> 4 -> 5 -> 6 -> 7 -> 8, k = 4
Output: 4 -> 2 -> 2 -> 1 -> 8 -> 7 -> 6 -> 5

Explanation: The first 4 elements 1, 2, 2, 4 are reversed first and then the next 4 elements 5, 6, 7, 8. 
Hence, the resultant linked list is 4 -> 2 -> 2 -> 1 -> 8 -> 7 -> 6 -> 5.
Input: head = 1 -> 2 -> 3 -> 4 -> 5, k = 3
Output: 3 -> 2 -> 1 -> 5 -> 4

Explanation: The first 3 elements 1, 2, 3 are reversed first and then left out elements 4, 5 are reversed.
 Hence, the resultant linked list is 3 -> 2 -> 1 -> 5 -> 4.
Constraints:
1 <= size of linked list <= 105
1 <= data of nodes <= 106
1 <= k <= size of linked list 
*/

#include<iostream>
using namespace std;

class Node
{
    public:
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
      Node *reverseKGroup(Node *head, int k) {
          // code here
          Node *first = new Node(0);
          first->next = head;
          head = first;
          
          while(first->next)
          {
              int x = k;
              Node *second = first->next;
              Node *prev = first;
              Node *curr = first->next;
              Node *front = NULL;
              while(x && curr)
              {
                  front = curr->next;
                  curr->next = prev;
                  prev = curr;
                  curr = front;
                  x--;
              }
              first->next = prev;
              second->next = curr;
              first = second;
          }
          first = head;
          head = head->next;
          delete first;
          return head;
      }
  };