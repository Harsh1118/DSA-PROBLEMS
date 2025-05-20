/*
You are given a string s, and your task is to reverse the string.

Examples:

Input: s = "Geeks"
Output: "skeeG"
Input: s = "for"
Output: "rof"
Input: s = "a"
Output: "a"
Constraints:
1 <= s.size() <= 106
s contains only alphabetic characters (both uppercase and lowercase).

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(1)
*/
#include<iostream>
#include<string>
using namespace std;

class Solution {
  public:
    string reverseString(string& s) {
        // code here
        int start = 0 , end = s.size()-1;
        while(start<=end)
        {
            swap(s[start],s[end]);
            start++,end--;
        }
        return s;
    }
};

