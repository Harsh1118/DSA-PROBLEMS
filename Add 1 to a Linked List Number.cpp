/*
You are given a linked list where each element in the list is a node and have an integer data. You need to add 1 to the number formed by concatinating all the list node numbers together and return the head of the modified linked list. 

Note: The head represents the first element of the given array.

Examples :

Input: LinkedList: 4->5->6
Output: 457

Explanation: 4->5->6 represents 456 and when 1 is added it becomes 457. 
Input: LinkedList: 1->2->3
Output: 124
 
Explanation:  1->2->3 represents 123 and when 1 is added it becomes 124. 
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= len(list) <= 105
0 <= list[i] <= 9

*/
#include<iostream>
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
    
    Node *reverse_LL(Node *curr)
    {
        if(curr == NULL)
        {
            return NULL;
        }
        
        if(curr->next == NULL)
        {
            return curr;
        }
        Node *prev = NULL;
        Node *front = NULL;
        
        while(curr)
        {
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        
        return prev;
    }
      Node* addOne(Node* head) {
          // Your Code here
          head = reverse_LL(head);
          Node *temp = head;
          
          int sum = 0 , carry = 1;
          while(temp)
          {
              sum = temp->data + carry;
              temp->data = sum%10;
              temp = temp->next;
              carry = sum/10;
          }
          
          temp = head;
          
          while(temp->next)
          {
              temp=temp->next;
          }
          if(carry)
          temp->next = new Node(carry);
          
          head = reverse_LL(head);
          return head;
          
      }
  };