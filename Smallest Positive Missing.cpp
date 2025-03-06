/*You are given an integer array arr[]. Your task is to find the smallest positive number missing from the array.

Note: Positive number starts from 1. The array can have negative integers too.

Examples:

Input: arr[] = [2, -3, 4, 1, 1, 7]
Output: 3
Explanation: Smallest positive missing number is 3.
Input: arr[] = [5, 3, 2, 5, 1]
Output: 4
Explanation: Smallest positive missing number is 4.
Input: arr[] = [-8, 0, -1, -4, -3]
Output: 1
Explanation: Smallest positive missing number is 1.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
      // Function to find the smallest positive number missing from the array.
      int missingNumber(vector<int> &arr) {
          // Your code here
          sort(arr.begin(),arr.end());
          int count = 1;
          for(int i = 0; i<arr.size(); i++)
          {
              if(arr[i]<0)
              {
                  continue;
              }
              else
              {
                  if(arr[i]==count)
                  {
                      count+=1;
                  }
              }
          }
          return count;
          
      }
  };