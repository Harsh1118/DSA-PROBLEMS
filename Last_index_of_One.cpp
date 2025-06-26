/*
Given a string s consisting of only '0's and '1's,  find the last index of the '1' present.

Note: If '1' is not present, return "-1"

Examples:

Input: s = 00001
Output: 4
Explanation: Last index of  1 in given string is 4.
Input: s = 0
Output: -1
Explanation: Since, 1 is not present, so output is -1.
Expected Time Complexity: O(n)
Expected Auxillary Space: O(1)

Constraints:
1 <= |s| <= 106
s = {0,1}
*/
#include<iostream>
using namespace std;

class Solution {
  public:
    int lastIndex(string s) {
        for(int i = s.size()-1; i>=0; i--)
        {
            if(s[i]=='1')
            {
                return i;
            }
        }
        return -1;
    }
};