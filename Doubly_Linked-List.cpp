/*
Geek is learning data structures and is familiar with linked lists, 
but he's curious about how to access the previous element in a linked list in the 
same way that we access the next element. His teacher explains doubly linked lists to him.

Given an integer array arr of size n. Construct the doubly linked list from arr and 
return the head of it.

Example 1:

Input:
n = 5
arr = [1,2,3,4,5]
Output:
1 2 3 4 5
Explanation: Linked list for the given array will be 1<->2<->3<->4<->5.
Example 2:

Input:
n = 1
arr = [1]
Output:
1
Explanation: Linked list for the given array will be 1.
Constraints:
1 <= n <= 105
1 <= arr[i] <= 100

Your Task:
You don't need to read input or print anything. Your task is to complete the 
function constructDLL() which takes arr[] as input parameters and returns the head of the
 Linked List.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Node 
{
    public :
    int data;
    Node *prev;
    Node *next;

    Node(int value)
    {
        data = value;
        prev = NULL;
        next = NULL;
    }
};

class Solution {
    public:
    
    Node *CreateDoublyLinkedlist(vector<int>&arr,int index,Node *back)
    {
        if(index == arr.size())
        {
            return NULL;
        }
        Node *temp = new Node(arr[index]);
        temp->prev = back;
        temp->next = CreateDoublyLinkedlist(arr,index+1,temp);
        return temp;
    }
      Node* constructDLL(vector<int>& arr) {
          // code here
          Node *Head = CreateDoublyLinkedlist(arr,0,NULL);
          return Head;
      }
  };
  

