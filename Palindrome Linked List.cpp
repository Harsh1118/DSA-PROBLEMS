/*
Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
*/

#include<iostream>
using namespace std;

class ListNode
{
    public :
    int val;
    ListNode *next;

    ListNode (int value)
    {
        val = value;
        next = NULL;
    }
};

class Solution {
    public:
        bool isPalindrome(ListNode* head) {
            if(head->next==NULL)
            {
                return 1;
            }
            int count = 0;
            ListNode *temp = head;
            while(temp)
            {
                count++;
                temp=temp->next;
            }
            count/=2;
            ListNode *curr = head, *prev = NULL;
    
            while(count--)
            {
                prev = curr;
                curr = curr->next;
            }
            prev->next = NULL;
            ListNode *front;
            prev = NULL;
    
            while(curr)
            {
                front = curr->next;
                curr->next = prev;
                prev = curr;
                curr=front;
            }
    
            ListNode *head1 = head;
            ListNode *head2 = prev;
    
            while(head1)
            {
                if(head1->val != head2->val)
                {
                    return 0;
                }
                head1 = head1->next;
                head2 = head2->next;
            }
            return 1;
        }
    };