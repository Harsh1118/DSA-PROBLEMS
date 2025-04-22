/*
Given a queue q containing integer elements, your task is to reverse the queue.

Examples:

Input: q[] = [4 3 1 10 2 6]
Output: [6, 2, 10, 1, 3, 4]
Explanation: After reversing the given elements of the queue, the resultant queue will be 6 2 10 1 3 4.
Input: q[] = [4 3 2 1]
Output: [1, 2, 3, 4]
Explanation: After reversing the given elements of the queue, the resultant queue will be 1 2 3 4.
Input: q[] = [7, 9, 5, 12, 8]
Output: [8, 12, 5, 9, 7]
Explanation: After reversing the given elements of the queue, the resultant queue will be 8, 12, 5, 9, 7.
Constraints:
1 ≤ q.size() ≤ 106
1 ≤ q[i] ≤ 105
*/
#include<iostream>
#include<stack>
#include<queue>
using namespace std;

class Solution {
    public:
      queue<int> reverseQueue(queue<int> &q) {
          // code here.
          stack<int>st;
          
          while(!q.empty())
          {
              st.push(q.front());
              q.pop();
          }
          
          while(!st.empty())
          {
              q.push(st.top());
              st.pop();
          }
          return q;
          
      }
  };