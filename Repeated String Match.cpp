/*Given two strings a and b, find the minimum number of times a has to be repeated such that b becomes a 
substring of the repeated a. If b cannot be a substring of a no matter how many times it is repeated, return -1.

Example 1:

Input: a = "abcd", b = "cdabcdab"
Output: 3
Explanation: After repeating a three times, 
we get "abcdabcdabcd".
Example 2:

Input: a = "aa", b = "a"
Output: 1
Explanation: B is already a substring of a.
Your Task:  
You don't need to read input or print anything.
 Complete the function repeatedStringMatch() which takes strings a and b as input parameters and 
 returns the minimum number of operations to complete the task. If it is not possible then return -1.

Expected Time Complexity: O(|a| * |b|)
Expected Auxiliary Space: O(1)
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {

    public:
    void findlps(vector<int>&lps ,string s) {
      int pre = 0, suf = 1;
      while(suf<s.size()) {
          if(s[pre]==s[suf]) {
              lps[suf]=pre+1;
              pre++,suf++;
          }
          else {
              if(pre==0) {
                  lps[suf]=0;
                  suf++;
              }
              else {
                  pre=lps[pre-1];
              }
          }
      }
  }
     
     int KMP_MATCH(string haystack,string needle)
     {
         vector<int>lps(needle.size(),0);
      findlps(lps,needle);
      
      int first = 0,second = 0;
      while(second<needle.size()&&first<haystack.size()) {
          if(haystack[first]==needle[second]) {
              first++,second++;
          }
          else {
              if(second==0) {
                  first++;
              }
              else {
                  second = lps[second-1]; 
              }
          }
      }
      if(second==needle.size()) {
          return 1;
      }
      return -1;
     }
  
  
      int repeatedStringMatch(string a, string b) {
          // Your code goes here
          if(a==b)
          {
              return 1;
          }
          
          int repeat=1;
          string temp = a;
          
          while(temp.size()<b.size())
          {
              temp+=a;
              repeat++;
          }
          
          if(KMP_MATCH(temp,b)==1)
          {
              return repeat;
          }
          
          if(KMP_MATCH(temp+a,b)==1)
          {
              return repeat+1;
          }
          return -1;
      }
  };