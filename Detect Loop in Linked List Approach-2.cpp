/*
You are given the head of a singly linked list. Your task is to determine if the linked list contains a loop.
 A loop exists in a linked list if the next pointer of the last node points to any other node in the list 
 (including itself), rather than being null.

Custom Input format:
A head of a singly linked list and a pos (1-based index) which denotes the position of the node to 
which the last node points to. If pos = 0, it means the last node points to null, indicating there is no loop.

Examples:

Input: head: 1 -> 3 -> 4, pos = 2
Output: true
Explanation: There exists a loop as last node is connected back to the second node.

Input: head: 1 -> 8 -> 3 -> 4, pos = 0
Output: false
Explanation: There exists no loop in given linked list.

Input: head: 1 -> 2 -> 3 -> 4, pos = 1
Output: true
Explanation: There exists a loop as last node is connected back to the first node.


Constraints:
1 ≤ number of nodes ≤ 104
1 ≤ node->data ≤ 103       
0 ≤ pos ≤ Number of nodes in Linked List
*/

#include<iostream>
#include<unordered_map>
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
      // Function to check if the linked list has a loop.
      bool detectLoop(Node* head) {
          // your code here
          unordered_map<Node*,bool>visited;
          
          Node *curr = head;
          while(curr)
          {
              if(visited[curr]==1)
              {
                  return 1;
              }
              visited[curr]=1;
              curr = curr->next;
          }
          return 0;
      }
  };
  