/*
A celebrity is a person who is known to all but does not know anyone at a party. 
A party is being organized by some people. A square matrix mat[][] (n*n) is used to represent 
people at the party such that if an element of row i and column j is set to 1 it means ith person knows 
jth person. You need to return the index of the celebrity in the party, if the celebrity does not exist, return -1.

Note: Follow 0-based indexing.

Examples:

Input: mat[][] = [[1, 1, 0], [0, 1, 0], [0, 1, 1]]
Output: 1
Explanation: 0th and 2nd person both know 1st person. Therefore, 1 is the celebrity person. 
Input: mat[][] = [[1, 1], [1, 1]]
Output: -1
Explanation: Since both the people at the party know each other. Hence none of them is a celebrity person.
Input: mat[][] = [[1]]
Output: 0
Constraints:
1 <= mat.size()<= 1000
0 <= mat[i][j]<= 1
mat[i][i] == 1


*/
#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
      int celebrity(vector<vector<int> >& mat) {
          // code here
          int n = mat.size();
          stack<int>st;
          
          for(int i = n-1; i>=0; i--)
          {
              st.push(i);
          }
          int first , second;
          while(st.size()>1)
          {
              first = st.top();
              st.pop();
              second = st.top();
              st.pop();
              if(mat[first][second]&&!mat[second][first])
              {
                  st.push(second);
              }
              else if(!mat[first][second]&&mat[second][first])
              {
                  st.push(first);
              }
          }
          
          if(st.empty())
          {
              return -1;
          }
          
          int num = st.top();
          st.pop();
          int row=0,col=0;
          for(int i = 0; i<n; i++)
          {
              row+=mat[num][i];
              col+=mat[i][num];
          }
          if(row==1 && col == n)
          {
              return num;
          }
          
          return row==0&&col==n-1?num:-1;
          
      }
  };