/*Given two strings text and pattern, find the first index where pattern exactly matches with any substring of text. 

Return -1 if pattern doesn't exist as a substring in text.

Example 1:

Input:
text = gffgfg
pattern = gfg
Output: 3
Explanation:  Considering 0-based indexing, substring of text from 3rd to last index is gfg.
Example 2:

Input:
text = gffggg
pattern = gfg
Output: -1
Explanation: pattern "gfg" does not exist in the text.
Your Task:
You don't need to read input or print anything. Your task is to complete the function findMatching() which takes the strings text and pattern as the input parameters and returns the first index of matching.

Expected Time Complexity: O(|text| * |pattern|)
Expected Auxiliary Space: O(1)
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
    
    void lpsfind(vector<int>&lps , string s)
    {
        int pre = 0, suf = 1;
        lps[0]=0;
        while(suf<s.size())
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
    }
      int findMatching(string text, string pat) {
          // Code here
          vector<int>lps(pat.size(),0);
          lpsfind(lps,pat);
          
          int first = 0 , second = 0;
          
          while(first<text.size() && second<pat.size())
          {
              if(text[first]== pat[second])
              {
                  first++,second++;
              }
              
              else 
              {
                  if(second==0)
                  {
                      first++;
                  }
                  else 
                  {
                      second = lps[second-1];
                  }
              }
          }
          if(second==pat.size())
          {
              return first-second;
          }
          
          return -1;
      }
  };