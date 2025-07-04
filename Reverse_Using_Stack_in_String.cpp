// You are given a string s , the task is to reverse the string using stack.

// Examples:

// Input: s ="GeeksforGeeks"
// Output:  skeeGrofskee
// Input: s ="Geek"
// Output: keeG
// Constraints:
// 1 ≤ s.length() ≤ 100

// Expected Complexities
// Time Complexity: O(n)
// Auxiliary Space: O(n)

#include<iostream>
#include<stack>
using namespace std;

class Solution {
  public:
    string reverse(const string& S) {
        // code here
        stack<char>s;
        string t = S;
        for(int i = 0; i<S.size(); i++)
        {
            s.push(t[i]);
        }
        int i = 0;
        while(!s.empty())
        {
            t[i]=s.top();
            s.pop();
            i++;
        }
        return t;
    }
};