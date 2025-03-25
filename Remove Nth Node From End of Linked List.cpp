/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
*/

#include<iostream>
using namespace std;

class ListNode
{
    public:
    int val;
    ListNode* next;

    ListNode(int value)
    {
        val = value;
        next = NULL;
    }
};

class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
    
            int count = 0;
            ListNode *temp = head;
    
            while(temp!=NULL)
            {
                count++;
                temp = temp->next;
            }
            if(count==1)
            {
                return NULL;
            }
            if(count<n)
            {
            n%=count;
            }
            count-=n;
            if(count==0)
            {
                temp = head;
                head = head->next;
                delete temp;
                return head;
            }
    
            ListNode *curr = head , *prev = NULL;
            while(count--)
            {
                prev = curr;
                curr = curr->next;
            }
            prev->next=curr->next;
            delete curr;
    
            return head;
        }
    };