/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in 
reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
*/

#include<iostream>
using namespace std;

class ListNode
{
    public:
    int val;
    ListNode* next;

    ListNode(int data)
    {
        val = data;
        next = NULL;
    }
};

class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode *curr1 = l1 , *curr2 = l2;
            int sum = 0 , carry = 0;
    
            ListNode *head = new ListNode(0);
            ListNode *tail = head;
            while(curr1 && curr2)
            {
                sum = curr1->val + curr2->val + carry;
                tail->next = new ListNode(sum%10);
                tail = tail->next;
                curr1 = curr1->next;
                curr2 = curr2->next;
                carry = sum/10;
            }
    
            while(curr1)
            {
                sum = curr1->val + carry;
                tail->next = new ListNode(sum%10);
                tail = tail->next;
                curr1 = curr1->next;
                carry = sum/10;
            }
    
                while(curr2)
            {
                sum = curr2->val + carry;
                tail->next = new ListNode(sum%10);
                tail = tail->next;
                curr2 = curr2->next;
                carry = sum/10;
            }
    
            while(carry)
            {
                tail->next = new ListNode(carry%10);
                tail = tail->next;
                carry/=10;
            }
    
            tail = head;
            head = head->next;
            delete tail;
    
            return head;
            
        }
    };