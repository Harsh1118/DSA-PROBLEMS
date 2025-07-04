/*
You are given two numbers a and b. Your task is to swap the given two numbers.

Note: Try to do it without a temporary variable.

Examples:

Input: a = 13, b = 9
Output: 9 13
Explanation: After swapping it becomes 9 and 13.
Input: a = 15, b = 8
Output: 8 15
Explanation: after swapping it becomes 8 and 15.
Constraints:
1 ≤ a, b ≤ 106

Expected Complexities
Time Complexity: O(1)
Auxiliary Space: O(1)
*/
#include<iostream>
using namespace std;

class Solution {
  public:
    pair<int, int> get(int a, int b) {
        // complete the function here
        a = a + b;
        b = a - b;
        a = a - b;
        return {a , b};
    }
};