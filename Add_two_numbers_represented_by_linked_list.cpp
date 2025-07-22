/*
Given the head of two singly linked lists num1 and num2 representing two non-negative integers. 

The task is to return the head of the linked list representing the sum of these two numbers.

For example, num1 represented by the linked list : 1 -> 9 -> 0, similarly num2 represented by the 
linked list: 2 -> 5. Sum of these two numbers is represented by 2 -> 1 -> 5.

Note: There can be leading zeros in the input lists, but there should not be any leading zeros in the output list.

Examples:

Input: num1 = 4 - > 5, num2 = 3 -> 4 -> 5
Output:  3 -> 9 -> 0
 
Explanation: Given numbers are 45 and 345. There sum is 390.
Input: num1 = 0 -> 0 -> 6 -> 3, num2 = 0 -> 7 
Output: 7 -> 0 
 
Explanation: Given numbers are 63 and 7. There sum is 70.
Constraints:
1 <= size of both linked lists <= 106
0 <= elements of both linked lists <= 9
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
    
    Node *reverse_LL(Node *curr)
    {
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
    
    Node *makeequal(Node *head , int count)
    {
        while(count--)
        {
            Node *temp = new Node (0);
            temp->next = head;
           head = temp;
            
        }
        
        return head;
        
    }
    
    
    
      Node* addTwoLists(Node* num1, Node* num2) {
          // code here
          
          int len1 = 0 , len2 = 0;
          Node *curr1 = num1 , *curr2 = num2;
          
          while(curr1)
          {
              len1++;
              curr1=curr1->next;
          }
          
          while(curr2)
          {
              len2++;
              curr2=curr2->next;
          }
          
          if(len1>len2)
          {
              num2 = makeequal(num2,len1-len2);
          }
          else if(len2>len1)
          {
              num1 = makeequal(num1,len2-len1);
          }
          
          num1 = reverse_LL(num1);
          num2 = reverse_LL(num2);
          
          curr1 = num1 , curr2 = num2;
          Node *head = new Node(0);
          Node *temp = head;
          
          int carry = 0;
          
          while(curr1 || curr2 || carry)
          {
              int sum = carry;
              if(curr1)
              {
                  sum+=curr1->data;
                  curr1=curr1->next;
              }
              
              if(curr2)
              {
                  sum+=curr2->data;
                  curr2=curr2->next;
              }
              
              temp->next = new Node(sum%10);
              temp = temp->next;
              carry = sum/10;
          }
          
          Node *result = reverse_LL(head->next);
          delete head;
          
          Node *temp1 = result;
          Node *front = NULL;
          while(temp1 && temp1->data == 0)
          {
              front = temp1->next;
              delete temp1;
              temp1 = front;
              
              
          }
          
          result = temp1;
          
          return result ? result : new Node(0);
          
      }
  };
