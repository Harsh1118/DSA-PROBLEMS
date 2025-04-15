/*
Given an array of integers arr[], the task is to find the maximum of the minimum values for every 
possible window size in the array, where the window size ranges from 1 to arr.size().

More formally, for each window size k, determine the smallest element in all windows of size k, 
and then find the largest value among these minimums where 1<=k<=arr.size().

Examples :

Input: arr[] = [10, 20, 30, 50, 10, 70, 30]
Output: [70, 30, 20, 10, 10, 10, 10] 
Explanation: 
1. First element in output indicates maximum of minimums of all windows of size 1. Minimums of windows of 
size 1 are [10], [20], [30], [50], [10], [70] and [30]. Maximum of these minimums is 70. 
2. Second element in output indicates maximum of minimums of all windows of size 2. Minimums of 
windows of size 2 are [10], [20], [30], [10], [10], and [30]. Maximum of these minimums is 30. 
3. Third element in output indicates maximum of minimums of all windows of size 3. Minimums of
 windows of size 3 are [10], [20], [10], [10] and [10]. Maximum of these minimums is 20. 
Similarly other elements of output are computed.
Input: arr[] = [10, 20, 30]
Output: [30, 20, 10]
Explanation: First element in output indicates maximum of minimums of all windows of size 1. 
Minimums of windows of size 1 are [10] , [20] , [30]. Maximum of these minimums are 30 and 
similarly other outputs can be computed
Constraints:
1 <= arr.size() <= 105
1 <= arr[i] <= 106


*/
#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
      vector<int> maxOfMins(vector<int>& arr) {
          // Your code here
          int n = arr.size();
          stack<int>st;
          vector<int>ans(n,0);
          
          for(int i=0; i<n; i++)
          {
              while(!st.empty()&&arr[st.top()]>arr[i])
              {
                  int index = st.top();
                  st.pop();
                  if(st.empty())
                  {
                      int range = i;
                      ans[range-1]=max(ans[range-1],arr[index]);
                  }
                  else
                  {
                      int range = i-st.top()-1;
                      ans[range-1]=max(ans[range-1],arr[index]);
                  }
              }
              st.push(i);
          }
          
          while(!st.empty())
          {
              int index = st.top();
              st.pop();
              if(st.empty())
              {
                  int range = n;
                  ans[range-1]= max(ans[range-1],arr[index]);
              }
              
              else
              {
                  int range = n-st.top()-1;
                  ans[range-1]=max(ans[range-1],arr[index]);
              }
          }
          
          for(int i = n-2; i>=0; i--)
          {
              ans[i]=max(ans[i],ans[i+1]);
          }
          return ans;
      }
  };

