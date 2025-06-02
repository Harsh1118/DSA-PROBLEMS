/*
Given a linked list. Print all the elements of the linked list separated by space followed.

Examples:

Input: LinkedList : 1 -> 2

Output: 1 2
Explanation: The linked list contains two elements 1 and 2.The elements are printed in a single line.
Input: Linked List : 49 -> 10 -> 30
 
Output: 49 10 30
Explanation: The linked list contains 3 elements 49, 10 and 30. The elements are printed in a single line.
Constraints :
1 <= numbers of nodes <= 105
1 <= node values <= 106
Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(1)
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
    // Function to display the elements of a linked list in same line
    void printList(Node *head) {
        // your code goes here
        if(!head)
        {
            return;
        }
        Node *curr = head;
        while(curr)
        {
            cout<<curr->data<<" ";
            curr=curr->next;
        }
    }
};