/*
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such 
that every character in t (including duplicates) is included in the window. If there is no such substring, 
return the empty string "".

The testcases will be generated such that the answer is unique.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 

Constraints:

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.
 

Follow up: Could you find an algorithm that runs in O(m + n) time?
*/
#include<iostream>
#include<unordered_map>
#include<climits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        //  Char , count 
        unordered_map<char,int>m;  // Characters need in the string s
        
        int total = t.size();

        for(int i = 0; i<t.size(); i++)
        {
            m[t[i]]++;
        }

        int start = 0 , end = 0 , ans = INT_MAX , index = -1;

        while(end<s.size())
        {
            m[s[end]]--;   // decrease the count of char 
            if(m[s[end]]>=0)   // if count i not -ve then 
                               // decrease the total
            {
                total--;
            }
               // can we decrease the size of window 
            while(!total && start<=end)
            {
                //   update the length of substring 
                if(ans>end-start+1)
                {
                    ans = end-start+1;
                    index = start;
                }
                m[s[start]]++;  // incease the count of char 
                if(m[s[start]]>0)  // if count is +ve then
                {                  // then increase the total 
                    total++;
                }
                start++;  // move the start , decrease the  size 
            }
              
              // Increase the window size 
            end++;
        }

        if(index==-1)
        {
            return "";
        }

        string S = "";

        for(int i = index; i<index+ans; i++)
        {
            S+=s[i];
        }
        return S;
    }
};