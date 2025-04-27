/*
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a 
multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
Example 2:


Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
 

Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000
 

Follow-up: Can you solve the problem in O(1) extra memory space?
*/
#include<iostream>
using namespace std;

class ListNode
{
    public:
    int val;
    ListNode *next;

    ListNode(int data)
    {
        val = data;
        next = NULL;
    }
};

class Solution {
    public:
        ListNode* reverseKGroup(ListNode* head, int k) {
            int size = 1;
            ListNode *temp = head;
            while(temp->next)
            {
                temp=temp->next;
                size++;
            }
            ListNode *first = new ListNode(0);
            first->next = head;
            head = first;
    
            int count = size/k;
    
            while(first->next && count--)
            {
                int x = k;
                ListNode *prev = first;
                ListNode *second = first->next;
                ListNode *curr = first->next;
                ListNode *front = NULL;
    
                while(x&&curr)
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