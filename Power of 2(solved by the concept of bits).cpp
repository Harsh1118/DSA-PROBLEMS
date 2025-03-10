/*
Given a non-negative integer n. The task is to check if it is a power of 2. 

Examples

Input: n = 8
Output: true
Explanation: 8 is equal to 2 raised to 3 (23 = 8).
Input: n = 98
Output: false
Explanation: 98 cannot be obtained by any power of 2.
Input: n = 1
Output: true
Explanation: (20 = 1).
*/

#include<iostream>
using namespace std;

class Solution {
    public:
      // Function to check if given number n is a power of two.
      bool isPowerofTwo(long long n) {
          // code here
          if(n>0 && (n & (n-1)) == 0)
          {
              return true;
          }
          return false;
      }
  };