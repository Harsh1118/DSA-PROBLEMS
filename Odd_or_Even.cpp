/*
Given a positive integer n, determine whether it is odd or even. Return true if the number is even and false if the number is odd.

Examples:

Input: n = 15
Output: false
Explanation: The number is not divisible by 2, Odd number.
Input: n = 44
Output: true
Explanation: The number is divisible by 2, Even number.
Constraints:
1 ≤ n ≤ 104

Expected Complexities
Time Complexity: O(1)
Auxiliary Space: O(1)
*/
#include<iostream>
using namespace std;

class Solution {
  public:
    bool isEven(int n) {
        // code here
        if(n%2==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};