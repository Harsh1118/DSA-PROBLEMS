/*
Given an positive integer n, print numbers from 1 to n without using loops.

Implement the function printTillN() to print the numbers from 1 to n as space-separated integers.

Examples

Input: n = 5
Output: 1 2 3 4 5
Explanation: We have to print numbers from 1 to 5.
Input: n = 10
Output: 1 2 3 4 5 6 7 8 9 10
Explanation: We have to print numbers from 1 to 10.
Constraints:
1 ≤ n ≤ 1000

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(n)
*/
#include<iostream>
using namespace std;
class Solution {
  public:
  void print(int num)
  {
      if(num==0)
      {
          return;
      }
      print(num-1);
      cout<<num<<" ";
  }
    void printTillN(int n) {
        // Write Your Code here
        print(n);
    }
};