/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        void parenthesis(int n , int left , int right, vector<string>&ans, string &temp)
        {
            if(left+right == 2*n)
            {
                ans.push_back(temp);
                return;
            }
    
            if(left<n)
            {
                temp.push_back('(');
                parenthesis(n,left+1,right,ans,temp);
                temp.pop_back();
            }
    
            if(right<left)
            {
                temp.push_back(')');
                parenthesis(n,left,right+1,ans,temp);
                temp.pop_back();
            }
        }
        vector<string> generateParenthesis(int n) {
            vector<string>ans;
            string temp;
            parenthesis(n,0,0,ans,temp);
            return ans;
        }
    };