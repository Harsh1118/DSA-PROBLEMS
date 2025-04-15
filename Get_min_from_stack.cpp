/*
Given q queries, You task is to implement the following four functions for a stack:

push(x) – Insert an integer x onto the stack.
pop() – Remove the top element from the stack.
peek() - Return the top element from the stack. If the stack is empty, return -1.
getMin() – Retrieve the minimum element from the stack in O(1) time. If the stack is empty, return -1.
Each query can be one of the following:

1 x : Push x onto the stack.
2 : Pop the top element from the stack.
3: Return the top element from the stack. If the stack is empty, return -1.
4: Return the minimum element from the stack.
Examples:

Input: q = 7, queries = [[1, 2], [1, 3], [3], [2], [4], [1, 1], [4]]
Output: [3, 2, 1]
Explanation: 
push(2): Stack is [2]
push(3): Stack is [2, 3]
peek(): Top element is 3
pop(): Removes 3, stack is [2]
getMin(): Minimum element is 2
push(1): Stack is [2, 1]
getMin(): Minimum element is 1
Input: q = 4, queries = [[1, 4], [1, 2], [4], [3]]
Output: [2, 2]
Explanation: 
push(4): Stack is [4]
push(2): Stack is [4, 2]
getMin(): Minimum element is 2
peek(): Top element is 2
Input: q = 5, queries = [[1, 10], [4], [1, 5], [4], [2]]
Output: [10, 5]
Explanation: 
push(10): Stack is [10]
getMin(): Minimum element is 10
push(5): Stack is [10, 5]
getMin(): Minimum element is 5
pop(): Removes 5, stack is [10]
*/
#include<iostream>
#include<stack>
using namespace std;

class Solution {
    stack<long long >st;
  public:
    // Add an element to the top of Stack
    void push(long long x) {
        // code here
        if(st.empty())
        {
            st.push(x*1000000000 + x);
        }
        else
        {
            st.push(x*1000000000+min(st.top()%1000000000,x));
        }
    }

    // Remove the top element from the Stack
 int  pop() {
        // code here
        if(st.empty())
        {
            return -1 ;
        }
        int element = st.top()/1000000000;
        st.pop();
        return element;
    }

    // Returns top element of the Stack
    int peek() {
        // code here
        if(st.empty())
        {
            return -1;
        }
        int element = st.top()/1000000000;
        return element;
    }

    // Finds minimum element of Stack
    int getMin() {
        // code here
        if(st.empty())
        {
            return -1;
        }
        
        else
        {
            return st.top()%1000000000;
        }
    }
};