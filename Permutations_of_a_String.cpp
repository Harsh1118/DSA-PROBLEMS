/*
Given a string s, which may contain duplicate characters, your task is to generate and return an array of 
all unique permutations of the string. You can return your answer in any order.

Examples:

Input: s = "ABC"
Output: ["ABC", "ACB", "BAC", "BCA", "CAB", "CBA"]
Explanation: Given string ABC has 6 unique permutations.
Input: s = "ABSG"
Output: ["ABGS", "ABSG", "AGBS", "AGSB", "ASBG", "ASGB", "BAGS", "BASG", "BGAS", "BGSA", "BSAG", "BSGA", 
"GABS", "GASB", "GBAS", "GBSA", "GSAB", "GSBA", "SABG", "SAGB", "SBAG", "SBGA", "SGAB", "SGBA"]
Explanation: Given string ABSG has 24 unique permutations.
Input: s = "AAA"
Output: ["AAA"]
Explanation: No other unique permutations can be formed as all the characters are same.
Constraints:
1 <= s.size() <= 9
s contains only Uppercase english alphabets
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
    public:
    void permutation(string &s , vector<string>&ans,int index)
    {
        if(index==s.size())
        {
            ans.push_back(s);
            return;
        }
        vector<bool>count(26,0);
        for(int i = index; i<s.size(); i++)
        {
            if(count[s[i]-65]==0)
            {
            swap(s[index],s[i]);
            permutation(s,ans,index+1);
            swap(s[index],s[i]);
            count[s[i]-65]=1;
            }
        }
    }
      vector<string> findPermutation(string &s) {
          // Code here there
          vector<string>ans;
          permutation(s,ans,0);
          return ans;
      }
  };