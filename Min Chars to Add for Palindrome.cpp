/*Given a string s, the task is to find the minimum characters to be added at the front to make the string palindrome.

Note: A palindrome string is a sequence of characters that reads the same forward and backward.

Examples:

Input: s = "abc"
Output: 2
Explanation: Add 'b' and 'c' at front of above string to make it palindrome : "cbabc"
Input: s = "aacecaaaa"
Output: 2
Explanation: Add 2 a's at front of above string to make it palindrome : "aaaacecaaaa"
*/

// CODE :-
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
      int minChar(string& s) {
          // Write your code here
          string rev = s;
          reverse(rev.begin(),rev.end());
          int size = s.size();
          s+='$';
          s+=rev;
          
          
          
          int pre = 0 , suf=1;
          int n = s.size();
          vector<int>lps(n,0);
          while(suf<n)
          {
              if(s[pre]==s[suf])
              {
                  lps[suf]=pre+1;
                  pre++,suf++;
              }
              
              else 
              {
                  if(pre==0)
                  {
                      suf++;
                  }
                  else 
                  {
                      pre = lps[pre-1];
                  }
              }
          }
          return size - lps[n-1];
      }
  };