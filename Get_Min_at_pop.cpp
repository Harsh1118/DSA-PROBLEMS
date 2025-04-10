/*
You are given an integer array A[]. You need to first push the elements of the array into a stack and 
then print minimum in the stack at each pop until stack becomes empty.

Examples:

Input: A[] = [1 2 3 4 5]
Output: 1 1 1 1 1
Explanation: 
After pushing elements to the stack, 
the stack will be "top -> 5, 4, 3, 2, 1". 
Now, start popping elements from the stack
popping 5: min in the stack is 1.popped 5
popping 4: min in the stack is 1. popped 4
popping 3: min in the stack is 1. popped 3
popping 2: min in the stack is 1. popped 2
popping 1: min in the stack is 1. popped 1
Input: A[] = [1 6 43 1 2 0 5]
Output: 0 0 1 1 1 1 1
Explanation: 
After pushing the elements to the stack, 
the stack will be 5->0->2->1->43->6->1. 
Now, poping the elements from the stack:
popping 5: min in the stack is 0. popped 5
popping 0: min in the stack is 0. popped 0
popping 2: min in the stack is 1. popped 2
popping 1: min in the stack is 1. popped 1
popping 43: min in the stack is 1. popped 43
popping 6: min in the stack is 1. popped 6
popping 1: min in the stack is 1. popped 1.
Constraints:
0 <= Ai <= 107
*/

#include<iostream>
#include<stack>
using namespace std;

stack<int> _push(int arr[],int n)
{
   // your code here
   stack<int>st;
   for(int i = 0; i<n; i++)
   {
       if(i==0)
       {
           st.push(arr[i]);
       }
       else
       {
           st.push(min(arr[i],st.top()));
       }
   }
   return st;
}

//Function to print minimum value in stack each time while popping.
void _getMinAtPop(stack<int>s)
{
    // your code here
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}