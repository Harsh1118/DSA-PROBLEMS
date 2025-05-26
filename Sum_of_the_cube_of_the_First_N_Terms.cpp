/*
Given an integer n, calculate the sum of series 13 + 23 + 33 + 43 + … till n-th term.

Examples:

Input: n = 5
Output: 225
Explanation: 13 + 23 + 33 + 43 + 53 = 225
Input: n = 7
Output: 784
Explanation: 13 + 23 + 33 + 43 + 53 + 63 + 73 = 784
Constraints:
1 <= n <= 200 

Expected Complexities
Time Complexity: O(1)
Auxiliary Space: O(1)
*/
#include<iostream>
#include<cmath>
using namespace std;
class Solution {
  public:
    int sumOfSeries(int n) {
        // code here
        int sum = 0;
        for(int i = 1;i<=n; i++)
        {
            sum+=pow(i,3);
        }
        return sum;
    }
};